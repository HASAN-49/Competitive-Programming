// بسم الله الرحمن الرحيم
// Solution of Codeforces Problem 1901B (Chip and Ribbon)
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
    ll a[n], tmp = 1, ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > tmp) {
            ans += a[i] - tmp;
            // tmp = a[i];
        }
        // if(a[i] == 0 && a[i-1] > 0) {
        //     ans++;
        //     // tmp = 1;
        // }
        tmp = a[i];
        // cout << ans << " ";
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
    test solve(k++);
    // cout << "HASAN\n";
    return 0;
}
