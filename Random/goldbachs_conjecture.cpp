// Goldbach’s conjecture is one of the oldest and best-known unsolved problems in the number theory of 
// mathematics. Every even integer greater than 2 can be expressed as the sum of two primes.

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

void solve(int tt) {
    int n; cin >> n;
    if (n <= 2 || n%2 == 1) cout << "-1\n";
    for (auto x: primes) {
        if (!is_prime[n-x]) {
            cout << x << ' ' << n-x << '\n';
            return;
        }
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
    test solve(k++);
    return 0;
}
