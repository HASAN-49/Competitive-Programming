// Problem Link --> https://lightoj.com/problem/coin-change-i

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int mod = 100000007, N = 55, M = 1005;
int n, a[N], c[N], K, dp[N][M];

int rec(int i, int weigth) {
  if (i == n) return weigth == 0;
  int &ans = dp[i][weigth];
  if (ans != -1) return ans;
  ans = 0;
  for (int cnt = 0; cnt <= c[i]; cnt++) {
    if (weigth - a[i] * cnt >= 0) {
      ans += rec(i + 1, weigth - a[i] * cnt);\
      ans %= mod;
    }
  }
  return ans;
}

void solve(int tc) {
  cin >> n >> K;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < n; j++) {
    cin >> c[j];
  }
  memset(dp, -1, sizeof dp);
  int ans = rec(0, K);
  cout << "Case " << tc << ": ";
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
