// بسم الله الرحمن الرحيم
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
#define MOD 1000000007

void solve(int tt) 
{
    ll n, ans = 0;
    cin >> n;
    ll a[n], cnt = 0, pre[n] = {0};
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n-1; i++) {
        if(a[i] > a[i-1] && a[i] > a[i+1]) {
            cnt++;
            i++;
        }
    }
    if(cnt == (n-1) / 2) {
        cout << "0\n";
        return;
    }
    if(n%2) {
        for(int i = 1; i < n-1; i += 2) {
            ll x = max(a[i-1], a[i+1]);
            ll y = x - a[i] + 1;
            if(y > 0) ans += y;
        }
        cout << ans << endl;
        return;
    }
    for(int i = 1; i < n-1; i += 2) {
        ll x = max(a[i-1], a[i+1]);
        ll y = x - a[i] + 1;
        if(y > 0) ans += y;
        pre[i] = ans;
    }
    ll sum = 0;
    for(int i = n-2; i > 0; i -= 2) {
        ll x = max(a[i-1], a[i+1]);
        ll y = x - a[i] + 1;
        if(y > 0) sum += y;
        int j = i - 3;
        if(j > 0) {
            ans = min(ans, sum+pre[j]);
        }
    }
    ans = min(ans, sum);
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
    test solve(k++);
    // cout << "HASAN\n";
    return 0;
}
