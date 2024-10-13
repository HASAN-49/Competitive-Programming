// بسم الله الرحمن الرحيم
// Problem Link --> https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2092

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

const int N = 1005;
string s;
int dp[N][N];

int rec(int l, int r) {
    if (l > r) return 0;
    if (l == r) return 1;
    int &ans = dp[l][r];
    if (ans != -1) return ans;
    ans = 0;
    if (s[l] == s[r]) {
        ans = 2 + rec(l + 1, r - 1);
    }
    else {
        ans = max(rec(l + 1, r), rec(l, r - 1));
    }
    return ans;
}

void solve(int tc) {
    int t; cin >> t; cin.ignore();
    while (t--) {
        getline(cin, s);
        int n = s.size();
        // memset(dp, -1, sizeof dp);
        // int ans = rec(0, n-1);
        // cout << ans << '\n';
        memset(dp, 0, sizeof dp);
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                int &ans = dp[l][r];
                if (l == r) {
                    ans = 1;
                }
                else if (s[l] == s[r]) {
                    ans = 2 + dp[l+1][r-1];
                }
                else {
                    ans = max(dp[l+1][r], dp[l][r-1]);
                }
            }
        }
        cout << dp[0][n-1] << '\n';
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
