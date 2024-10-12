// بسم الله الرحمن الرحيم
// Problem Link --> https://lightoj.com/problem/neighbor-house-ii

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
int a[N], n, dp[N][2][2];

int f(int i, int last_element, int first_element) {
    if (i > n) return 0;
    int &ans = dp[i][last_element][first_element];
    if (ans != -1) return ans;
    ans = f(i + 1, 0, first_element);
    if (i == n) {
        if (!last_element && !first_element) {
            ans = max(ans, a[i] + f(i + 1, 1, first_element));
        }
    }
    else {
        if (!last_element) {
            ans = max(ans, a[i] + f(i + 1, 1, first_element));
        }
    }
    return ans;
}

void solve(int tc) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << "Case " << tc << ": ";
    memset(dp, -1, sizeof dp);
    int ans = f(2, 0, 0);
    ans = max(ans, a[1] + f(2, 1, 1));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
