// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1639

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

const int N = 5005, inf = 1e9 + 9;
string a, b;
int n, m, dp[N][N];

int rec(int i, int j) {
    if (i == n && j == m) return 0;
    if (i == n) return m - j;
    if (j == m) return n - i;
    int &ans = dp[i][j];
    if (ans != -1) return ans;
    ans = inf;
    if (a[i] == b[j]) {
        ans = min(ans, rec(i + 1, j + 1));
    }
    ans = min(ans, 1 + rec(i, j + 1)); // for adding
    ans = min(ans, 1 + rec(i + 1, j)); // for removing
    ans = min(ans, 1 + rec(i + 1, j + 1)); // for replacing
    return ans;
}

void solve(int tc) {
    cin >> a >> b;
    n = a.size(), m = b.size();
    memset(dp, -1, sizeof dp);
    cout << rec(0, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
