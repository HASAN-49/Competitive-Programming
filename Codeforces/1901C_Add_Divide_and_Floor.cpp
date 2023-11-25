// بسم الله الرحمن الرحيم
// Solution of Codeforces Problem 1901C (Add, Divide and Floor)
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
    ll n;
    cin >> n;
    ll a[n], mn = INT_MAX, mx = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    ll tmp = mn;
    mn = mx - mn;
    while(mn > 0) {
        mn /= 2;
        ans++;
    }
    mn = tmp;
    cout << ans << endl;
    if(ans <= n) {
        for(int i = 0; i < ans-1; i++) {
            cout << mx + 1 << " ";
        }
        if(ans > 0) {
            cout << mx + 1 << "\n";
        }
    }
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
