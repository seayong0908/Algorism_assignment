#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void play_game(char **words, char *answer, int *n_ptr){
    int n = *n_ptr;
    int r = rand() % n;
    char *removed_ptr = words[r]; // 제거할 단어의 포인터
    
    for(int i=r; i<n-1; i++){
        words[i] = words[i+1];
    }
    n--; // 현재 단어 수 감소 

    printf("\n단어 리스트 [");
    for(int i=0; i<n; i++){
        printf("%s ", words[i]);
    }
    printf("]\n빠진 단어는? ");

    scanf("%99s", answer);

    if(strcmp(answer, removed_ptr) == 0){
        printf("정답입니다!\n");
    } else {
        printf("틀렸습니다! 정답: %s\n", removed_ptr);
    }

    if(n > 0){
        char cont;
        
        CONTINUE_PROMPT:
        printf("계속하시겠습니까? (y/n): ");
        scanf(" %c", &cont);
        
        if(cont == 'y' || cont == 'Y') play_game(words, answer, &n); 
        else if (cont == 'n' || cont == 'N'){
            printf("게임을 종료합니다.\n");
        }
        else {
            printf("잘못된 입력입니다. 다시 입력해주세요.\n");
            goto CONTINUE_PROMPT;
        }
    }
}

int main(){

    int n;
    printf("몇 개의 단어를 입력하시겠습니까? : ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("올바른 개수를 입력하세요.\n");
        return 1;
    }

    char **words = (char **)malloc(n * sizeof(char *));

    for(int i=0; i<n; i++){
        words[i] = (char *)malloc(100 * sizeof(char));
    }

    for(int i=0; i<n; i++){
        printf("%d번째 단어를 입력하세요: ", i+1);
        scanf("%99s", words[i]);
    }

    srand((unsigned)time(NULL));
    char answer[100];
    play_game(words, answer, &n);

    for(int i=0; i<n; i++){
        free(words[i]);
    }
    free(words);

    return 0;
}