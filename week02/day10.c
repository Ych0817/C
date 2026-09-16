#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "day10_lib.h"

#if 0
typedef struct {
    char* name;
    char* sign;
    int(*func)(int, int);
}op_t;

void print_arr(op_t* p, int menu_size) {
    for (int i = 1; i < menu_size; ++i) {
        int idx = (i + 1) % menu_size;
        printf("%d. %s\n", i, p[i].name);
    }
    printf("0. 종료\n");
    printf("\n");
}

int get_menu(op_t* menu, int n) {
    int id = 0;
    print_arr(menu, n);
    (void)scanf("%d", &id);
    return id;
}

int main(void) {
    int a, b, id = 0;
    const int menu_size = 6;
    op_t menu[6] = {
        {"종료"},
        {"덧셈","+",sum_10},
        {"뺄셈","-",sub_10},
        {"곱셈","*",mul_10},
        {"나눗셈(몫)","/",div_10},
        {"나눗셈(나머지)","%",mod_10},
    };
    op_t* op_ptr = NULL;

    while (id = get_menu(menu, SIZE(menu))) {
        op_ptr = &menu[id];
        printf("두 숫자 입력 : ");
        (void)scanf("%d %d", &a, &b);
        printf("결과는 %d %s %d = %d입니다.\n", a, op_ptr->sign, b, op_ptr->func(a, b));
    }
    printf("프로그램을 종료합니다.\n");
    return 0;
}
#endif

#if 0
#define ARRAY_SIZE(a) ((int)(sizeof(a) / sizeof((a)[0])))

typedef struct {
    const char* name;
    const char* sign;
    int (*func)(int, int);
    int  deny_zero;              /* b == 0 을 막아야 하는 연산인지 */
} op_t;

static int sum_10(int a, int b) { return a + b; }
static int sub_10(int a, int b) { return a - b; }
static int mul_10(int a, int b) { return a * b; }
static int div_10(int a, int b) { return a / b; }
static int mod_10(int a, int b) { return a % b; }

static const op_t menu[] = {
    { "종료",           "종료", NULL,   0 },
    { "덧셈",           "+",    sum_10, 0 },
    { "뺄셈",           "-",    sub_10, 0 },
    { "곱셈",           "*",    mul_10, 0 },
    { "나눗셈(몫)",     "/",    div_10, 1 },
    { "나눗셈(나머지)", "%",    mod_10, 1 },
};

static void clear_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static int read_int(int* out) {
    if (scanf("%d", out) != 1) {
        clear_stdin();
        return 0;
    }
    return 1;
}

static void print_menu(void) {
    for (int i = 1; i <= ARRAY_SIZE(menu); ++i) {
        int idx = i % ARRAY_SIZE(menu);
        printf("%d. %s  ", idx, menu[idx].name);
    }
    printf("\n> ");
}

int main(void) {
    for (;;) {
        int id, a, b;

        print_menu();

        if (!read_int(&id)) {
            printf("숫자를 입력해 주세요.\n");
            continue;
        }
        if (id < 0 || id >= ARRAY_SIZE(menu)) {
            printf("0 ~ %d 사이로 입력해 주세요.\n", ARRAY_SIZE(menu) - 1);
            continue;
        }
        if (id == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        const op_t* op = &menu[id];

        if (!read_int(&a) || !read_int(&b)) {
            printf("숫자 두 개를 입력해 주세요.\n");
            continue;
        }
        if (op->deny_zero && b == 0) {
            printf("0으로 나눌 수 없습니다.\n");
            continue;
        }

        printf("결과는 %d %s %d = %d입니다.\n", a, op->sign, b, op->func(a, b));
    }
    return 0;
}
#endif

#if 0
int main(void)
{
    /* 함수 포인터 배열: 메뉴 1~5 -> 인덱스 0~4 */
    int (*func[])(int x, int y) = { sum_10, sub_10, mul_10, div_10, mod_10 };
    const char* op[] = { "+", "-", "*", "/", "%" };

    int menu, x, y;

    while (1) {
        print_menu();
        printf("메뉴 선택 : ");

        if (scanf("%d", &menu) != 1) {   /* 숫자가 아닌 입력 방어 */
            printf("잘못된 입력입니다.\n\n");
            clear_stdin();
            continue;
        }

        if (menu == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        if (menu < 1 || menu > 5) {
            printf("메뉴 번호는 0~5 사이로 입력하세요.\n\n");
            continue;
        }

        printf("정수 2개 입력 : ");
        if (scanf("%d %d", &x, &y) != 2) {
            printf("잘못된 입력입니다.\n\n");
            clear_stdin();
            continue;
        }

        /* 나눗셈, 나머지 연산은 0으로 나눌 수 없음 */
        if ((menu == 4 || menu == 5) && y == 0) {
            printf("0으로는 나눌 수 없습니다.\n\n");
            continue;
        }

        /* 핵심: 함수 포인터 배열로 해당 연산 호출 */
        printf("결과 : %d %s %d = %d\n\n",
            x, op[menu - 1], y, func[menu - 1](x, y));
    }

    return 0;
}

#endif