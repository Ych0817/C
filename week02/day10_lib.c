#include "day10_lib.h"

void print_menu(void)
{
    printf("===== ¿¬»ê ÇÁ·Î±×·¥ =====\n");
    printf(" 1. µ¡¼À\n");
    printf(" 2. »¬¼À\n");
    printf(" 3. °ö¼À\n");
    printf(" 4. ³ª´°¼À (¸ò)\n");
    printf(" 5. ³ª´°¼À (³ª¸ÓÁö)\n");
    printf(" 0. Á¾·á\n");
    printf("=========================\n");
}

void clear_stdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int sum_10(int x, int y) { return x + y; }
int sub_10(int x, int y) { return x - y; }
int mul_10(int x, int y) { return x * y; }
int div_10(int x, int y) { return x / y; }
int mod_10(int x, int y) { return x % y; }