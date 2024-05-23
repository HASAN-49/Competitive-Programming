// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for (cin >> t; t; t--)

void solve(int tt) {
    long long int a, ans = 0; string b; cin >> a >> b; // 0 <= a <= 10^12 and 0 <= b <= 10^250
    int n = b.size();
    for (int i = 0; i < n; i++) {
        ans = ans * 10 + (b[i] - '0');
        ans %= a;
    }
    ans = __gcd(ans, a);
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
