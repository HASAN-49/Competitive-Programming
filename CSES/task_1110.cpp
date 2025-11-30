//بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

const int N = 2e6 + 9;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;

int binPow(int a, int n, int mod) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1LL * res * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return res;
}

pair<int, int> pw[N], ipw[N];
void prec() { // O(n)
  pw[0].first = pw[0].second = 1;
  for (int i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i-1].first * p1 % mod1;
    pw[i].second = 1LL * pw[i-1].second * p2 % mod2;
  }

  int ip1 = binPow(p1, mod1 - 2, mod1);
  int ip2 = binPow(p2, mod2 - 2, mod2);
  ipw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1LL * ipw[i-1].first * ip1 % mod1;
    ipw[i].second = 1LL * ipw[i-1].second * ip2 % mod2;
  }
}

pair<int, int> string_hash(string s) { // O(n)
  int n = s.size();
  pair<int, int> hs({0, 0});
  for (int i = 0; i < n; i++) {
    hs.first += 1LL * pw[i].first * s[i] % mod1;
    hs.first %= mod1;
    hs.second += 1LL * pw[i].second * s[i] % mod2;
    hs.second %= mod2;
  }
  return hs;
}

pair<int, int> pre_hash[N];
void build(string s) { // O(n)
  int n = s.size();
  for (int i = 0; i < n; i++) {
    pre_hash[i].first = 1LL * pw[i].first * s[i] % mod1;
    if (i) pre_hash[i].first = (pre_hash[i-1].first + pre_hash[i].first) % mod1;
    pre_hash[i].second = 1LL * pw[i].second * s[i] % mod2;
    if (i) pre_hash[i].second = (pre_hash[i-1].second + pre_hash[i].second) % mod2;
  }
}

pair<int, int> get_hash(int i, int j) { // O(1)
  // assert(i <= j);

  pair<int, int> hs({0, 0});
  hs.first = pre_hash[j].first;
  if (i) hs.first = (hs.first - pre_hash[i-1].first + mod1) % mod1;
  hs.first = 1LL * hs.first * ipw[i].first % mod1;

  hs.second = pre_hash[j].second;
  if (i) hs.second = (hs.second - pre_hash[i-1].second + mod2) % mod2;
  hs.second = 1LL * hs.second * ipw[i].second % mod2;

  return hs;
}

// int n;
string s;

int lcp(int i, int j, int x, int y) {
  int len = 0, low = 1, high = j - i + 1;
  while (low <= high) {
    int mid = (low + high) >> 1;
    if (get_hash(i, i + mid - 1) == get_hash(x, x + mid - 1)) {
      len = mid;
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }
  return len;
}

bool cmp(int i, int j, int x, int y) {
  int len = lcp(i, j, x, y);
  int n = j - i + 1;
  if (len == n) return false;
  if (len == 0 && s[x] < s[i]) return false;
  if (len && s[x + len] < s[i + len]) return false;
  return true;
}

void solve(int tc) {
  // prec();

  cin >> s;
  int n = s.size();
  s += s;
  build(s);

  int ans_l = 0, ans_r = n - 1;
  for (int i = 0; i < n; i++) {
    bool k = cmp(i, i + n - 1, ans_l, ans_r);
    if (k) ans_l = i, ans_r = i + n - 1;
  }

  cout << s.substr(ans_l, n) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  prec();
  // test 
  solve(k++);

  return 0;
}
