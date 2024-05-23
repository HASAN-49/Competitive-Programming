// Given an integer n and a prime number p, find the largest x such that p^x (p raised to power x) divides n! (factorial) 

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for (cin >> t; t; t--)

int calculate(int n, int p) {
    int res = 0;
    while (n > 1) {
        n /= p;
        res += n;
    }
    return res;
}

void solve(int tt) {
    int n, p; cin >> n >> p;
    long long ans = calculate(n, p);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int k = 1;
    test solve(k++);
    return 0;
}
