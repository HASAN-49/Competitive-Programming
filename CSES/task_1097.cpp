// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1097

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

ll f2(int, int);

const int N = 5005;
ll inf = 1e9, dp1[N][N], dp2[N][N];
bool vis1[N][N], vis2[N][N];
int n, a[N];

ll f1(int l, int r) {
    if (l > r) return 0;
    if (vis1[l][r]) return dp1[l][r];
    ll left = a[l] + f2(l + 1, r);
    ll right = a[r] + f2(l, r - 1);
    vis1[l][r] = true;
    return dp1[l][r] = max(left, right);
}

ll f2(int l, int r) {
    if (l > r) return 0;
    if (vis2[l][r]) return dp2[l][r];
    ll left = f1(l + 1, r);
    ll right = f1(l, r - 1);
    vis2[l][r] = true;
    return dp2[l][r] = min(left, right);
}

void solve(int tc) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << f1(1, n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
