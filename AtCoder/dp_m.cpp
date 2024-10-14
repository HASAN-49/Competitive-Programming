// بسم الله الرحمن الرحيم
// Problem Link --> https://atcoder.jp/contests/dp/tasks/dp_m?lang=en

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

const int N = 105, M = 1e5 + 9;
int n, a[N], dp[N][M], pre_sum[N][M];

int f(int i, int sum) {
    if (sum == 0) return 1;
    if (i == n + 1) return 0;
    int &ans = dp[i][sum];
    if (ans != -1) return ans;
    ans = 0;
    for (int k = 0; k <= a[i]; k++) {
        if (sum >= k) {
            ans += f(i + 1, sum - k);
            ans %= mod;
        }
    }
    return ans;
}

void solve(int tc) {
    cin >> n;
    int sum; cin >> sum;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // memset(dp, -1, sizeof dp);
    // cout << f(1, sum) << '\n';
    // Complexity of recursive solution = N * M * M
    // We have to make iterative solution to optimize the Complexity

    for (int i = n + 1; i >= 1; i--) {
        for (int x = 0; x <= sum; x++) {
            int &ans = dp[i][x];
            if (i == n + 1) {
                if (x == 0) ans = 1;
                else ans = 0;
            }
            else {
                ans = 0;
                // for (int c = 0; c <= a[i]; c++) {
                //     if (x >= c) {
                //         ans += dp[i + 1][x - c];
                //         ans %= mod;
                //     }
                // }
                int l = max(0, x - a[i]);
                int r = x;
                ans = (pre_sum[i+1][x] - ((l - 1 >= 0) ? pre_sum[i+1][l-1] : 0) + mod) % mod;
            }
            pre_sum[i][x] = ans;
            if (x) pre_sum[i][x] += pre_sum[i][x-1];
            pre_sum[i][x] %= mod;
        }
    }
    cout << dp[1][sum] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
