// Problem Link --> https://lightoj.com/problem/hex-a-bonacci

#include <bits/stdc++.h>
using namespace std;

const int mod = 10000007, N = 10005;
int dp[N];
int a, b, c, d, e, f;

int fn(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    int &ans = dp[n];
    if (ans != -1) return ans;
    ans = fn(n - 1) % mod;
    ans = (ans + fn(n - 2)) % mod;
    ans = (ans + fn(n - 3)) % mod;
    ans = (ans + fn(n - 4)) % mod;
    ans = (ans + fn(n - 5)) % mod;
    ans = (ans + fn(n - 6)) % mod;
    return ans;
}

void solve(int cs) {
    memset(dp, -1, sizeof dp);
    int n;
    cin >> a >> b >> c >> d >> e >> f >> n;
    cout << "Case " << cs << ": ";
    cout << fn(n) % mod << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1, t; cin >> t;
  while (t--) solve(k++);

  return 0;
}
