#include <stdio.h>

int main() {
    printf("��: 0x9A�� �������� ���: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (0x9A >> i) & 1);
    }
    printf("\n");

    printf("��: 0x9A�� �������� 3bit ����Ʈ�� ��� : %d\n", (0x9A >> 3) & 1);

    int result_1 = (0x9A & 0xF0) >> 4;
    printf("��-1: 0xF0�� ����ŷ �� 4��Ʈ ���� ����Ʈ�� ���: %X\n", result_1);

    int result_2 = 0x9A & 0x0F;
    printf("��-2: 0x0F�� ����ŷ�� ���: %X\n", result_2);

    int left = result_1 ^ 0x0B;
    printf("��-1: ��-1�� 0x0B�� XOR�� ���(10����): %d\n", left);

    int right = result_2 ^ 0x0F;
    printf("��-2: ��-2�� 0x0F�� XOR�� ���(10����): %d\n", right);

    int temp = right;
    right = left;
    left = temp;

    int result = (left << 4) | right;
    printf("��-1: left�� ���� 4��Ʈ ����Ʈ�� �� right�� OR�� ���: %X\n", result);

    printf("��-2: left ��(10����): %d\n", left);
    printf("      right ��(10����): %d\n", right);

    return 0;
}