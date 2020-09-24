#include <stdio.h>
#include <stdbool.h>

struct date {
    int d, m, y;
} typedef date;

bool check(int d, int m, int y, char symbol1, char symbol2) {
    int legal_num_d;
    if (y > 0) {
        if (0 < m && m <= 12) {
            if (y <= 0) {
                return true;
            }
            if (m == 2) {
                if (y % 4 == 0) {
                    legal_num_d = 29;
                } else {
                    legal_num_d = 28;
                }
            } else if ((m <= 7 && m % 2 != 0) || (m >= 8 && m % 2 == 0)) {
                legal_num_d = 31;
            } else {
                legal_num_d = 30;
            }
            if (d > legal_num_d || d <= 0) {
                return true;
            }
        }
    }
    if (symbol1 != symbol2 || symbol1 != ':') {
        return true;
    }
    return false;
}

int do_actions(int x, int y) {
    if (x > y) {
        return 1;
    }
    if (x < y) {
        return -1;
    }
    return 0;
}

void compare(date d1, date d2) {
    int index = do_actions(d1.y, d2.y);
    if (index == 0) {
        index = do_actions(d1.m, d2.m);
    }
    if (index == 0) {
        index = do_actions(d1.d, d2.d);
    }

    if (index == 1) {
        printf("First is bigger");
    } else if (index == -1) {
        printf("Second is bigger");
    } else {
        printf("the same");
    }
}

date get_date() {
    bool status = true;
    char symbol1, symbol2;
    date d;
    while (status) {
        printf("give дд:мм:гг");
        printf("\n");
        scanf("%d%c%d%c%d", &d.d, &symbol1, &d.m, &symbol2, &d.y);
        status = check(d.d, d.m, d.y, symbol1, symbol2);
        if (status) {
            printf("Your input was incorrect. Please, try again.\n");
        }
    }
    return d;
}

int main() {
    date d1, d2;
    d1 = get_date();
    d2 = get_date();
    compare(d1, d2);
}