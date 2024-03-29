#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
// Ford Fulkerson
using namespace std;
struct MaximumFlow {
    struct Edge {
        int to;
        int capacity;
        Edge *rev;
        Edge(int to, int capacity) : to(to), capacity(capacity) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph; // Edge*
    vector<bool> check;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
    };
    void add_edge(int u, int v, int cap) {
        Edge *ori = new Edge(v,cap);
        Edge *rev = new Edge(u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    int dfs(int x, int c) {
        if (check[x]) return 0;
        check[x] = true;
        if (x == sink) {
            return c;
        }
        for (int i=0; i<graph[x].size(); i++) {
            if (graph[x][i]->capacity > 0) {
                int nc = graph[x][i]->capacity;
                if (c != 0 && c < nc) { // init c == 0, dfs(source, 0)
                    nc = c;
                }
                int f = dfs(graph[x][i]->to, nc);
                if (f) {
                    graph[x][i]->capacity -= f;
                    graph[x][i]->rev->capacity += f;
                    return f;
                }
            }
        }
        return 0;
    }
    int flow() {
        int ans = 0;
        while (true) {
            fill(check.begin(),check.end(),false);
            int f = dfs(source, 0);
            if (f == 0) break;
            ans += f;
        }
        return ans;
    }
};
int node(string s) {
    if (s[0] >= 'A' && s[0] <= 'Z') {
        return s[0] - 'A';
    } else {
        return s[0] - 'a' + 26; //A~Z,a~z
    }
}
int main() {
    int m;
    cin >> m;
    MaximumFlow mf(52, 0, 'Z'-'A');
    for (int i=0; i<m; i++) {
        string us, vs;
        int f;
        cin >> us >> vs >> f;
        int u = node(us);
        int v = node(vs);
        mf.add_edge(u,v,f);
        mf.add_edge(v,u,f);
    }
    cout << mf.flow() << '\n';
    return 0;
}