// Problem Link --> https://lightoj.com/problem/rooks

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
  long long n, k; cin >> n >> k;
  cout << "Case " << tc << ": ";
  if (k > n) {
    cout << "0\n";
    return;
  }
  unsigned long long ans = 1;
  for (int i = 0; i < k; i++) {
    ans *= (n - i) * (n - i);
    ans /= (i + 1);
  }
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
