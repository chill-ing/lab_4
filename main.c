#include <stdio.h>
#include <math.h>

void sortMatrixRows(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            int key = matrix[i][j];
            int k = j - 1;

            while (k >= 0 && matrix[i][k] < key) {
                matrix[i][k + 1] = matrix[i][k];
                k = k - 1;
            }

            matrix[i][k + 1] = key;
        }
    }
}

void calculateSum(int rows, int cols, int matrix[rows][cols], int sum[cols-1]) {
    for (int j = 0; j < cols-1; j++) {
        sum[j] = 0;
        for (int i = j + 1; i < rows; i++) {
            sum[j] += matrix[i][j];
        }
    }
}

double calculateGeometricMean(int cols, int sum[cols-1]) {
    double product = 1.0;
    for (int j = 0; j < cols-1; j++) {
        product *= sum[j];
    }
    return pow(product, 1.0 / (cols-1));
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns for the matrix:\n ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    printf("\n");

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    sortMatrixRows(rows, cols, matrix);

    int sum[cols-1];
    calculateSum(rows, cols, matrix, sum);

    printf("\n");

    printf("Sorted Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Sum values (excluding last column):\n");
    for (int j = 0; j < cols-1; j++) {
        printf("Sum(col%d) = %d\n", j, sum[j]);
    }

    printf("\n");

    double Gm = calculateGeometricMean(cols, sum);
    printf("Geometric Mean (excluding last column) = %lf\n\n", Gm);

    return 0;
}
