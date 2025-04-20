// Problem Link => https://lightoj.com/problem/mathematically-hard

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define ll long long
#define ull unsigned long long
#define ld long double

#define all(a) a.begin(), a.end() 
#define allr(a) a.rbegin(), a.rend()
#define out(x) cout << x << endl
#define outs(x) cout << x << " "

#define yes cout << "Yes\n"
#define no cout << "No\n"
#define endl '\n'
#define nline cout << '\n'

#define __lcm(a, b) ((a / __gcd(a, b)) * b)
#define pi 3.14159265358979323846
const int mod = 1e9 + 7;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 5e6 + 9;
int spf[N];
ull cnt[N];

void spf_with_counter_function() {
  for (int i = 1; i < N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }

  for (int i = 1; i < N; i++) {
    int x = i;
    ll res = i;
    while (x > 1) {
      int p = spf[x];
      while (x % p == 0) x /= p;
      res = res / p * (p - 1);
    }
    cnt[i] = cnt[i - 1] + res * res;
  }
  // cout << cnt[N - 1] << '\n';
}

void solve(int tc) {
  int l, r; cin >> l >> r;  
  cout << "Case " << tc << ": ";
  cout << cnt[r] - cnt[l - 1] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  spf_with_counter_function();
  test 
  solve(k++);

  return 0;
}
