// بسم الله الرحمن الرحيم
// Solution of Codeforces 1866B (Battling with Numbers)
#include<bits/stdc++.h>
using namespace std ;

#define test int t; for(cin >> t; t; t--)
#define ll long long
#define ld long double

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define out(x) cout << x << endl
#define outs(x) cout << x << " "

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nline cout << "\n"

#define pi 3.14159265358979323846
#define M 1000000007

bool compare(string &a, string &b) {
    return a.size() < b.size();
}

void solve(int tt) 
{
    ll n;
    cin >> n;
    ll a[n], b[n];
    bool ok = false;
    map<ll, ll> mp1, mp2;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        mp1[a[i]] = b[i];
    }
    ll m;
    cin >> m;
    ll c[m], d[m];
    for(int i = 0; i < m; i++) {
        cin >> c[i];
        if(mp1[c[i]] == 0) ok = true;
    }
    for(int i = 0; i < m; i++) {
        cin >> d[i];
        mp2[c[i]] = d[i];
    }
    if(ok) {
        cout << "0\n";
        return;
    }
    ll ans = 1, cnt = n - m;
    ll mod = 998244353;
    for(int i = 0; i < n; i++) {
        if(mp1[a[i]] < mp2[a[i]]) {
            cout << "0\n";
            return;
        }
        if(mp1[a[i]] > mp2[a[i]]) {
            ans *= 2;
            ans %= mod;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // sieve();
    int k = 1;
    solve(k++);
    // cout << "HASAN\n";
    return 0;
}
