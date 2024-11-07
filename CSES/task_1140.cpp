// بسم الله الرحمن الرحيم
// Problem Link --> https://cses.fi/problemset/task/1140

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

const int N = 2e5 + 5;
ll dp[N], pre[N];
struct seg{
    int l, r, reward;
}a[N];

bool cmp (seg x, seg y) {
    return x.r < y.r;
}

void solve(int tc) {
    int n; cin >> n;
    // cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].reward;
    }
    sort (a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        dp[i] = a[i].reward;

        ll mx = 0; // We can find mx using segment tree
        // for (int j = i - 1; j >= 1; j--) {
        //     if (a[j].r < a[i].l) {
        //         mx = max(mx, dp[j]);
        //     }
        // }

        int L = 1, R = i - 1, j = 0;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (a[mid].r < a[i].l) {
                j = mid;
                L = mid + 1;
            }
            else {
                R = mid - 1;
            }
        }
        mx = pre[j];

        dp[i] = max(dp[i], mx + a[i].reward);
        pre[i] = max(dp[i], pre[i-1]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
