#include<bits/stdc++.h>
using namespace std;

const int N = 3030;
int n, m, a[N], b[N];
int dp[N][N];
vector<int> ans;

int lcs(int i, int j) {
  if (i >= n or j >= m) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  int ans = lcs(i + 1, j);
  ans = max(ans, lcs(i, j + 1));
  if (a[i] == b[j]) {
    ans = max(ans, lcs(i + 1, j + 1) + 1);
  }
  return dp[i][j] = ans;
}

void print(int i, int j) {
  if (i >= n or j >= m) return;
  if (a[i] == b[j]) {
    // cout << a[i] << ' ';
    ans.push_back(a[i]);
    print(i + 1, j + 1);
    return;
  }
  int x = lcs(i + 1, j);
  int y = lcs(i, j + 1);
  if (x >= y) {
    print(i + 1, j);
  }
  else {
    print(i, j + 1);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // cin >> a >> b;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  memset(dp, -1, sizeof dp);
  // cout << lcs(0, 0) << '\n';
  print(0, 0);
  cout << ans.size() << '\n';
  for (auto x: ans) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}
// https://cses.fi/problemset/task/3403/
