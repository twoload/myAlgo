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

int n;
int a[401][801];
int s[401][801];
int ans = 0;
/**
 *              (1,1)
 *         (2,1)(2,2)(2,3)
 *    (3,1)(3,2)(3,3)(3,4)(3,5)
 * ....
 * 
 * 
 * 
 * 
 */
void calc(int row, int left, int right, int sum) {
    if (row < 1 || row > n) return;
    if (left < 1 || right > 2*row-1) return;
    //printf("(B) row:%d (%d-%d) (sum:%d)\n", row, left, right, sum);
    sum += s[row][right] - s[row][left-1];
    printf("row:%d (%d-%d) (sum:%d)\n", row, left, right, sum);
    if (sum > ans) ans = sum;
    if (left % 2 == 0) {
        calc(row-1, left-2, right, sum);
    } else {
        calc(row+1, left, right+2, sum);
    }
}

int main() {
    for (int tc=1;;tc++) {
        cin >> n;
        if (n == 0) break;
        ans = -100000;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=2*i-1; j++) {
                cin >> a[i][j];
                s[i][j] = s[i][j-1] + a[i][j];
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=2*i-1; j++) {
                printf("=============\n");
                calc(i,j,j,0);
            }
        }
        cout << tc << ". " << ans << '\n';
    }
    return 0;
}