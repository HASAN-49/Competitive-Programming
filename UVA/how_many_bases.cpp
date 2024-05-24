// Solution of uva problem 12216(how many bases?)

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for (cin >> t; t; t--)

const int N = 1e5 + 1, mod = 100000007;
vector<int> primes;
void sieve() {
    vector<bool> is_prime(N, false);
    for (int i = 2; i * i < N; i++) {
        if (!is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = true;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i < N; i += 2) {
        if (!is_prime[i]) primes.push_back(i);
    } 
}

int greater_or_equal(vector<int> e, int tz) {
    int ans = 1, n = e.size();
    for (int i = 0; i < n; i++) {
        ans = 1LL * ans * (e[i] / tz + 1) % mod;
    }
    return ans;
}

int equal(vector<int> e, int tz) {
    return (greater_or_equal(e, tz) - greater_or_equal(e, tz+1) + mod) % mod;
}

void solve(int tt) {
    int n, m, tz, cs = 0;
    while (cin >> n >> m >> tz && n > 0 && m > 0 && tz > 0) {
        vector<int> e;
        for (auto x: primes) {
            if (x * x > n) break;
            if (n%x) continue;
            int cnt = 0;
            while (n%x == 0) {
                cnt++;
                n /= x;
            }
            e.push_back(cnt * m);
        }
        if (n > 1) e.push_back(m);
        cout << "Case " << ++cs << ": ";
        cout << equal(e, tz) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    sieve();
    int k = 1;
    solve(k++);
    return 0;
}
