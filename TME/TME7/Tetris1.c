#include <SDL2/SDL.h>
#include <cini.h>
#include <cini_console.h>
#include <cini_graphic.h>

#define TAILLE_CASE 20
#define HAUTEUR 22
#define LARGEUR 10
#define VIDE                                                                   \
    8 /* n'importe quelle valeur qui n'est pas un indice du tableau des        \
         couleurs */

/*-------------   INSERER ICI LES DEFINITIONS DE TYPES   --------------*/

struct une_case {
    int colonne;
    int ligne;
};

struct piece {
    int pos_ligne, pos_colonne;
    struct une_case la_piece[4];
    int type;
};

/*-------------------   INSERER ICI LES FONCTIONS   -------------------*/
/* Affiche une piece */
void afficher_piece(struct piece tetromino, char* couleur) {
    int i;
    int ligne_deb, colonne_deb;

    for (i = 0; i < 4; i++) {
        ligne_deb =
            (tetromino.pos_ligne + tetromino.la_piece[i].ligne) * TAILLE_CASE;
        colonne_deb = (tetromino.pos_colonne + tetromino.la_piece[i].colonne) *
                      TAILLE_CASE;
        CINI_fill_rect(colonne_deb, ligne_deb, TAILLE_CASE, TAILLE_CASE,
                       couleur);
    }
}

/* Initialisation d'une piece, elle se trouve initialement en haut et au milieu
 * du plateau */
void initialiser(struct piece* p_tetromino, struct une_case tab[4],
                 int indice) {
    int i;
    p_tetromino->pos_colonne = LARGEUR / 2;
    p_tetromino->pos_ligne = 0;
    for (i = 0; i < 4; i++) {
        p_tetromino->la_piece[i] = tab[i];
    }

    p_tetromino->type = indice;
}

/* Afficher toutes les pieces, permet de tester si les pieces sont bien
 * declarees */
void afficher_toutes_pieces(char* color[], struct une_case tab_pieces[7][4]) {
    int i;
    int lig = 0;
    struct piece tetromino;

    for (i = 0; i < 7; i++) {
        initialiser(&tetromino, tab_pieces[i], i);
        tetromino.pos_ligne = lig;
        lig = lig + 3;
        afficher_piece(tetromino, color[tetromino.type]);
    }
}

void afficher_plateau(int plateau[HAUTEUR][LARGEUR], char* color[]) {
    CINI_fill_window("white");
    for (int y = 0; y < HAUTEUR; y++) {
        for (int x = 0; x < LARGEUR; x++) {
            char* extract =
                (plateau[y][x] == VIDE) ? "black" : color[plateau[y][x]];
            CINI_fill_rect(x * TAILLE_CASE, y * TAILLE_CASE, TAILLE_CASE,
                           TAILLE_CASE, extract);
        }
    }
}

