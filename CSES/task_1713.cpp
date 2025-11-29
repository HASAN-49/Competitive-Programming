// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

void solve() {
  int n; cin >> n;
  int ans = 1;
  for (int i = 2; 1LL * i * i <= n; i++) {
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      cnt++;
    }
    ans *= (cnt + 1);
  }
  if (n > 1) ans *= 2;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  test 
  solve();

  return 0;
}
