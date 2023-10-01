#include <stdio.h>
#include <math.h>

double tabulateTable1(double x) {
    if (x < 3) {
        return cos(pow(x, 0.3));
    } else if (x >= 3 && x < 4) {
        return sqrt(pow(x, 3) + log10(x));
    } else {
        return 1.0 / tan(pow(x, 2));
    }
}

double tabulateTable2(double x, double d) {
    double result = 0;
    double term = 0;
    int n = 1;

    while (1) {
        term = (2.0 / ((2 * n + 1) * (x + 1)));
        
        if (fabs(term) < d) {
            break;
        }
        
        if (n % 2 == 0) {
            result -= term * pow(x - 1, 2 * n + 1);
        } else {
            result += term * pow(x - 1, 2 * n + 1);
        }
        
        n++;
    }
    
    return result;
}

int main() {
    double initial = 2.0;
    double final = 5.0;
    double step = 0.2;

    double a2 = 1.0;
    double b2 = 1.2;
    double h2 = 0.02;
    double d2 = 1e-6;

    printf("Table 1:\n");
    printf("x\tf(x)\n");
    
    for (double x = initial; x <= final; x += step) {
        double result = tabulateTable1(x);
        printf("%.2lf\t%.6lf\n", x, result);
    }

    printf("\nTable 2:\n");
    printf("x\tf(x)\n");
    
    for (double x = a2; x <= b2; x += h2) {
        double result = tabulateTable2(x, d2);
        printf("%.2lf\t%.6lf\n", x, result);
    }

    return 0;
}
