#if 0
//# Ive attended the code.plus class (https://code.plus/)
# And I've referred it's codes
# And core parts can be come fully from the class.
// Fenwick Tree
#endif

#include <iostream>
using namespace std;
const int MAX = 1'000'000;
int prime[MAX];
int pn;
bool check[MAX+1];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i=2; i<= MAX; i++) {
        if (check[i] == false) {
            prime[pn++] = i;
            for (int j = i+i; j<= MAX; j+= i) {
                check[j] = true;
            }
        }
    }
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i=1; i<pn; i++) { // i:0 -> prime[0]=2 -> skip
            // check if the other one is prime
            if (check[n-prime[i]] == false) {
                cout << n << " = " << prime[i] << " + " << n-prime[i] << '\n';
                break; 
            }
        }
    }
    return 0;
}
