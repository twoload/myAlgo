#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif
//https://justicehui.github.io/ps/2019/09/12/BOJ13505/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

char s[33];

struct Node{
    Node *child[2];
    Node() {
        child[0] = child[1] = 0;
    }
    ~Node() {
        if (child[0]) delete child[0];
        if (child[1]) delete child[1];
    }
    void insert(char *s) {
        if (*s == 0) return;
        int t = *s - '0';
        if(!child[t]) child[t] = new Node;
        child[t]->insert(s+1);
    }
    void query(char *s) {
        if (*s == 0) return;
        int t = *s - '0'; t^=1;
        if (child[t]) {
            *s = '1';
            child[t]->query(s+1);
        } else {
            *s = '0';
            child[t^1]->query(s+1);
        }
    }
};

int main() {
    int n ; 
    cin >> n;
    vector<int> v(n);
    Node *root = new Node;
    for (auto &i : v) {
        cin >> i;
    }
    for (auto i : v) {
        for (int j=31; j>=0; j--) {
            if (i&1) {
                s[j] = '1';
            } else {
                s[j] = '0';
            }
            i >>= 1;
        }
        s[32] = 0;
        root->insert(s);
    }
    int ans = -1;
    for (auto i : v) {
        for (int j=31; j>=0; j--) {
            if (i&1) {
                s[j] = '1';
            } else {
                s[j] = '0';
            }
            i >>= 1;
        }
        s[32] = 0;
        root->query(s);
        int now = 0;
        int tmp = 1;
        for (int i=31; i>=0; i--) {
            if (s[i] == '1') {
                now |= tmp;
            }
            tmp <<= 1;
        }
        ans = max(ans, now);
    }
    cout << ans;
    return 0;
}