// Problem Link --> https://lightoj.com/problem/knights-on-chessboard

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

void solve(int tc) {
  int n, m; cin >> n >> m;
  cout << "Case " << tc << ": ";
  if (n == 1 || m == 1) {
    cout << max(n, m) << '\n';
    return;
  }
  else if (n == 2 || m == 2) {
    int ans = max(n, m);
    if (ans % 4 == 1 || ans % 4 == 3) ans++;
    else if (ans % 4 == 2) ans += 2;
    cout << ans << '\n';
    return;
  }
  int ans = n * m + 1;
  cout << ans / 2 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
