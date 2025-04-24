// Problem Link --> https://lightoj.com/problem/monkey-banana-problem

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 205, M = 105;
int n, a[N][M], dp[N][M];

int rec(int i, int j) {
  if (i == 2 * n - 1) return a[i][j];
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  int k = i;
  if (k >= n) ans = a[i][j] + max(rec(i + 1, j), rec(i + 1, j - 1));
  else ans = a[i][j] + max(rec(i + 1, j), rec(i + 1, j + 1));
  return ans;
}

void solve(int tc) {
  cin >> n;
  for (int i = 1, k = n - 1; i <= 2 * n - 1; i++) {
    if (i <= n) {
      for (int j = 1; j <= i; j++) {
        cin >> a[i][j];
      }
    }
    else {
      for (int j = 1; j <= k; j++) {
        cin >> a[i][j];
      }
      k--;
    }
  }
  memset(dp, -1, sizeof dp);
  int ans = rec(1, 1);
  cout << "Case " << tc << ": ";
  cout << ans << '\n';
  for (int i = 1, k = n - 1; i <= 2 * n - 1; i++) {
    if (i <= n) {
      for (int j = 1; j <= i; j++) {
        a[i][j] = 0;
      }
    }
    else {
      for (int j = 1; j <= k; j++) {
        a[i][j] = 0;
      }
      k--;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
