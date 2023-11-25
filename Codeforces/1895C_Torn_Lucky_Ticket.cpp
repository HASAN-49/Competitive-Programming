// بسم الله الرحمن الرحيم
// Solution of Codeforces 1895C (Torn Lucky Ticket)
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

bool compare(string &a, string &b) {
    return a.size() < b.size();
}

void solve(int tt) 
{
    ll n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(all(s), compare);
    map<pair<ll, ll>, ll> mp;
    ll ans = n;
    for(int i = 0; i < n; i++) {
        // cout << s[i] << " ";
        ll sz = s[i].size();
        for(int j = 1; j <= sz; j++) {
            if((sz+j)%2) continue;
            ll mid = (sz + j) / 2;
            ll sum = 0;
            for(int k = 0; k < mid; k++) sum += s[i][k] - '0';
            for(int k = mid; k < sz; k++) sum -= s[i][k] - '0';
            if(sum >= 0) ans += mp[{j, sum}];
        }
        reverse(all(s[i]));
        for(int j = 1; j <= sz; j++) {
            if((sz+j)%2) continue;
            ll mid = (sz + j) / 2;
            ll sum = 0;
            for(int k = 0; k < mid; k++) sum += s[i][k] - '0';
            for(int k = mid; k < sz; k++) sum -= s[i][k] - '0';
            if(sum >= 0) ans += mp[{j, sum}];
        }
        ll sum = 0;
        for(int k = 0; k < sz; k++) sum += s[i][k] - '0';
        mp[{sz, sum}] += 1;
    }
    cout << ans << endl;
    // nline;
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
