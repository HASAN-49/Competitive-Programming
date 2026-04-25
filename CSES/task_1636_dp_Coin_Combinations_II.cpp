// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1636

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

const int mod = 1e9 + 7, N = 105, M = 1e6 + 5;
int n, x, a[N], dp[N][M];

int rec(int i, int sum) {
  if (i == n) {
    if (sum == 0) return 1;
    else return 0;
  }
  int &ans = dp[i][sum];
  if (ans != -1) return ans;
  ans = rec(i + 1, sum);
  if (sum >= a[i]) ans += rec(i, sum - a[i]);
  ans %= mod;
  return ans;
}

void solve(int tc) {
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Getting TLE
  // memset(dp, -1, sizeof dp);
  // int ans = rec(0, x);
  // cout << ans << '\n';

  
  for (int i = n - 1; i >= 0; i--) {
    for (int sum = 0; sum <= x; sum++) {
      if (sum == 0) dp[i][sum] = 1;
      else {
        dp[i][sum] = dp[i + 1][sum];
        if (sum >= a[i]) dp[i][sum] += dp[i][sum - a[i]];
        dp[i][sum] %= mod;
      }
    }
  }
  cout << dp[0][x] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  // test 
  solve(k++);

  return 0;
}
