// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for (cin >> t; t; t--)

const int N = 1e5 + 1;
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

int power(int x, int e, int mod) {
    int res = 1;
    while (e > 0) {
        if (e%2) {
            res = 1LL * res * x % mod;
            e--;
        }
        else {
            x = 1LL * x * x % mod;
            e /= 2;
        }
    }
    return res;
}

void solve(int tt) {
    int n, p; cin >> n >> p;
    int tmp = n, e = 0;
    while (tmp > 1) {
        tmp /= 2;
        e += tmp;
    }
    cout << "Case " << tt << ": ";
    if (e < p) {
        cout << "-1\n";
        return;
    }
    int b = 1, mod = 10000019;
    for (auto x: primes) {
        if (x > n) break;
        tmp = n;
        int e = 0;
        while (tmp > 1) {
            tmp /= x;
            e += tmp;
        }
        e /= p;
        if (e == 0) break;
        b = 1LL * b * power(x, e, mod) % mod;
    }
    cout << b << '\n';
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
