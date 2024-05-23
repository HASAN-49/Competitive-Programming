// Given a number n, count the total number of divisors of n!.

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for (cin >> t; t; t--)

const int N = 1e5 + 1;
bitset<N> is_prime;
vector<int> primes;
void sieve() {
    for (int i = 2; i * i < N; i++) {
        if (!is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = true;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (!is_prime[i]) primes.push_back(i);
    }
}

long long calculate(int n) {
    long long res = 1;
    for (auto x: primes) {
        if (x > n) break;
        int e = 0, m = n;
        while (m > 1) {
            m /= x;
            e += m;
        }
        // for (int i = x; i <= n; i += x) {
        //     int m = i;
        //     while (m > 1) {
        //         m /= x;
        //         e++;
        //     }
        // }
        res *= (e + 1);
    }
    return res;
}

void solve(int tt) {
    int n; cin >> n;
    long long ans = calculate(n);
    cout << ans << '\n';
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
    test solve(k++);
    return 0;
}
