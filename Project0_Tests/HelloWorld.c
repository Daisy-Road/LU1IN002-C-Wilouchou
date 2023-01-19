#include <stdio.h>


int main() 
{
    int test = 5;
    test++;
    int out = printf("Hello World %d!\n", test);
    printf("Value of out is %d\n", out);
    printf("Testing NeoVim capabilities with git and writing code !\n");
    test--;
    return 0;
}