#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstring>
using namespace std;
int d[1001][1001];
int main() {
    int n;
    cin >> n;
    memset(d, -1, sizeof(d));
    queue<pair<int,int>> q;
    d[1][0] = 0;
    while (!q.empty()) {
        int s, c;
        tie(s, c) = q.front();
        q.pop();
        if (d[s][s] == -1) {
            d[s][s] = d[s][c] + 1;
            q.push(make_pair(s,s));
        }
        if (s+c <= n && d[s+c][c] == -1) {
            d[s+c][c] = d[s][c] + 1;
            q.push(make_pair(s+c, c));
        }
        if (s-1 >= 0 && d[s-1][c] == -1) {
            d[s-1][c] = d[s][c] + 1;
            q.push(make_pair(s-1, c));
        }
    }
    int ans = -1;
    for (int i=0; i<=n; i++) {
        if (d[n][i] != -1) {
            if (ans == -1 || ans > d[n][i]) {
                ans = d[n][i];
            }
        }
    }
    cout << ans << '\n';
    return 0;
} 

