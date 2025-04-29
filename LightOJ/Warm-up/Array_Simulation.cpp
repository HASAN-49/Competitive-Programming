// Problem Link --> https://lightoj.com/problem/array-simulation

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  int n, q; cin >> n >> q;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int r = 0;
  while (q--) {
    char ch; cin >> ch;
    if (ch == 'S') {
      int d; cin >> d;
      for (int i = 0; i < n; i++) a[i] += d;
    }
    else if (ch == 'M') {
      int d; cin >> d;
      for (int i = 0; i < n; i++) a[i] *= d;
    }
    else if (ch == 'D') {
      int k; cin >> k;
      for (int i = 0; i < n; i++) a[i] /= k;
    }
    else if (ch == 'P') {
      int x, y; cin >> x >> y;
      if (r == 1) swap(a[n - 1 - x], a[n - 1 - y]);
      else swap(a[x], a[y]);
    }
    else r ^= 1;
  }
  if (r == 1) reverse(a, a + n);
  cout << "Case " << tc << ":\n";
  for (int i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << a[i];
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
