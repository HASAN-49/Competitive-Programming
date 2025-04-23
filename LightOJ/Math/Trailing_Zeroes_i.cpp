// Problem Link --> https://lightoj.com/problem/trailing-zeroes-i

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

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

#define __lcm(a, b) ((a / __gcd(a, b)) * b)
#define pi 3.14159265358979323846

const int N = 1e6 + 9;
bitset<N> f;
vector<int> primes;

void sieve() {
  // int n = N - 9;
  f[1] = true;
  for (int i = 2; i * i < N; i++) {
    if (!f[i]) {
      for (int j = i * i; j < N; j += i) {
        f[j] = true;
      }
    }
  }
  for (int i = 2; i < N; i++) {
    if (!f[i]) {
      primes.push_back(i);
    }
  }
}

long long fn(long long n) {
  long long ans = 1;
  for (auto p: primes) {
    if (p * p > n) break;
    int e = 0;
    while (n % p == 0) {
      e++;
      n /= p;
    }
    ans *= (e + 1);
  }
  if (n > 1) ans *= 2;
  return ans;
}

void solve(int tc) {
  long long n; cin >> n;
  long long ans = fn(n);
  cout << "Case " << tc << ": ";
  cout << ans - 1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  sieve();
  test 
  solve(k++);

  return 0;
}
