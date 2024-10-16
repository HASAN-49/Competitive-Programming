// بسم الله الرحمن الرحيم
// Problem Link --> https://lightoj.com/problem/coin-change-ii

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
const int mod = 100000007;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 105, K = 10005;
int n, k, a[N], dp[N][K];

int f(int i, int s) {
    if (i == 0) return s == 0;
    int &ans = dp[i][s];
    if (ans != -1) return ans;
    ans = f(i - 1, s);
    // for (int j = 1; j <= k; j++) {
    //     if (s >= a[i] * j) {
    //         ans += f(i - 1, s - a[i] * j);
    //         ans %= mod;
    //     }
    //     else break;
    // }
    if (s >= a[i]) {
        ans += f(i, s - a[i]);
        if (ans >= mod) ans -= mod;
    }
    return ans;
}

void solve(int tc) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << "Case " << tc << ": ";
    // Recursive solution gives TLE
    // memset(dp, -1, sizeof dp);
    // cout << f(n, k) << '\n';

    for (int i = 0; i <= n; i++) {
        for (int s = 0; s <= k; s++) {
            int &ans = dp[i][s];
            if (i == 0) {
                ans = s == 0;
            }
            else {
                ans = dp[i - 1][s];
                if (s >= a[i]) {
                    ans += dp[i][s - a[i]];
                    if (ans >= mod) ans -= mod;
                }
            }
        }
    }
    cout << dp[n][k] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
