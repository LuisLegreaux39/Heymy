#include <stdio.h>
#include <cstdlib>

int main() {
    printf("Cubos narcisistas menores o iguales que 5000:\n");

    for (int num = 0; num <= 5000; num++) {
        int temp = num;
        int sum = 0;

        while (temp != 0) {
            int digit = temp % 10;
            sum += digit * digit * digit;
            temp /= 10;
        }

        if (sum == num) {
            printf("%d\n", num);
        }
    }
    system("pause");
    return 0;
}