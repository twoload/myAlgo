#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool can(bool blind, char from, char to) {
    if (from == to) return true;
    if (blind) {
        if (from == 'R' && to == 'G') return true;
        if (from == 'G' && to == 'R') return true;
    }
    return false;
}

int go(vector<string>& a, bool blind) {
    int n = a.size();
    vector<vector<bool>> check(n, vector<bool>(n, false));
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (check[i][j] == false) {
                ans += 1;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                check[i][j] = true;
                while (!q.empty()) {
                    int x,y;
                    tie(x,y) = q.front(); q.pop();
                    for (int k=0; k<4; k++) {
                        int nx = x+dx[k];
                        int ny = y+dy[k];
                        if (0<=nx && nx<n && 0<=ny && ny<n) {
                            if (check[nx][ny]) continue;
                            if (can(blind, a[x][y], a[nx][ny])) {
                                check[nx][ny] = true;
                                q.push(make_pair(nx,ny));
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << go(a, false) << ' ' << go(a, true) << '\n'; 
}