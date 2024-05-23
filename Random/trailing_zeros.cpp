// Given an integer n, write a function that returns count of trailing zeroes in n!

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for (cin >> t; t; t--)

void solve(int tt) {
    int n, ans = 0; cin >> n;
    while (n >= 5) {
        ans += n / 5;
        n /= 5;
    }
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
