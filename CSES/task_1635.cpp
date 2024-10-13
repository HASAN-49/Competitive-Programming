// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1635

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
#define Mm 998244353
const int mod = 1e9 + 7;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 105, X = 1e6 + 9;
int n, a[N], dp[X];

int rec(int sum) {
    if (sum == 0) return 1;
    if (sum < 0) return 0;
    int &ans = dp[sum];
    if (ans != -1) return ans;
    ans = 0;
    for (int k = 1; k <= n; k++) {
        ans += rec(sum - a[k]);
        ans %= mod;
    }
    return ans;
}

void solve(int tc) {
    cin >> n;
    int sum; cin >> sum;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Recursive Solution
    // memset(dp, -1, sizeof dp);
    // int ans = rec(sum);
    // cout << ans << '\n';

    // Iterative Solution
    dp[0] = 1;
    for (int s = 1; s <= sum; s++) {
        int &ans = dp[s];
        ans = 0;
        for (int i = 1; i <= n; i++) {
            if (s < a[i]) continue;
            ans += dp[s - a[i]];
            if (ans >= mod) ans -= mod;
        }
    }
    cout << dp[sum] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
