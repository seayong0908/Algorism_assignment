#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, min_idx, temp;
    printf("1000개의 임의의 수 생성\n\n");
    int arr[1000];
    srand((unsigned)time(NULL));

    for (i = 0; i < 1000; i++) {
        arr[i] = rand() % 10000; // 0부터 9999 사이의 임의의 정수 생성
    }
    int n = 1000;

    time_t start_time = clock();
    // 선택 정렬 알고리즘
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // 최소값과 현재 위치의 값 교환
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }

    time_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("정렬된 정수:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("선택 정렬에 걸린 시간: %f 초\n", time_taken);

    return 0;
}