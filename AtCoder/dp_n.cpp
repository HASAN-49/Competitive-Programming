// بسم الله الرحمن الرحيم
// Problem Link --> https://atcoder.jp/contests/dp/tasks/dp_n?lang=en

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

const int N = 405;
const ll inf = LLONG_MAX;
int n, a[N];
long long dp[N][N], pre_sum[N];

ll f(int l, int r) {
    if (l == r) return 0;
    ll &ans = dp[l][r];
    if (ans != -1) return ans;
    ll current_cost = 0;
    for (int i = l; i <= r; i++) {
        current_cost += a[i];
    }
    ans = inf;
    for (int i = l; i < r; i++) {
        ans = min(ans, current_cost + f(l, i) + f(i + 1, r));
    }
    return ans;
}

void solve(int tc) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre_sum[i] = a[i] + pre_sum[i-1];
    }
    // memset(dp, -1, sizeof dp);
    // cout << f(1, n) << '\n';

    // Iteative Solution
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            ll &ans = dp[l][r];
            if (l == r) {
                ans = 0;
            }
            else {
                ll current_cost = pre_sum[r] - pre_sum[l-1];
                // for (int i = l; i <= r; i++) {
                //     current_cost += a[i];
                // }
                ans = inf;
                for (int i = l; i < r; i++) {
                    ans = min(ans, current_cost + dp[l][i] + dp[i + 1][r]);
                }
            }
        }
    }
    cout << dp[1][n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
