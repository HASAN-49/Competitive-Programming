// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve() {
  int n; cin >> n;
  vector<pair<long long, long long>> points(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> points[i].first >> points[i].second;
  }
  points[n] = points[0];
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += points[i].first * points[i + 1].second;
    ans -= points[i].second * points[i + 1].first;
  }
  cout << abs(ans) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // test
  solve();

  return 0;
}
