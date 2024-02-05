//# I've attended the code.plus class (https://code.plus/)
//# And I've referred it's codes
//# And core parts can be come fully from the class.

// 2^20
// 0000000 ---> N/2
// 1111111 ---> N/2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int s[20][20];
int main() {

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> s[i][j];
        }
    }

    int ans = -1;
    for (int i=0; i<(1<<n); i++) {
        vector<int> first, second;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) {
                first.push_back(j);
            } else {
                second.push_back(j);
            }
        }
        if (first.size() != n/2) continue;
        int t1 =0; // initialize : very important!!!
        int t2 =0;

        for(int i=0; i<first.size(); i++) {
            printf("%d ", first[i]);
        }
        printf("\n");
        for(int i=0; i<second.size(); i++) {
            printf("%d ", second[i]);
        }
        printf("\n");
        for (int l1=0; l1<n/2; l1++) {
            for (int l2=0; l2<n/2; l2++) {
                if (l1 == l2) continue;
                t1 += s[first[l1]][first[l2]];
                printf("t1(%d) += %d (l1:%d,l2:%d)\n", t1, s[first[l1]][first[l2]], first[l1], first[l2]);
                t2 += s[second[l1]][second[l2]];
                printf("t2(%d) += %d (l1:%d,l2:%d)\n", t2, s[second[l1]][second[l2]], second[l1], second[l2]);
            }
        }
        int diff = t1-t2;
        if (diff < 0) diff = -diff;
        if (ans == -1 || ans > diff) {
            ans = diff;
        }
    }
    cout << ans << '\n';
}