int descendre(struct piece* tetromino, int plateau[HAUTEUR][LARGEUR]) {
    for (int i = 0; i < 4; i++) {
        struct une_case eval = tetromino->la_piece[i];
        int x = eval.colonne + LARGEUR / 2;
        int y = eval.ligne;
        if (y + 1 >= HAUTEUR || plateau[y + 1][x] != VIDE) {
            for (int j = 0; j < 4; j++) {
                eval = tetromino->la_piece[j];
                x = eval.colonne + LARGEUR / 2;
                y = eval.ligne;
                plateau[y][x] = tetromino->type;
            }
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        tetromino->la_piece[i].ligne += 1;
    }
    return 1;
}

void hard_drop(struct piece* tetromino, int plateau[HAUTEUR][LARGEUR]) {
    while (descendre(tetromino, plateau))
        ;
}

void decaler_gauche(struct piece* tetromino, int plateau[HAUTEUR][LARGEUR]) {
    for (int i = 0; i < 4; i++) {
        struct une_case eval = tetromino->la_piece[i];
        int x = LARGEUR / 2 + eval.colonne;
        int y = eval.ligne;
        if (x - 1 < 0 || plateau[y][x - 1] != VIDE) return;
    }
    for (int i = 0; i < 4; i++) {
        tetromino->la_piece[i].colonne -= 1;
    }
}

void decaler_droite(struct piece* tetromino, int plateau[HAUTEUR][LARGEUR]) {
    for (int i = 0; i < 4; i++) {
        struct une_case eval = tetromino->la_piece[i];
        int x = LARGEUR / 2 + eval.colonne;
        int y = eval.ligne;
        if (x + 1 >= LARGEUR || plateau[y][x + 1] != VIDE) return;
    }
    for (int i = 0; i < 4; i++) {
        tetromino->la_piece[i].colonne += 1;
    }
}

void rotation_droite(struct piece* tetromino, int plateau[HAUTEUR][LARGEUR]) {
    int O_x = tetromino->la_piece[0].colonne;
    int O_y = tetromino->la_piece[0].ligne;
    for (int i = 0; i < 4; i++) {
        struct une_case eval = tetromino->la_piece[i];
        int x = LARGEUR / 2 - eval.ligne + O_y + O_x;
        int y = eval.colonne - O_x + O_y;
        if (y >= HAUTEUR || x < 0 || x >= LARGEUR || plateau[y][x] != VIDE)
            return;
    }
    for (int i = 1; i < 4; i++) {
        int x = tetromino->la_piece[i].colonne - O_x;
        int y = tetromino->la_piece[i].ligne - O_y;
        tetromino->la_piece[i].colonne = -y + O_x;
        tetromino->la_piece[i].ligne = x + O_y;
    }
}

void rotation_gauche(struct piece* tetromino, int plateau[HAUTEUR][LARGEUR]) {
    int O_x = tetromino->la_piece[0].colonne;
    int O_y = tetromino->la_piece[0].ligne;
    for (int i = 0; i < 4; i++) {
        struct une_case eval = tetromino->la_piece[i];
        int x = LARGEUR / 2 + eval.ligne - O_y + O_x;
        int y = -eval.colonne + O_x + O_y;
        if (y >= HAUTEUR || x < 0 || x >= LARGEUR || plateau[y][x] != VIDE)
            return;
    }
    for (int i = 1; i < 4; i++) {
        int x = tetromino->la_piece[i].colonne - O_x;
        int y = tetromino->la_piece[i].ligne - O_y;
        tetromino->la_piece[i].colonne = y + O_x;
        tetromino->la_piece[i].ligne = -x + O_y;
    }
}

int perdu(int plateau[HAUTEUR][LARGEUR]) {
    for (int x = 0; x < LARGEUR; x++) {
        if (plateau[0][x] != VIDE) return 1;
    }
    return 0;
}

void supprimer_lignes(int plateau[HAUTEUR][LARGEUR]) {
    int rm_size = 0;
    int broke = 0;
    int y;
    for (y = HAUTEUR - 1; y >= 0; y--) {
        for (int x = 0; x < LARGEUR; x++) {
            if (plateau[y][x] == VIDE) {
                broke = 1;
                /*CINI_print_string("Broke at (");
                CINI_print_int(x);
                CINI_print_string(",");
                CINI_print_int(y);
                CINI_print_string(") at ");
                CINI_print_int(rm_size);
                CINI_print_string("\n");*/
                break;
            }
        }
        if (broke && rm_size) break;
        if (!broke) rm_size++;
    }
    if (!rm_size) return;
    for (y = y + rm_size; y >= 0; y--) {
        for (int x = 0; x < LARGEUR; x++) {
            plateau[y][x] = (y - rm_size <= 0) ? VIDE : plateau[y - rm_size][x];
        }
    }
}
/*---------------------------------------------------------------------*/

int main() {

    /*---------------------   les declarations   ---------------------*/

    int indice; /* l'indice (type) de la piece jouee */
    int touche; /* identifie la frappe du joueur */

    char* color[] = {"light salmon", "fuchsia", "lime green", "white",
                     "yellow",       "cyan",    "grey"};

    struct une_case tab_pieces[7][4];

    /*--------------------  les initialisations  ---------------------*/

    srand(time(NULL));
    typedef struct une_case Case;
    typedef struct piece Tetromino;

    // O
    Case o_0 = {0, 0};
    tab_pieces[0][0] = o_0;
    Case o_1 = {1, 0};
    tab_pieces[0][1] = o_1;
    Case o_2 = {0, 1};
    tab_pieces[0][2] = o_2;
    Case o_3 = {1, 1};
    tab_pieces[0][3] = o_3;

    // I
    Case I_0 = {0, 0};
    tab_pieces[1][0] = I_0;
    Case I_1 = {0, 1};
    tab_pieces[1][1] = I_1;
    Case I_2 = {0, 2};
    tab_pieces[1][2] = I_2;
    Case I_3 = {0, 3};
    tab_pieces[1][3] = I_3;

    // L
    Case L_0 = {0, 0};
    tab_pieces[2][0] = L_0;
    Case L_1 = {1, 0};
    tab_pieces[2][1] = L_1;
    Case L_2 = {2, 0};
    tab_pieces[2][2] = L_2;
    Case L_3 = {2, 1};
    tab_pieces[2][3] = L_3;

    // J
    Case J_0 = {0, 0};
    tab_pieces[3][0] = J_0;
    Case J_1 = {0, 1};
    tab_pieces[3][1] = J_1;
    Case J_2 = {0, 2};
    tab_pieces[3][2] = J_2;
    Case J_3 = {-1, 2};
    tab_pieces[3][3] = J_3;

    // Z
    Case Z_0 = {0, 0};
    tab_pieces[4][0] = Z_0;
    Case Z_1 = {-1, 0};
    tab_pieces[4][1] = Z_1;
    Case Z_2 = {0, 1};
    tab_pieces[4][2] = Z_2;
    Case Z_3 = {1, 1};
    tab_pieces[4][3] = Z_3;

    // S
    Case S_0 = {0, 0};
    tab_pieces[5][0] = S_0;
    Case S_1 = {1, 0};
    tab_pieces[5][1] = S_1;
    Case S_2 = {0, 1};
    tab_pieces[5][2] = S_2;
    Case S_3 = {-1, 1};
    tab_pieces[5][3] = S_3;

    // T
    Case T_0 = {0, 0};
    tab_pieces[6][0] = T_0;
    Case T_1 = {-1, 0};
    tab_pieces[6][1] = T_1;
    Case T_2 = {1, 0};
    tab_pieces[6][2] = T_2;
    Case T_3 = {0, 1};
    tab_pieces[6][3] = T_3;

    int plateau[HAUTEUR][LARGEUR];
    for (int i = 0; i < HAUTEUR; i++) {
        for (int j = 0; j < LARGEUR; j++) {
            plateau[i][j] = VIDE;
        }
    }
    /*----------------------  ouverture de la fenêtre graphique -------*/

    CINI_open_window(LARGEUR * TAILLE_CASE, HAUTEUR * TAILLE_CASE, "black");

    /* Affichage de test des pieces */
    /* Instruction a mettre en commentaire pour la suite */
    // afficher_toutes_pieces(color, tab_pieces);

    /*----------------------  la boucle de jeu  ----------------------*/

    do {
        afficher_plateau(plateau, color);
        indice = rand() % 7;
        Tetromino new_piece;
        initialiser(&new_piece, tab_pieces[indice], indice);
        afficher_piece(new_piece, color[new_piece.type]);

        do {
            touche = CINI_loop_until_keyup();
            afficher_piece(new_piece, "black");
            descendre(&new_piece, plateau);
            switch (touche) {
            case SDLK_LEFT:
                decaler_gauche(&new_piece, plateau);
                break;
            case SDLK_RIGHT:
                decaler_droite(&new_piece, plateau);
                break;
            case SDLK_g:
                rotation_gauche(&new_piece, plateau);
                break;
            case SDLK_d:
                rotation_droite(&new_piece, plateau);
                break;
            case SDLK_j:
                hard_drop(&new_piece, plateau);
                break;
            default:
                break;
            }
            afficher_piece(new_piece, color[new_piece.type]);
        } while ((touche != SDLK_DOWN) && (touche != SDLK_ESCAPE));

        /* on supprime les lignes completes si elles existent */
        supprimer_lignes(plateau);

    } while (touche != SDLK_ESCAPE && !perdu(plateau));

    return 0;
}
