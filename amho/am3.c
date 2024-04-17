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
/* Description : 스택을 초기화하는 함수
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
/* Description : 스택이 비어있는지 확인하는 함수
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
/* Description : 스택이 가득 차있는지 확인하는 함수
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
/* Description : 스택에 데이터를 저장하는 함수
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
/* Description : 스택에 데이터 저장이 가능한지 확인하는 함수
*/

bool isStackAvailable(int inputSize) {
    char answer;

    if (top + inputSize > MAX_STACK_SIZE - 1) {
        printf("스택 공간이 부족합니다.\n");
        printf("스택 공간을 초기화하고 저장하시겠습니까? 실행할 경우에 기존 데이터가 삭제됩니다. 실행하시겠습니까?(y/n)\n");
        (void)getchar();

        scanf("%c", &answer);

        if (answer == 'y') {
            initStack();
            printf("스택을 초기화 후 현재 데이터를 저장 합니다.\n");

            return true;
        }
        else {
            printf("현재 입력 값은 무시됩니다.\n");
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
/* Description : 스택에 저장된 값을 꺼내는 함수
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
/* Description : Tmp 스택이 비어있는지 확인하는 함수
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
/* Description : Tmp 스택에 데이터를 저장하는 함수
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
/* Description : Tmp 스택에 저장된 값을 꺼내는 함수
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
/* Description : Base 스택에 데이터를 저장하는 함수
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
/* Description : Base 스택에 저장된 값을 꺼내는 함수
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
/* Description : Base 스택의 최상위 값을 조회하는 함수
*/

int basePeek() {
    return BaseStack[baseTop];
}

/*
/* Name : popLastInput
/* Param : None
/* Return : None
/* Description : 스택에서 가장 최근 입력된 값을 순서대로 출력하고 삭제하는 함수
*/

void popLastInput() {
    if (isEmpty()) {
        printf("스택이 비어있습니다.\n");
        return;
    }

    int startIndex = basePop();
    int count = top - startIndex + 1;
    // baseTop을 사용하여 가장 최근에 입력된 문자열의 시작 인덱스를 찾는다.
    for (int i = count - 1; i >= 0; i--) {
        char ch = Stack[startIndex + i];
        printf("%c", ch);
    }
    printf("\n");// 스택의 상단부터 문자열을 거꾸로 출력한다.

    top = startIndex - 1;
    // 출력한 문자열을 스택에서 제거한다.
}

/*
/* Name : popLastInputOrdered
/* Param : None
/* Return : None
/* Description : 스택에서 가장 최근 입력된 값을 거꾸로 출력하고 삭제하는 함수
*/

void popLastInputOrdered() {
    if (isEmpty()) {
        printf("스택이 비어있습니다.\n");
        return;
    }

    int startIndex = basePop();
    int count = top - startIndex + 1;
    // baseTop을 사용하여 가장 최근에 입력된 문자열의 시작 인덱스를 찾는다.

    for (int i = 0; i < count; i++) {
        tmpPush(pop());
    }// TmpStack에 문자열을 임시로 저장한다.

    for (int i = 0; i < count; i++) {
        char ch = tmpPop();
        printf("%c", ch);
    }
    printf("\n");
}// TmpStack에서 문자열을 순서대로 꺼내어 출력한다.

/*
/* Name : peekLastInput
/* Param : None
/* Return : None
/* Description : 스택에서 가장 최근 입력된 값을 조회하여 출력하는 함수. 삭제하지 않음.
*/

void peekLastInput() {
    if (isEmpty()) {
        printf("스택이 비어있습니다.\n");
        return;
    }

    int startIndex = basePeek();
    int count = top - startIndex + 1;
    // baseTop을 사용하여 가장 최근에 입력된 문자열의 시작 인덱스를 찾는다.

    for (int i = count - 1; i >= 0; i--) {
        char ch = Stack[startIndex + i];
        printf("%c", ch);
    }// 스택의 상단부터 문자열의 마지막 문자까지 거꾸로 확인한다.
    printf("\n");
}


int main() {
    int nMenu = 0, inputSize = 0;
    char inputString[MAX_INPUT_SIZE] = { 0, };

    initStack();

    printf("===== Leve2 Test =====\n\n");
    printf("1. 문자열 입력(10자 이내)\n");
    printf("2. 가장 최근 입력한 문자열을 거꾸로 출력(최근 입력 순서대로 출력하고, 메모리에서 삭제) hello -> olleh\n");
    printf("3. 가장 최근 입력한 문자열을 입력 순서대로 출력(메모리에서 삭제) hello -> hello\n");
    printf("4. 가장 최근 입력한 문자열 중 마지막 문자를 출력(메모리에서 삭제하지 않음 hello -> olleh)\n");
    printf("5. 가장 최근 입력한 문자열의 개수를 출력 hello -> 5\n");
    printf("6. 프로그램 종료\n\n");

    while (1) {
        printf("원하는 기능의 번호를 입력하세요 : ");
        scanf("%d", &nMenu);
        (void)getchar();

        switch (nMenu) {
        case 1: {
            printf("문자열을 입력하세요: ");
            scanf("%s", inputString);
            inputSize = (int)strlen(inputString);
            if (inputSize > 10) {
                printf("10자 이상입니다. \n");
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
                printf("스택이 비어있습니다.\n");
                break;
            }

            // baseTop을 사용하여 가장 최근에 입력된 문자열의 시작 인덱스를 찾습니다.
            int startIndex = basePeek();
            int length = top - startIndex + 1;

            printf("최근 입력값 길이 : %d\n", length);
            break;
        }

        case 6: {
            printf("프로그램 종료");
            return ERROR_SUCCESS;
        }
        default:
            printf("입력이 잘못 되었습니다.\n");
        }
    }

    return ERROR_SUCCESS;
}