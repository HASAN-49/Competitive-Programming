// بسم الله الرحمن الرحيم
// Problem link --> https://codeforces.com/contest/2033/problem/D

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
    int n;
    cin >> n;

    int a[n+1];
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll pre[n+1];
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    map<ll, int> mp;
    int ans[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            ans[i] = ans[i - 1] + 1;
        }
        else if (mp[pre[i]] || pre[i] == 0) {
            ans[i] = max(ans[mp[pre[i]]] + 1, ans[i - 1]);
        }
        else {
            ans[i] = ans[i - 1];
        }
        mp[pre[i]] = i;
    }

    cout << ans[n] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
