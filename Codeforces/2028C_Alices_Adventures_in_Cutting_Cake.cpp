// بسم الله الرحمن الرحيم
// Problem link --> https://codeforces.com/contest/2028/problem/C

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

void solve(int tc) {
    int n, m; ll v; 
    cin >> n >> m >> v;

    int a[n+1];
    long long pref[n+1];
    a[0] = pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }

    int l[m+1], r[m+1], j = 0;
    l[0] = 0, r[0] = n;
    for (int i = 1; i <= m; i++) {
        while (j <= n && pref[j] - pref[l[i-1]] < v) {
            j++;
        }
        l[i] = j;
    }
    for (int i = 1, j = n; i <= m; i++) {
        while (j >= 0 && pref[r[i-1]] - pref[j] < v) {
            j--;
        }
        r[i] = j;
    }

    long long ans = -1;
    for (int i = 0; i <= m; i++) {
        if (l[i] > r[m-i] || r[m-i] > n || l[i] < 0) continue;
        long long tmp = pref[r[m-i]] - pref[l[i]];
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
