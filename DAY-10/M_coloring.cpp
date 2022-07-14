#include<bits/stdc++.h>
using namespace std;

const int N = 20;
int color[N];

bool check(int u, int n, int c, bool graph[101][101]) {
    for (int v = 0; v < n; v++) {
        if (u != v && graph[u][v] && color[v] == c)
            return true;
    }
    return false;
}

bool help(int u, int n, int m, bool graph[101][101]) {
    if (u == n)
        return true;
    for (int c = 0; c < m; c++) {
        if (check(u, n, c, graph))
            continue;
        color[u] = c;
        if (help(u + 1, n, m, graph))
            return true;
        color[u] = -1;
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    memset(color, -1, sizeof(color));
    return help(0, n, m, graph);
}