#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int **rows = (int **)malloc(n * sizeof(int *));
    int **cols = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        int len;
        scanf("%d", &len);
        rows[i] = (int *)malloc(len * sizeof(int));
        for (int j = 0; j < len; j++)
        {
            scanf("%d", &rows[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int len;
        scanf("%d", &len);
        cols[i] = (int *)malloc(len * sizeof(int));
        for (int j = 0; j < len; j++)
        {
            scanf("%d", &cols[i][j]);
        }
    }
    printf("Rows:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sizeof(rows[i])/sizeof(rows[i][0]); j++) {
            printf("%d ", rows[i][j]);
        }
        printf("\n");
    }
    printf("Columns:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sizeof(cols[i])/sizeof(cols[i][0]); j++) {
            printf("%d ", cols[i][j]);
        }
        printf("\n");
    }
    free(**cols);
    return 0;
}
