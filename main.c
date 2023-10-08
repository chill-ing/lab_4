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

double tabulateTable2(double start, double number, double end, double step) {
    double sum = 0.0;
    double n;

    for (n = start; n <= end; n += step) {
        double result = pow(number - 1, 2 * n + 1) / ((2 * n + 1) * pow(number + 1, 2 * n + 1));
        printf("%.2lf\t%.6lf\n", n, result);
        sum += result;
    }

    return sum;
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

    double start, end, step_2, x;

    printf("Enter initial point of start: ");
    scanf("%lf", &start); // 1.0

    printf("Enter final point of end: ");
    scanf("%lf", &end); // 1.2

    printf("Enter step of calculation: ");
    scanf("%lf", &step_2); // 0.02

    printf("Enter x for calculation: ");
    scanf("%lf", &x);

    printf("\nTable 2:\n");
    printf("x\tf(x)\n");
    
    double sum = tabulateTable2(start, x, end, step_2);

    return 0;
}
