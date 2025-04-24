// Problem Link --> https://lightoj.com/problem/neighbor-house

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define ll long long
#define ull unsigned long long
#define ld long double

#define all(a) a.begin(), a.end() 
#define allr(a) a.rbegin(), a.rend()
#define out(x) cout << x << endl
#define outs(x) cout << x << " "

#define yes cout << "Yes\n"
#define no cout << "No\n"
#define endl '\n'
#define nline cout << '\n'

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

#define __lcm(a, b) ((a / __gcd(a, b)) * b)
#define pi 3.14159265358979323846

const int mod = 1e9 + 7;
const int N = 105;
int n, w[N][3];
int dp[N][3];

int rec(int i, int pre) {
  if (i > n) return 0;
  int &ans = dp[i][pre];
  if (ans != -1) return ans;
  ans = INT_MAX;
  for (int k = 0; k < 3; k++) {
    if (k != pre) ans = min(ans, w[i][k] + rec(i + 1, k));
  }
  return ans;
}

void solve(int tc) {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> w[i][j];
    }
  }
  memset(dp, -1, sizeof dp);
  int ans = rec(1, -1);
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
