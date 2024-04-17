/*#include <stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX_STACK_SIZE 10
#define MAX_INPUT_SIZE 10
#define ERROR_SUCCESS 0
#define ERROR_FAIL -1

int top = 0;
int baseTop = 0;
int tmpTop = 0;
char Stack[MAX_STACK_SIZE] = { 0, };
char TmpStack[MAX_STACK_SIZE] = { 0, };
char BaseStack[MAX_STACK_SIZE] = { 0, };

void initStack();
bool isEmpty();
bool isFull();
int push(char value);
bool isStackAvailable(int inputSize);
char pop();
bool isTmpEmpty();
int tmpPush(char value);
char tmpPop();
int basePush(int value);
int basePop();
int basePeek();
void popLastInput();
void popLastInputOrdered();
void peekLastInput();

/*
/* Name : initStack
/* Param : None
/* Return : None
/* Description : ������ �ʱ�ȭ�ϴ� �Լ�
*/

void initStack() {
    top = -1;
    baseTop = -1;
    tmpTop = -1;
}

/*
/* Name : isEmpty
/* Param : None
/* Return : true, false
/* Description : ������ ����ִ��� Ȯ���ϴ� �Լ�
*/

bool isEmpty() {
    if (-1 == top)
        return true;
    else
        return false;
}

/*
/* Name : isFull
/* Param : None
/* Return : true, false
/* Description : ������ ���� ���ִ��� Ȯ���ϴ� �Լ�
*/

bool isFull() {
    if (MAX_STACK_SIZE - 1 == top)
        return true;
    else
        return false;
}

/*
/* Name : push
/* Param : None
/* Return : top, ERROR_FAIL
/* Description : ���ÿ� �����͸� �����ϴ� �Լ�
*/

int push(char value) {
    if (!isFull()) {
        top = top + 1;
        Stack[top] = value;
        return top;
    }
    else {
        return ERROR_FAIL;
    }
}

/*
/* Name : isStackAvailable
/* Param : None
/* Return : true, false
/* Description : ���ÿ� ������ ������ �������� Ȯ���ϴ� �Լ�
*/

bool isStackAvailable(int inputSize) {
    char answer;

    if (top + inputSize > MAX_STACK_SIZE - 1) {
        printf("���� ������ �����մϴ�.\n");
        printf("���� ������ �ʱ�ȭ�ϰ� �����Ͻðڽ��ϱ�? ������ ��쿡 ���� �����Ͱ� �����˴ϴ�. �����Ͻðڽ��ϱ�?(y/n)\n");
        (void)getchar();

        scanf("%c", &answer);

        if (answer == 'y') {
            initStack();
            printf("������ �ʱ�ȭ �� ���� �����͸� ���� �մϴ�.\n");

            return true;
        }
        else {
            printf("���� �Է� ���� ���õ˴ϴ�.\n");
            return false;
        }
    }
    else {
        return true;
    }
}

/*
/* Name : pop
/* Param : None
/* Return : char, NULL
/* Description : ���ÿ� ����� ���� ������ �Լ�
*/

char pop() {
    if (isEmpty()) {
        return '\0';
    }

    int topIndex = top;
    top = top - 1;

    return Stack[topIndex];
}

/* Name : isTmpEmpty
/* Param : None
/* Return : true, false
/* Description : Tmp ������ ����ִ��� Ȯ���ϴ� �Լ�
*/

bool isTmpEmpty() {
    if (-1 == tmpTop)
        return true;
    else
        return false;
}

/*
/* Name : tmpPush
/* Param : None
/* Return : int
/* Description : Tmp ���ÿ� �����͸� �����ϴ� �Լ�
*/

int tmpPush(char value) {
    tmpTop = tmpTop + 1;
    TmpStack[tmpTop] = value;

    return tmpTop;
}

/*
/* Name : tmpPop
/* Param : None
/* Return : char
/* Description : Tmp ���ÿ� ����� ���� ������ �Լ�
*/

char tmpPop() {
    if (isTmpEmpty()) {
        return '\0';
    }

    int tmpIndex = tmpTop;
    tmpTop = tmpTop - 1;

    return TmpStack[tmpIndex];
}

/*
/* Name : basePush
/* Param : None
/* Return : baseTop
/* Description : Base ���ÿ� �����͸� �����ϴ� �Լ�
*/

int basePush(int value) {
    baseTop = baseTop + 1;
    BaseStack[baseTop] = value;

    return baseTop;
}

/*
/* Name : basePop
/* Param : None
/* Return : int
/* Description : Base ���ÿ� ����� ���� ������ �Լ�
*/

int basePop() {
    int baseIndex = baseTop;
    baseTop = baseTop - 1;

    return BaseStack[baseIndex];
}

/*
/* Name : basePeek
/* Param : None
/* Return : int
/* Description : Base ������ �ֻ��� ���� ��ȸ�ϴ� �Լ�
*/

int basePeek() {
    return BaseStack[baseTop];
}

/*
/* Name : popLastInput
/* Param : None
/* Return : None
/* Description : ���ÿ��� ���� �ֱ� �Էµ� ���� ������� ����ϰ� �����ϴ� �Լ�
*/

