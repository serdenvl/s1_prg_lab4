#include <stdio.h>
#include <stdlib.h>

// Вычисление значение функции в точке x с погрешностью eps 
double fun(double x, double eps)
{
    double sum = 0;
    double a = 1 / (x * x);
    x = -x * x;

    for (double i = 2; (a > 0 ? a : -a) > eps; i += 2)
    {
        sum += a;
        a *= x / (i * (i + 1));
    }

    return sum;
}

#define description "Lab4\n\
Вычисляет значение некой функции в точках промежутка [A,B] с шагом r и погрешностью eps\
\n"

// Табулирует функцию в заданном диапозоне
void tabulate_fun()
{
    printf(description);

    double A, B, r, eps;
    double *vars[] = {&A, &B, &r, &eps};
    char *names[] = {"A", "B", "r", "eps"};

    // Ввод данных
    while (1)
    {
        for (int i = 0; i < (sizeof(vars) / sizeof(double *)); ++i)
        {
            printf("%s: ", names[i]);
            scanf("%lf", vars[i]);
        }

        if (A > B || r <= 0 || eps <= 0)
            printf("\nНекорректные данные\n\n\n");
        else
            break;
    }

    // Табулирование
    printf("|%9s|%9s|\n", "X", "F(x)");
    for (double i = A; i <= B; i += r)
    {
        printf("|%+8lf|%+8lf|\n", i, fun(i, eps));
    }
}

int main()
{
    tabulate_fun();
    getchar();
}