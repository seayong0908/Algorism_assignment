#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1024];

    printf("문자열 입력 : ");
    if (!fgets(input, sizeof(input), stdin)) return 0;

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }

    if (len == 0) {
        printf("출력: (빈 문자열)\n");
        return 0;
    }

    char *stack = (char *)malloc(len * sizeof(char));
    if (!stack) {
        perror("메모리 할당 실패");
        return 1;
    }

    int top = -1;

    for(size_t i = 0; i< len; i++) {
        stack[++top] = input[i];
    }

    printf("출력: ");
    while (top >= 0) {
        putchar(stack[top--]);
    }
    putchar('\n');

    free(stack);
    return 0;
}
