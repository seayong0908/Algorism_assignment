#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // 큐 최대 크기

typedef struct {
    char* items[MAX];
    int front, rear;
} Queue;

// 큐 초기화
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// 큐가 비었는지 확인
int isEmpty(Queue* q) {
    return q->front == -1;
}

// 큐가 가득 찼는지 확인
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// 큐에 삽입 (enqueue)
void enqueue(Queue* q, const char* filename) {
    if (isFull(q)) {
        printf("큐가 가득 찼습니다!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = (char*)malloc(strlen(filename)+1);
    strcpy(q->items[q->rear], filename);
    printf("파일 '%s' 대기열에 추가됨\n", filename);
}

// 큐에서 제거 (dequeue)
char* dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("큐가 비어있습니다!\n");
        return NULL;
    }
    char* file = q->items[q->front];
    if (q->front == q->rear) { // 마지막 원소 제거
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return file;
}

// 현재 큐 상태 출력
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("[큐 비어 있음]\n");
        return;
    }
    printf("현재 대기열: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%s ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    char input[100];

    // 파일 입력
    printf("프린터에 넣을 파일 이름 입력 (종료는 'END'): \n");
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "END") == 0) break;
        enqueue(&q, input);
        printQueue(&q);
    }

    printf("\n=== 프린터 작업 시작 ===\n");

    // 파일 출력
    while (!isEmpty(&q)) {
        char* file = dequeue(&q);
        printf("출력 완료: %s\n", file);
        free(file); // 메모리 해제
        printQueue(&q);
    }

    printf("모든 작업 완료!\n");

    return 0;
}
