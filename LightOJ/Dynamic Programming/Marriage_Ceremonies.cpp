// Problem Link --> https://lightoj.com/problem/marriage-ceremonies

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

const int mod = 1e9 + 7, N = 20;
int n, a[N][N], dp[N][1 << N];

int rec(int i, int mask) {
  if (i == n) return 0;
  int &ans = dp[i][mask];
  if (ans != -1) return ans;
  ans = 0;
  for (int j = 0; j < n; j++) {
    if ((1 << j) & mask) {
      mask ^= (1 << j);
      ans = max(ans, a[i][j] + rec(i + 1, mask));
      mask ^= (1 << j);
    }
  }
  return ans;
}

void solve(int tc) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  memset(dp, -1, sizeof dp);
  int ans = rec(0, (1 << n) - 1);
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
