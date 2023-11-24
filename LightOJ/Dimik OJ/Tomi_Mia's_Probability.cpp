// بسم الله الرحمن الرحيم
// Solution of LightOJ problem Tomi Mia's Probability
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

long long func(long long n) {
    if(n <= 1) return 1;
    return n*func(n-1);
}

void solve(int tt) 
{
    string s;
    getline(cin >> ws, s);
    int ln = s.length(), n = 1;
    // cout << ln << endl;
    string w = "";
    map<string, int> mp;
    for(int i = 0; i < ln; i++) {
        if(s[i] == ' ' && w.size() > 0) {
            mp[w] += 1;
            w = "";
            n++;
        }
        else {
            w += s[i];
        }
    }
    if(w.size() > 0) mp[w] += 1;
    else n--;
    long long ans = 1;
    for(auto it : mp) {
        ans *= func(it.second);
    }
    ans = func(n) / ans;
    cout << "1/" << ans << endl;
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
