// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1093

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

#define pi 3.14159265358979323846
const int mod = 1e9 + 7;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

ll f2(int, int);

const int N = 505, M = 125255;
int n, MX, dp[N][M];

int binPow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return res;
}

int f(int i, int s) {
    if (i == n + 1) return s == 0;
    int &ans = dp[i][s];
    if (ans != -1) return ans;
    ans = f(i + 1, s);
    if (s >= i) {
        ans += f(i + 1, s - i);
        ans %= mod;
    }
    return ans;
}

int rec(int i, int s) {
    if (i == 0) return s == 0;
    int &ans = dp[i][s];
    if (ans != -1) return ans;
    ans = rec(i - 1, s);
    if (s >= i) {
        ans += rec(i - 1, s - i);
        ans %= mod;
    }
    return ans;
}

void solve(int tc) {
    cin >> n;
    MX = n * (n + 1) / 2;
    if (MX % 2) {
        cout << "0\n";
    }
    else {
        memset(dp, -1, sizeof dp);
        // cout << 1LL * f(1, MX / 2) * binPow(2, mod - 2) % mod << '\n';

        cout << 1LL * rec(n, MX / 2) * binPow(2, mod - 2) % mod << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
