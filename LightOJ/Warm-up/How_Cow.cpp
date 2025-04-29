// Problem Link --> https://lightoj.com/problem/how-cow

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
  int q; cin >> q;
  cout << "Case " << tc << ":\n";
  while (q--) {
    int x, y; cin >> x >> y;
    if (x >= x1 && x <= x2 && y >= y1 && y <= y2) cout << "Yes\n";
    else cout << "No\n";
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
