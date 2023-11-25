// بسم الله الرحمن الرحيم
// Solution of Codeforces Problem 1860C (Game on Permutation)
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

void solve(int tt) 
{
    ll n;
    cin >> n;
    ll a[n];
    vector<ll> v;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0) v.push_back(a[i]);
        if(a[i] < v.back()) v.push_back(a[i]);
    }
    reverse(all(v));
    ll ans = 0, mn = INT_MAX;
    for(int i = 0; i < n; i++) {
        while(a[i] == v.back() && i < n) {
            v.pop_back();
            i++;
        }
        if(i == n) break;
        if(a[i] < mn) mn = a[i];
        if(a[i] <= mn) {
            ans++;
            mn = a[i];
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
    test solve(k++);
    // cout << "HASAN\n";
    return 0;
}