void popLastInput() {
    if (isEmpty()) {
        printf("������ ����ֽ��ϴ�.\n");
        return;
    }

    int startIndex = basePop();
    int count = top - startIndex + 1;
    // baseTop�� ����Ͽ� ���� �ֱٿ� �Էµ� ���ڿ��� ���� �ε����� ã�´�.
    for (int i = count - 1; i >= 0; i--) {
        char ch = Stack[startIndex + i];
        printf("%c", ch);
    }
    printf("\n");// ������ ��ܺ��� ���ڿ��� �Ųٷ� ����Ѵ�.

    top = startIndex - 1;
    // ����� ���ڿ��� ���ÿ��� �����Ѵ�.
}

/*
/* Name : popLastInputOrdered
/* Param : None
/* Return : None
/* Description : ���ÿ��� ���� �ֱ� �Էµ� ���� �Ųٷ� ����ϰ� �����ϴ� �Լ�
*/

void popLastInputOrdered() {
    if (isEmpty()) {
        printf("������ ����ֽ��ϴ�.\n");
        return;
    }

    int startIndex = basePop();
    int count = top - startIndex + 1;
    // baseTop�� ����Ͽ� ���� �ֱٿ� �Էµ� ���ڿ��� ���� �ε����� ã�´�.

    for (int i = 0; i < count; i++) {
        tmpPush(pop());
    }// TmpStack�� ���ڿ��� �ӽ÷� �����Ѵ�.

    for (int i = 0; i < count; i++) {
        char ch = tmpPop();
        printf("%c", ch);
    }
    printf("\n");
}// TmpStack���� ���ڿ��� ������� ������ ����Ѵ�.

/*
/* Name : peekLastInput
/* Param : None
/* Return : None
/* Description : ���ÿ��� ���� �ֱ� �Էµ� ���� ��ȸ�Ͽ� ����ϴ� �Լ�. �������� ����.
*/

void peekLastInput() {
    if (isEmpty()) {
        printf("������ ����ֽ��ϴ�.\n");
        return;
    }

    int startIndex = basePeek();
    int count = top - startIndex + 1;
    // baseTop�� ����Ͽ� ���� �ֱٿ� �Էµ� ���ڿ��� ���� �ε����� ã�´�.

    for (int i = count - 1; i >= 0; i--) {
        char ch = Stack[startIndex + i];
        printf("%c", ch);
    }// ������ ��ܺ��� ���ڿ��� ������ ���ڱ��� �Ųٷ� Ȯ���Ѵ�.
    printf("\n");
}


int main() {
    int nMenu = 0, inputSize = 0;
    char inputString[MAX_INPUT_SIZE] = { 0, };

    initStack();

    printf("===== Leve2 Test =====\n\n");
    printf("1. ���ڿ� �Է�(10�� �̳�)\n");
    printf("2. ���� �ֱ� �Է��� ���ڿ��� �Ųٷ� ���(�ֱ� �Է� ������� ����ϰ�, �޸𸮿��� ����) hello -> olleh\n");
    printf("3. ���� �ֱ� �Է��� ���ڿ��� �Է� ������� ���(�޸𸮿��� ����) hello -> hello\n");
    printf("4. ���� �ֱ� �Է��� ���ڿ� �� ������ ���ڸ� ���(�޸𸮿��� �������� ���� hello -> olleh)\n");
    printf("5. ���� �ֱ� �Է��� ���ڿ��� ������ ��� hello -> 5\n");
    printf("6. ���α׷� ����\n\n");

    while (1) {
        printf("���ϴ� ����� ��ȣ�� �Է��ϼ��� : ");
        scanf("%d", &nMenu);
        (void)getchar();

        switch (nMenu) {
        case 1: {
            printf("���ڿ��� �Է��ϼ���: ");
            scanf("%s", inputString);
            inputSize = (int)strlen(inputString);
            if (inputSize > 10) {
                printf("10�� �̻��Դϴ�. \n");
                break;
            }

            if (isStackAvailable(inputSize)) {
                for (int i = 0; i < inputSize; i++) {
                    push(inputString[i]);
                }
                basePush(top + 1 - inputSize);
            }
            break;
        }
        case 2: {
            popLastInput();
            break;
        }
        case 3: {
            popLastInputOrdered();
            break;
        }
        case 4: {
            peekLastInput();
            break;
        }
        case 5: {
            if (isEmpty()) {
                printf("������ ����ֽ��ϴ�.\n");
                break;
            }

            // baseTop�� ����Ͽ� ���� �ֱٿ� �Էµ� ���ڿ��� ���� �ε����� ã���ϴ�.
            int startIndex = basePeek();
            int length = top - startIndex + 1;

            printf("�ֱ� �Է°� ���� : %d\n", length);
            break;
        }

        case 6: {
            printf("���α׷� ����");
            return ERROR_SUCCESS;
        }
        default:
            printf("�Է��� �߸� �Ǿ����ϴ�.\n");
        }
    }

    return ERROR_SUCCESS;
}