// Problem Link --> https://lightoj.com/problem/sum-of-factorials

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve(int tc) {
  long long n; cin >> n;
  long long f = 1, c = 1;
  while (f <= n / c) {
    f *= c;
    c++;
  }
  c--;
  vector<int> ans;
  while (n > 0 && c >= 0) {
    while (n < f && c) {
      f /= c;
      c--;
    }
    ans.push_back(c);
    n -= f;
    if (c) f /= c;
    c--;
  }
  cout << "Case " << tc << ": ";
  if (n > 0) {
    cout << "impossible\n";
    return;
  }
  sort(ans.begin(), ans.end());
  int m = ans.size();
  for (int i = 0; i < m; i++) {
    if (i) cout << '+';
    cout << ans[i] << '!';
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
