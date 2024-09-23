#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

//순열을 생성하는 함수
void perm(char* list, int i, int n) {
    int j, temp;
    if (i == n) {
        for (j = 0; j <= n; j++) {
            printf("%c", list[j]);
        }
        printf("   ");
    }
    else {
        for (j = i; j <= n; j++) {
            //j와 n의 값을 SWAP, 그리고 다시 SWAP으로 원상복구
            SWAP(list[i], list[j], temp);
            perm(list, i + 1, n);
            SWAP(list[i], list[j], temp);
        }
    }

}

//순열을 생성하는 함수
void perm_int(int* list, int i, int n) {
    int j, temp;
    if (i == n) {
        for (j = 0; j <= n; j++) {
            printf("%d", list[j]);
        }
        printf("   ");
    }
    else {
        for (j = i; j <= n; j++) {
            //j와 n의 값을 SWAP, 그리고 다시 SWAP으로 원상복구
            SWAP(list[i], list[j], temp);
            perm_int(list, i + 1, n);
            SWAP(list[i], list[j], temp);
        }
    }
}

int main(void)
{
    //2.1-------------------------------------------------------
    /*
    char A[4][10] = {"GO","BOY","GIRL","GIRLS"};
    for(int i=0; i<4; i++) {
        printf("제시 문자열 : %s\n",A[i]);
        perm(A[i],0,strlen(A[i])-1);
        printf("\n");
    }
    */
    //2.2-------------------------------------------------------
    /*
    while (1) {
        int n = 0;
        int arr[33] = { 0, };
        double duration;
        clock_t start;

        printf("1부터 n사이의 숫자들을 이용한 순열\n");
        printf("입력 : ");
        scanf("%d", &n);

        if (n == -1) {
            printf("종료\n");
            break;
        }
        if (n > 32 || n < 1) {
            printf("입력 범위(1~32)를 벗어났습니다.\n");
            continue;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        start = clock();
        perm_int(arr, 0, n - 1);
        printf("\n");

        duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
        printf("time : %f\n", duration);
    }
    */
    //2.3-------------------------------------------------------
    
    int cycle = 0;
    float time[11] = { 0, };

    while (cycle <= 10) {
        int arr[33] = { 0, };
        double duration;
        clock_t start;

        for (int i = 0; i < cycle; i++) {
            arr[i] = i + 1;
        }
        start = clock();
        perm_int(arr, 0, cycle - 1);
        printf("\n");

        duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
        time[cycle] = duration;
        cycle++;

    }
    printf("원소 개수    시간\n");
    for (int i = 1; i <=10; i++) {
        printf("%6d      %.3f\n", i,time[i]);
    }
}
