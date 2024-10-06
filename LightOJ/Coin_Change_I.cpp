// بسم الله الرحمن الرحيم
// Problem Link --> https://lightoj.com/problem/coin-change-i

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
const int M = 100000007;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 55;
int a[N], c[N], n, dp[N][1005], k;

int f(int i, int sum) {
    if (sum > k) return 0;
    if (i == n) {
        if (sum == k) return 1;
        else return 0;
    }
    int &ans = dp[i][sum];
    if (ans != -1) return ans;
    ans = 0;
    for (int cnt = 0; cnt <= c[i]; cnt++) {
        ans += f(i + 1, sum + a[i] * cnt);
        ans %= M;
    }
    return ans;
}

void solve(int tc) {
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int cnt = c[0];
    int ans = f(0, 0);
    cout << "Case " << tc << ": ";
    cout << ans << '\n';
    // nline;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
