#include <stdio.h>

int multiplyNumbers(int num_1, int num_2)
{
    int num_array[5] = {23, 5, 39, 7, 17};
    int num_from_array;
    if (num_1 >= 0 && num_1 <= 4) {
        num_from_array = num_array[num_1];
    } else if (num_2 >= 0 && num_2 <= 4) {
        num_from_array = num_array[num_2];
    }
    return num_1 * num_2 * num_from_array; // 32 * 39 = 1248
}

double divideNumber(int num_1, int num_2, int num_3)
{
    int multi_dimensional[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    return multi_dimensional[num_1][num_2] / num_3;
}

int main()
{
    int num_1 = 1, num_2 = 2, num_3 = 3, num_4 = 4, num_5 = 5;
    int x, y;
    int result = num_1 + num_3 * num_4 - num_2 + num_5; // (3 * 4) + 1 - 2 + 5 = 16
    int multipliedNumber = multiplyNumbers(result, num_2); // 16 * 2 = 32
    printf("Enter values for x and y\n");
    scanf("%d %d", &x, &y);
    double dividedNumber = divideNumber(x, y, multipliedNumber);
    printf("%d\n", multipliedNumber);
    printf("%lf\n", dividedNumber);
    return 0;
}
