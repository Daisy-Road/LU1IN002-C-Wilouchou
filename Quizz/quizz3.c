# include <stdio.h>

void f(int t[], int len) {
  int i;
  for(i=1; i<len; i++) {
    t[i-1] = t[i];
  }
}

void f2(int a,int b,int c,int *p_a,int *p_b,int *p_c){
  a=b;
  p_a=p_b;
  b=(*p_a)*c;
  p_c=&b;
  *p_b=*p_c+a;
}

int main () {
  int tab[5] = { 9, 6, 8, 5, 4 };
  f(tab+1, 4);
  int i;
  int a=5; int b=3; int c=2;
  f2(a,b,c,&a,&b,&c);
  printf("%d %d %d\n",a,b,c);
  for(i=0; i<5; i++) {
    printf("%d ", tab[i]);
  }
  return 0;
}
