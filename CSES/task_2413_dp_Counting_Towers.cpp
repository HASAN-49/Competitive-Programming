// بسم الله الرحمن الرحيم
// https://cses.fi/problemset/task/2413

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6, mod = 1e9 + 7;
int dp[N + 1][2];

void pre_calculate() {
  dp[N][0] = dp[N][1] = 1;
  for (int i = N - 1; i >= 1; i--) {
    dp[i][0] = (2LL * dp[i + 1][0] % mod + dp[i + 1][1]) % mod;
    dp[i][1] = (4LL * dp[i + 1][1] % mod + dp[i + 1][0]) % mod;
  }
}

void solve() {
  int n; cin >> n;
  // dp[n][0] = dp[n][1] = 1;
  // for (int i = n - 1; i >= 1; i--) {
  //   dp[i][0] = (2LL * dp[i + 1][0] % mod + dp[i + 1][1]) % mod;
  //   dp[i][1] = (4LL * dp[i + 1][1] % mod + dp[i + 1][0]) % mod;
  // }
  n = N - n + 1;
  cout << (dp[n][0] + dp[n][1]) % mod << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pre_calculate();
  int t; cin >> t;
  while (t--) solve();

  return 0;
}
