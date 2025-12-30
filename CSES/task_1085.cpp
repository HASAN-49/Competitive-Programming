// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;
 
vector<int> a;
int n, k;
 
int f(long long x) {
  int cnt = 1;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (sum + a[i] <= x) sum += a[i];
    else sum = a[i], cnt++;
  }
  return cnt;
}
 
void solve() {
  // return;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a.push_back(x);
  }
  long long low = *max_element(a.begin(), a.end()), high = 1e18, ans = low;
  while (low <= high) {
    long long mid = (low + high) >> 1;
    int cur = f(mid);
    if (cur > k) {
      low = mid + 1;
    }
    else {
      ans = mid;
      high = mid - 1;
    }
  }
  cout << ans << '\n';
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  solve();
 
  return 0;
}
