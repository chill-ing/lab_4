#include <stdio.h>
#include <math.h>

double tabulateTable1(double number) {
    if (number < 3) {
        return cos(pow(number, 0.3));
    } else if (number >= 3 && number < 4) {
        return sqrt(pow(number, 3) + log10(number));
    } else {
        return 1.0 / tan(pow(number, 2));
    }
}

double tabulateTable2(double x, double a, double b, double h, double error) {
    double result = 0;
    double term;
    int n = 1;

    do {
        term = (pow(x - 1, 2 * n + 1) / ((2 * n + 1) * pow(x + 1, 2 * n + 1)));
        result += term;
        n++;
    } while (fabs(term) >= error);

    return result;
}

int main() {
    double initial, final, step_1;

    printf("Enter initial point of start: ");
    scanf("%lf", &initial); // 2.0

    printf("Enter final point of end: ");
    scanf("%lf", &final); // 5.0

    printf("Enter step of calculation: ");
    scanf("%lf", &step_1); // 0.2

    printf("Table 1:\n");
    printf("x\tf(x)\n");
    
    for (double x = initial; x <= final; x += step_1) {
        double result = tabulateTable1(x);
        printf("%.2lf\t%.6lf\n", x, result);
    }

    double start, end, step_2, error, x;

    printf("Enter initial point of start: ");
    scanf("%lf", &start); // 1.0

    printf("Enter final point of end: ");
    scanf("%lf", &end); // 1.2

    printf("Enter step of calculation: ");
    scanf("%lf", &step_2); // 0.02

    printf("Enter error: ");
    scanf("%lf", &error); // 10^-6

    printf("\nTable 2:\n");
    printf("x\tf(x)\n");
    
    for (x = start; x <= end; x += step_2) {
        double result = tabulateTable2(x, start, end, step_2, error);
        printf("%.2lf\t%.6lf\n", x, result);
    }

    return 0;
}
