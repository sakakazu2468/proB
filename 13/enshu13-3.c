#include <stdio.h>

void orderThreeNumbers(int* number1, int* number2, int* number3) {
    int tmp1, tmp2, tmp3;
    if (*number1 > *number2) {
        if (*number1 > *number3) {
            if (*number2 > *number3) {
                tmp1 = *number1;
                tmp2 = *number2;
                tmp3 = *number3;
            } else {
                tmp1 = *number1;
                tmp2 = *number3;
                tmp3 = *number2;   
            }
        } else {
            tmp1 = *number3;
            tmp2 = *number1;
            tmp3 = *number2;
        }
    } else {
        if (*number2 > *number3) {
            if (*number1 > *number3) {
                tmp1 = *number2;
                tmp2 = *number1;
                tmp3 = *number3;
            } else {
                tmp1 = *number2;
                tmp2 = *number3;
                tmp3 = *number1;
            }
        } else {
            tmp1 = *number3;
            tmp2 = *number2;
            tmp3 = *number1;
        }
    }
    *number1 = tmp1;
    *number2 = tmp2;
    *number3 = tmp3;
}

int main(void) {
    int number1, number2, number3;
    printf("input number1\n");
    scanf("%d", &number1);
    printf("input number2\n");
    scanf("%d", &number2);
    printf("input number3\n");
    scanf("%d", &number3);
    orderThreeNumbers(&number1, &number2, &number3);
    printf("%d %d %d", number1, number2, number3);
    return 0;
}