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
    ll ans = 0;
    string s, ss;
    cin >> s >> ss;
    int sz = s.size(), szz = ss.size();
    string mxs, mns;
    if(sz < szz) {
        mxs = ss;
        mns = s;
    }
    else {
        mxs = s;
        mns = ss;
    }
    mns = string(abs(sz - szz), '0') + mns;
    for(int i = 0; i < sz; i++) {
        if(mxs[i] != mns[i]) {
            ans = abs(mxs[i] - mns[i]) + (max(sz, szz)-1-i) * 9;
            break;
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
