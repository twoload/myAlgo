#if 0
# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
#endif

#include <iostream>
using namespace std;


int a[10];
bool c[10];
void go(int index, int n, int m)
{
    if (index == m) {
        // print result
        //cout << "print: ";
        for(int i=0; i<m; i++) {
            cout << a[i];
            if (i != m-1) cout << " ";
        }
        cout << '\n';
    }
    for (int i= 1; i<=n; i++) {
        if (c[i]) continue;
        c[i] = true;
        a[index] = i;
        go(index+1, n, m);
        c[i] = false;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    go(0,n,m);
    return 0;
}