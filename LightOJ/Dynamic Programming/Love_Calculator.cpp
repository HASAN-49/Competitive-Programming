// Problem Link --> https://lightoj.com/problem/love-calculator

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 35;
int n, m, dp[N][N];
long long dp1[N][N];
string s, t;

int length(int i, int j) {
  if (i == n) return m - j;
  if (j == m) return n - i;
  if (dp[i][j] != -1) return dp[i][j];
  if (s[i] == t[j]) return dp[i][j] = 1 + length(i + 1, j + 1);
  return dp[i][j] = min(length(i + 1, j), length(i, j + 1)) + 1;
}

long long unique_strings(int i, int j) {
  if (i == n || j == m) return 1;
  long long &ans = dp1[i][j];
  if (ans != -1) return ans;
  if (s[i] == t[j]) return ans = unique_strings(i + 1, j + 1);
  int ln1 = length(i + 1, j);
  int ln2 = length(i, j + 1);
  if (ln1 == ln2) return ans = unique_strings(i + 1, j) + unique_strings(i, j + 1);
  if (ln1 < ln2) return ans = unique_strings(i + 1, j);
  return ans = unique_strings(i, j + 1);
}

void solve(int tc) {
  cin >> s >> t;
  n = s.size(), m = t.size();
  memset(dp, -1, sizeof dp);
  memset(dp1, -1, sizeof dp1);
  cout << "Case " << tc << ": ";
  cout << length(0, 0) << ' ' << unique_strings(0, 0) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
