// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1091

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int parent[N];

int find(int idx) {
  if (idx < 0) return -1;
  if (parent[idx] == idx) return idx;
  return parent[idx] = find(parent[idx]);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  // Using DSU concept
  for (int i = 0; i <= n; i++) {
    parent[i] = i;
  }

  while (m--) {
    int x; cin >> x;
    auto it = upper_bound(a.begin(), a.end(), x);
    if (it == a.begin()) cout << "-1\n";
    else {
      int idx = (it - a.begin()) - 1;
      idx = find(idx);
      if (idx < 0) cout << "-1\n";
      else {
        cout << a[idx] << '\n';
        parent[idx] = idx - 1;
      }
    }
  }

  // Bellow code getting TLE, becuase erase takes O(N) time complexity

  // while (m--) {
  //   int x; cin >> x;
  //   if (a.empty()) {
  //     cout << "-1\n";
  //     continue;
  //   }
  //   auto k = lower_bound(a.begin(), a.end(), x) - a.begin();
  //   if (k + a.begin() == a.end()) {
  //     if (k - 1 >= 0 && a[k - 1] <= x) {
  //       cout << a[k - 1] << '\n';
  //       a.erase(k - 1 + a.begin());
  //     }
  //     else cout << "-1\n";
  //   }
  //   else {
  //     if (a[k] > x) k--;
  //     if (k < 0) cout << "-1\n";
  //     else {
  //       cout << a[k] << '\n';
  //       a.erase(k + a.begin());
  //     }
  //   }
  // }

  return 0;
}
