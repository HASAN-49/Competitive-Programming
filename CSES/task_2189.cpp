// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve() {
  long long x0, x1, x2, y0, y1, y2;
  cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

  long long k = x0 * y1 + x1 * y2 + x2 * y0 - x1 * y0 - x2 * y1 - x0 * y2;
  // cout << k << '\n';

  // if area > 0, then the point will be at the left side
  if (k > 0) cout << "LEFT\n";
  // if area < 0, then the point will be at the right side
  else if (k < 0) cout << "RIGHT\n";
  // if area = 0, then every point will be on same line
  else cout << "TOUCH\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  test
  solve();

  return 0;
}
