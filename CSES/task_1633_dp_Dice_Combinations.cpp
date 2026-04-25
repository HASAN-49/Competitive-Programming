// Problem link --> https://cses.fi/problemset/task/1633

// بسم الله الرحمن الرحيم
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
const int M = 1e9 + 7;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 1e6 + 9;
int dp[N];

int rec(int n) {
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];
    int ans = 0;
    for (int i = 1; i <= min(n, 6); i++) {
        ans += rec(n - i);
        ans %= M;
    }
    return dp[n] = ans;
}

void solve(int tc) {
    int n; cin >> n;
    memset(dp, -1, sizeof dp);
    int ans = rec(n);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
