/**
 * I've attended the code.plus class (https://code.plus/)
 * And I've referred it's codes
 * And core parts can be come fully from the class.
 *
 * problem: https://www.acmicpc.net/problem/1761
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define left _left
#define right _right
using namespace std;

// 2 dfs => tree's diameter
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {    
    }
};
vector<Edge> a[100001];
bool check[100001];
int dist[100001];
void bfs(int start) {
    memset(dist, 0, sizeof(dist));
    memset(check, false, sizeof(check));
    queue<int> q;
    check[start] = true;
    q.push(start);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i=0; i<a[x].size(); i++) {
            Edge &e = a[x][i];
            if (check[e.to] == false) {
                dist[e.to] = dist[x] + e.cost;
                q.push(e.to);
                check[e.to] = true;
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        int x;
        scanf("%d", &x);
        while (true) {
            int y, z;
            scanf("%d", &y);
            if (y == -1) break;
            scanf("%d", &z);
            a[x].push_back(Edge(y,z));
        }
    }
    bfs(1);
    int start = 1;
    for (int i=2; i<=n; i++) {
        if (dist[i] > dist[start]) {
            start = i;
        }
    }
    bfs(start);
    int ans = dist[1]; // ? init value (range: 1~n)
    for (int i=2; i<=n; i++) {
        if (ans < dist[i]) {
            ans = dist[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}