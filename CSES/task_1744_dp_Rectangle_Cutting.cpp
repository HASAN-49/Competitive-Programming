// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 9, N = 505;
int dp[N][N];

void solve() {
  int a, b; cin >> a >> b;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      int &ans = dp[i][j];
      if (i == j) {
        ans = 0;
        continue;
      }
      ans = inf;
      for (int k = 1; k < i; k++) {
        ans = min(ans, dp[k][j] + dp[i - k][j] + 1);
      }
      for (int k = 1; k < j; k++) {
        ans = min(ans, dp[i][k] + dp[i][j - k] + 1);
      }
    }
  }
  cout << dp[a][b] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
