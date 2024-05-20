#include <stdio.h>
#include <stdbool.h>
#define lar 14

bool validatehorizontal(int N, int M, char puzzle[][M+1], int clues[][lar])
{
    int segment;
    int consec;
    for (int i = 0; i < N; i++)
    {
        segment = 0;
        consec = 0;
        for (int j = 0; j < M; j++)
        {
            if (puzzle[i][j] == 'o')
            {
                if (clues[i][0] == 0)
                {
                    return false;
                }
                if (consec == 0)
                {
                    segment++;
                    consec++;
                }
                else
                {
                    consec++;
                    if (consec > clues[i][segment])
                    {
                        return false;
                    }
                }
            }
            else
            {
                if (consec != 0)
                {
                    if (consec != clues[i][segment])
                    {
                        return false;
                    }
                    consec = 0;
                }
            }
        }
        if (segment != clues[i][0])
        {
            return false;
        }
    }
    return true;
}

bool validatevertical(int N, int M, char puzzle[][M+1], int clues[][lar])
{
    int segment;
    int consec;
    for (int i = 0; i < M; i++) {
        segment = 0;
        consec = 0;
        for (int j = 0; j < N; j++) {
            if (puzzle[j][i] == 'o') {
                if (clues[i + N][0] == 0) {
                    return false;
                }
                if (consec == 0) {
                    segment++;
                    consec++;
                }
                else {
                    consec++;
                    if (consec > clues[i + N][segment]) {
                        return false;
                    }
                }
            }
            else {
                if (consec != 0) {
                    if (consec != clues[i + N][segment]) {
                        return false;
                    }
                consec = 0;
                }
            }
        }
        if (segment != clues[i + N][0])
        {
            return false;
        }
    }
    return true;
}

bool fillpuzzle(int N, int M, char puzzle[][M+1], int clues[][lar]) {
    bool filled = true;
    char *ptr;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (filled && (puzzle[i][j] == 'x'))
            {
                ptr = &(puzzle[i][j]);
                filled = false;
            }
        }
    for(int i = 0; i < n; i++)
    }
    bool validhor = validatehorizontal(N, M, puzzle, clues);
    bool validver = validatevertical(N, M, puzzle, clues);
    if (filled) {
        if ((validhor) && (validver)) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (j == M - 1) {
                        printf("%c\n", puzzle[i][j]);
                    }
                    else {
                        printf("%c", puzzle[i][j]);
                    }
                }
            }
            return true;
        }
        else {
            return false;
        }
    }
    else {
        *ptr = 'o';
        bool succeed = fillpuzzle(N, M, puzzle, clues);
        if (succeed) {
            return true;
        }
        *ptr = '_';
        succeed = fillpuzzle(N, M, puzzle, clues);
        if (succeed) {
            return true;
        }
        *ptr = 'x';
        return false;
    }
}

int main(void) 
{
    int N, M;
    scanf("%d%d", &N, &M);
    char puzzle[N][M+1];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            puzzle[i][j] = 'x';
        }
    }
    int nplusm = N + M;
    int clues[nplusm][lar];
    for (int i = 0; i < nplusm; i++) {
        for (int j = 0; j < lar; j++) {
            clues[i][j] = 0;
        }
    }
    for (int i = 0; i < nplusm; i++) {
        for (int j = 0; j <= lar; j++) {
            scanf("%d", &clues[i][j]);
            if (clues[i][0] == 0) {
                break;
            }
            if (j == clues[i][0]) {
                break;
            }
        }
    }
    bool solution = fillpuzzle(N, M, puzzle, clues);
}
