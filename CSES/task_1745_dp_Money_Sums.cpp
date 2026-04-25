// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1745

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

const int N = 105, M = 1005;
int n, a[N], vis[N][N * M], dp[N][N * M];

bool f(int i, int s) {
    if (i == n + 1) return s == 0;
    if (vis[i][s]) return dp[i][s];
    bool is_ok = f(i + 1, s);
    if (s >= a[i]) is_ok |= f(i + 1, s - a[i]);
    vis[i][s] = true;
    return dp[i][s] = is_ok;
}

void solve(int tc) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    for (int i = 1; i < N * M; i++) {
        if (f(1, i)) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto x: ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
