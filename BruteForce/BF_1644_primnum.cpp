#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <deque>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n+1);
    vector<int> p;
    for (int i=2; i<=n; i++) {
        if (c[i] == false) {
            p.push_back(i);
            for (int j=i*2; j<=n; j+=i) {
                c[j] = true;
            }
        }        
    }

    int l=0;
    int r=0;
    int sum = p.empty() ? 0 : p[0];
    int ans = 0;

    while (l<=r && r<p.size()) {
        if (sum <= n) {
            if (sum == n) {
                ans += 1;
            }
            r += 1;
            if (r<p.size()) {
                sum += p[r];
            }
        } else {
            sum -= p[l];
            l += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}