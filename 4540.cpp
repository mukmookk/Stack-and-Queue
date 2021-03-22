#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    int cases, i;
    char *q_A[20];          // 아이템 1 <= m <= 20
    char *q_B[20];          // 아이템 1 <= m <= 20
    int moved[20];          // 큐 연산에 포함되지 않는 아이템은 모두 순서를 유지하고, 빈 위치로 이동하게 된다.
    int nextslot;           // 연산에 포함되지 않는 아이템 대입에 사용되는 index

    scanf("%d",&cases);     // 테스트 케이스 수

    for (i=0; i < cases; i++)
    {
        int m, n, j, source, target;

        // 테스트 케이스 item 정보
        scanf("%d %d", &m, &n);

        // 아이템 읽는 부분
        for (j=0; j<m; j++)
        {
            char temp[10];
            scanf ("%s", temp);
            q_A[j]=strdup(temp);
            q_B[j]=NULL;
            moved[j]=0;
        }

        // 큐 연산 1
        for (j=0; j<n; j++)
        {
            scanf("%d %d", &source, &target);
            q_B[target-1]=q_A[source-1];
            moved[source-1]=1;
        }

        // 큐 연산 2
        // 연산에 쓰이지 않는 나머지 아이템 순서대로 나열
        nextslot=0;
        for (j=0; j<m; j++)
        {
            if (!moved[j])
            {
             while (q_B[nextslot] != NULL) nextslot++;
             q_B[nextslot]=q_A[j];
             nextslot++;
            }
        }

        // 출력부
        for (j=0; j<m; j++)
        {
            printf("%s ",q_B[j]);
        }
        printf("\n");
    }

}
