// بسم الله الرحمن الرحيم
// Problem Link --> https://lightoj.com/problem/an-easy-lcs

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

const int N = 105;
string a, b;
int n, m;
bool vis[N][N];
string dp[N][N];

string f(int i, int j) {
    if (i == n || j == m) return "";
    if (vis[i][j]) return dp[i][j];
    string ans = "";
    if (a[i] == b[j]) {
        ans = string(1, a[i]) + f(i + 1, j + 1);
    }
    else {
        string x = f(i + 1, j);
        string y = f(i, j + 1);
        if (x.size() == y.size()) {
            ans = min(x, y);
        }
        else if (x.size() > y.size()) ans = x;
        else ans = y;
    }
    vis[i][j] = true;
    dp[i][j] = ans;
    // cout << i << ' ' << j << ' ' << ans << '\n';
    return ans;
}

void solve(int tc) {
    cin >> a >> b;
    n = a.size(), m = b.size();
    memset(vis, false, sizeof vis);
    string ans = f(0, 0);
    cout << "Case " << tc << ": ";
    if (ans.empty()) cout << ":(\n";
    else cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
