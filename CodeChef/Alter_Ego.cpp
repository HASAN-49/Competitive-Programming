// بسم الله الرحمن الرحيم
// Solution of CodeChef problem Alter Ego
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
    ll a[n], odd = 0, even = 0;
    vector<ll> vo, ve;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i]%2) {
            odd++;
            vo.push_back(a[i]);
        }
        else {
            even++;
            ve.push_back(a[i]);
        }
    }
    if(odd%2 == 1 || even%2 == 1) {
        cout << "-1\n";
        return;
    }
    sort(all(vo));
    sort(all(ve));
    vector<ll> fv;
    int sz = odd / 2;
    for(int i = 0; i < sz; i++) {
        ll mx = max(vo[i], vo[sz+i]);
        ll x = (vo[i] + vo[sz+i]) / 2;
        cout << x << " ";
        fv.push_back(mx-x);
    }
    sz = even / 2;
    for(int i = 0; i < sz; i++) {
        ll mx = max(ve[i], ve[sz+i]);
        ll x = (ve[i] + ve[sz+i]) / 2;
        cout << x << " ";
        fv.push_back(mx-x);
    }
    for(int i = 0; i < fv.size(); i++) cout << fv[i] << " ";
    cout << endl;
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
