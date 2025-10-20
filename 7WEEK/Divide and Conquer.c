#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char subject_name[100];
    int chapter_count;
    int study_amounts[100];
    int min_study_amount;
    int min_study_chapter; // 이 과목에서 가장 공부가 덜 된 챕터 번호
} Chapter_info;

int main() {
    char temp_subject[100];
    int n = 0;

    Chapter_info *chapters = (Chapter_info *)malloc(100 * sizeof(Chapter_info));

    if (chapters == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    while (n < 100) {
        printf("\n과목 명을 입력하세요 (그만두려면 '끝' 입력): ");
        scanf("%s", temp_subject);

        if (strcmp(temp_subject, "끝") == 0) {
            break;
        }

        strcpy(chapters[n].subject_name, temp_subject);

        printf("'%s' 과목의 챕터 수는? : ", chapters[n].subject_name);
        scanf("%d", &chapters[n].chapter_count);

        for (int i = 0; i < chapters[n].chapter_count; i++) {
            printf("  %d번째 챕터의 공부한 양 (1~100): ", i + 1); // 보여줄 땐 1부터
            int temp_amount;
            scanf("%d", &temp_amount);

            if (temp_amount < 1 || temp_amount > 100) {
                printf("    [오류] 1~100 사이의 값을 입력해주세요.\n");
                i--; // 이번 차례 다시
                continue;
            }
            // 저장할 땐 0번 인덱스부터 차곡차곡!
            chapters[n].study_amounts[i] = temp_amount;
        }
        n++;
    }

    for (int i = 0; i < n; i++) {
        int min_val = 101;
        int min_chap_num = 0;
        for (int j = 0; j < chapters[i].chapter_count; j++) {
            if (chapters[i].study_amounts[j] < min_val) {
                min_val = chapters[i].study_amounts[j]; // 최소값 갱신
                min_chap_num = j + 1; 
            }
        }
        chapters[i].min_study_amount = min_val;
        chapters[i].min_study_chapter = min_chap_num;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (chapters[j].min_study_amount > chapters[j + 1].min_study_amount) {
                Chapter_info temp = chapters[j];
                chapters[j] = chapters[j + 1];
                chapters[j + 1] = temp;
            }
        }
    }

    printf("\n======================================\n");
    printf("      🚀 최종 공부 순서 🚀\n");
    printf("======================================\n");

    for (int i = 0; i < n; i++) {
        printf("%d순위: %s (가장 시급한 챕터: %d장, 공부량: %d)\n",
               i + 1,
               chapters[i].subject_name,
               chapters[i].min_study_chapter,
               chapters[i].min_study_amount);
    }

    free(chapters);
    return 0;
}