#include <stdio.h>

int main() {
    printf("가: 0x9A를 이진수로 출력: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (0x9A >> i) & 1);
    }
    printf("\n");

    printf("나: 0x9A를 우측으로 3bit 시프트한 결과 : %d\n", (0x9A >> 3) & 1);

    int result_1 = (0x9A & 0xF0) >> 4;
    printf("다-1: 0xF0와 마스킹 후 4비트 우측 시프트한 결과: %X\n", result_1);

    int result_2 = 0x9A & 0x0F;
    printf("다-2: 0x0F와 마스킹한 결과: %X\n", result_2);

    int left = result_1 ^ 0x0B;
    printf("라-1: 다-1을 0x0B와 XOR한 결과(10진수): %d\n", left);

    int right = result_2 ^ 0x0F;
    printf("라-2: 다-2를 0x0F와 XOR한 결과(10진수): %d\n", right);

    int temp = right;
    right = left;
    left = temp;

    int result = (left << 4) | right;
    printf("마-1: left를 좌측 4비트 시프트한 후 right와 OR한 결과: %X\n", result);

    printf("마-2: left 값(10진수): %d\n", left);
    printf("      right 값(10진수): %d\n", right);

    return 0;
}