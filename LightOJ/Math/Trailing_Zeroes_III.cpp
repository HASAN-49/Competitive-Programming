// Problem Link --> https://lightoj.com/problem/trailing-zeroes-iii

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

int counter_function(int x) {
  int ans = 0;
  while (x) {
    x /= 5;
    ans += x;
  }
  return ans;
}

void solve(int tc) {
  int q; cin >> q;
  int l = 0, r = 5 * q;
  cout << "Case " << tc << ": ";
  while (l <= r) {
    int mid = (l + r) >> 1;
    int cnt = counter_function(mid);
    if (cnt == q) {
      cout << mid / 5 * 5 << '\n';
      return;
    }
    if (cnt <= q) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  cout << "impossible\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
