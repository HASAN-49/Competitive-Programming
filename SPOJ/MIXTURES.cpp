// بسم الله الرحمن الرحيم
// Problem Link --> https://www.spoj.com/problems/MIXTURES/en/

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
const int mod = 100;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 105, inf = 1e9 + 9;
int a[N], pre_sum[N];
int dp[N][N];

int f(int l, int r) {
    if (l == r) return 0;
    int &ans = dp[l][r];
    if (ans != -1) return ans;
    ans = inf;
    for (int i = l; i < r; i++) {
        int aa = (pre_sum[i] - pre_sum[l-1]) % 100;
        int bb = (pre_sum[r] - pre_sum[i]) % 100;
        int cost = aa * bb;
        ans = min(ans, cost + f(l, i) + f(i + 1, r));
    }
    return ans;
}

void solve(int tc) {
    int n; 
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre_sum[i] = pre_sum[i-1] + a[i];
        }

        // Recursive Solution
        // memset(dp, -1, sizeof dp);
        // cout << f(1, n) << '\n';


        // Iterative Sotution
        for (int len = 1; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                int &ans = dp[l][r];
                if (l == r) {
                    ans = 0;
                }
                else {
                    ans = inf;
                    for (int i = l; i < r; i++) {
                        int aa = (pre_sum[i] - pre_sum[l-1]) % 100;
                        int bb = (pre_sum[r] - pre_sum[i]) % 100;
                        int cost = aa * bb;
                        ans = min(ans, cost + dp[l][i] + dp[i + 1][r]);
                    }
                }
            }
        }
        cout << dp[1][n] << '\n';
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
