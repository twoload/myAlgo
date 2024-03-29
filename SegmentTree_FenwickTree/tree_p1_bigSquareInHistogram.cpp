#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

// n (1 <= n <= 100'000)
// h (0 <= h <= 1'000'000'000)
// brute force
// = O(n^2)
// divide and conquer
// segment tree O(nlogn)
//   need to save location of minimum
// 2 1 4 5 1 3 3
//   * (min height) -> area = 7 -> min height : segment tree
// L : (2) R: (4 5 1 3 3)
//   divide and conquer 

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
void init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
    } else {
        init(a, tree, node*2, start, (start+end)/2);
        init(a, tree, node*2+1, (start+end)/2+1, end);
        if (a[tree[node*2]] <= a[tree[node*2+1]]) {
            tree[node] = tree[node*2];
        } else {
            tree[node] = tree[node*2+1];
        }
    }
}
int query(vector<int> &a, vector<int> &tree, int node, int start, int end, int i, int j) {
    if (i > end || j < start) {
        return -1;
    }
    if (i <= start && end <= j) {
        return tree[node];
    }
    int m1 = query(a, tree, node*2, start, (start+end)/2, i, j);
    int m2 = query(a, tree, node*2+1, (start+end)/2+1, end, i, j);
    if (m1 == -1) {
        return m2;
    } else if (m2 == -1) {
        return m1;
    } else {
        if (a[m1] < a[m2]) {
            return m1;
        } else {
            return m2;
        }
    }
}
long long largest(vector<int> &a, vector<int> &tree, int start, int end) {
    int n = a.size();
    int m = query(a, tree, 1, 0, n-1, start, end);
    long long area = (long long)(end-start+1)*(long long)a[m];
    // L
    if (start <= m-1) {
        long long temp = largest(a, tree, start, m-1);
        if (area < temp) {
            area = temp;
        }
    }
    // R
    if (m+1 <= end) {
        long long temp = largest(a, tree, m+1, end);
        if (area < temp) {
            area = temp;
        }
    }
    return area;
}
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        int h = (int)(ceil(log2(n))+1e-9); // (int)(ceil(log2(n+1)))
        int tree_size = (1 << (h+1));
        vector<int> tree(tree_size);
        init(a, tree, 1, 0, n-1);
        cout << largest(a, tree, 0, n-1) << '\n';
    }
    return 0;
}