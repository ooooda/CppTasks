#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void triangle(int a, int b, int c) {
    double perimeter = a + b + c;
    double half_perimeter = perimeter / 2;
    double square = sqrt(half_perimeter * (half_perimeter - a) *
                  (half_perimeter - b) * (half_perimeter - c));
    printf("The perimeter is %0.f", perimeter);
    printf("\n");
    printf("The square is %0.f", square);
}

void circle(int a) {
    double perimeter = 2 * M_PI * a;
    double square = M_PI * a * a;
    printf("The perimeter is %0.f", perimeter);
    printf("\n");
    printf("The square is %0.f", square);
}

void rectangle(int a, int b) {
    double perimeter = 2 * (a + b);
    double square = a * b;
    printf("The perimeter is %0.f", perimeter);
    printf("\n");
    printf("The square is %0.f", square);
}

int operations_for_figure(int index) {
    int a, b, c;
    if (index == 0) {
        printf("Print 3 values.\n");
        scanf("%d %d %d", &a, &b, &c);
        if (a * b * c > 0 && a + b > c && a + c > b && c + b > a) {
            triangle(a, b, c);
            return 0;
        }
    }
    if (index == 1) {
        printf("Print 1 value.\n"); // a - radius
        scanf("%d", &a);
        if (a > 0) {
            circle(a);
            return 0;
        }
    }
    if (index == 2) {
        printf("Print 2 values.\n");
        scanf("%d %d", &a, &b);
        if (a * b > 0 && a > 0) {
            rectangle(a, b);
            return 0;
        }
    }
    printf("This figure does not exist.\n");
    operations_for_figure(index);
}

int main() {
    bool status = true;
    char figure[10] = "";
    const int NUM_FIGURES = 3;
    const char figure_choose[NUM_FIGURES][10] = {"triangle", "circle", "rectangle"};
    while (status) {
        printf("Choose the figure: triangle, circle, rectangle\n");
        scanf("%s", figure);
        for (int i = 0; i < NUM_FIGURES; ++i) {
            if (strcmp(figure_choose[i], figure) == 0) {
                status = false;
                operations_for_figure(i);
            }
        }
        if (status) {
            printf("Your input was incorrect.\nBe sure that your input was the same as it was written in a line above.\n");
        }
    }
}