#include <stdio.h>

int visitedB[10];
int adjB[10][10];
int nB;

void bfs(int start) {
    int queue[20], front = 0, rear = 0;

    queue[rear++] = start;
    visitedB[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < nB; i++) {
            if (adjB[v][i] == 1 && visitedB[i] == 0) {
                queue[rear++] = i;
                visitedB[i] = 1;
            }
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &nB);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < nB; i++)
        for (int j = 0; j < nB; j++)
            scanf("%d", &adjB[i][j]);

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (int i = 0; i < nB; i++)
        visitedB[i] = 0;

    printf("BFS traversal: ");
    bfs(start);

    return 0;
}
