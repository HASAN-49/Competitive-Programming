// Problem Link --> https://lightoj.com/problem/parallelogram-counting

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  int n; cin >> n;
  int x[n], y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<pair<double, double>> vp;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      vp.push_back({(x[i] + x[j]) / 2.0, (y[i] + y[j]) / 2.0});
    }
  }
  sort(vp.begin(), vp.end());
  n = vp.size();
  int cnt = 1, ans = 0;
  for (int i = 1; i < n; i++) {
    if (vp[i] == vp[i - 1]) cnt++;
    else {
      ans += cnt * (cnt - 1) / 2;
      cnt = 1;
    }
  }
  ans += cnt * (cnt - 1) / 2;
  cout << "Case " << tc << ": " << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}
