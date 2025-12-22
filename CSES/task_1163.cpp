// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << v[i];
  }
  cout << '\n';
}

void solve() {
  int x; cin >> x;
  int n; cin >> n;
  vector<int> a(n), b;
  b.push_back(0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b.push_back(a[i]);
  }
  b.push_back(x);
  sort(b.begin(), b.end());
  // print(b);
  map<int, pair<int, int>> mp;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    mp[b[i]] = {b[i - 1], b[i + 1]};
    mx = max(b[i + 1] - b[i], mx);
    mx = max(b[i] - b[i - 1], mx);
  }
  vector<int> ans(n);
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = mx;
    int next = mp[a[i]].second;
    int pre = mp[a[i]].first;
    mx = max(mx, next - pre);
    // cout << pre << ' ' << a[i] << ' ' << next << " mx=" << mx << '\n';
    mp[next].first = pre;
    mp[pre].second = next;
  }
  print(ans);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
