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
    int n;
    cin >> n;
    ll a[n], mx = 0, mex;
    map<ll, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        mx = max(mx, a[i]);
    }
    for(int i = 0; i <= mx+1; i++) {
        if(mp[i] == 0) {
            mex = i;
            break;
        }
    }
    cout << mex << endl;
    ll y;
    cin >> y;
    while(y != -1) {
        cout << y << endl;
        cin >> y;
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
