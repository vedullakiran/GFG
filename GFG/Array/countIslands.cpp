#include <iostream>
#include <stdio.h>
#include <algorithm>
#define COL 5
#define ROW 5

using namespace std;

bool isSafe(int row, int col, int M[][COL], int visited[][COL])
{
    return ((row>=0) && (row<ROW) && (col>=0) && (col<COL) && M[row][col] && !visited[row][col]);
}

void dfs(int row, int col, int M[][COL], int visited[][COL])
{
    visited[row][col]=1;
    static int rowN[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int colN[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    for(int i=0; i<8; i++)
    if(isSafe(row+rowN[i], col+colN[i], M, visited))
        dfs(row+rowN[i], col+colN[i], M, visited);
}

int countIslands(int M[][COL])
{
    int count=0;
    int visited[ROW][COL];
    int i, j;

    for(i=0; i<ROW; i++)
        for(j=0; j<COL; j++)
            visited[i][j]=0;

    for(i=0; i<ROW; i++)
        for(j=0; j<COL; j++)
            if(M[i][j] && !visited[i][j])
            {
                count++;
                dfs(i, j, M, visited);
            }

}

int main()
{
    int M[][COL]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
    printf("Number of islands is: %d\n", countIslands(M));

    return 0;
}
