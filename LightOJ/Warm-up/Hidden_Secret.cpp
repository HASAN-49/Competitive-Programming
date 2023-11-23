// Solution of LightOJ Problem Hidden Secret!
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
    string a, b;
    getline(cin >> ws, a);
    getline(cin >> ws, b);

    string aa = "", bb = "";
    int sz = a.length();
    
    for(int i = 0; i < sz; i++) {
        if(a[i] == ' ') continue;
        aa += tolower(a[i]);
    }
    sort(all(aa));
    
    sz = b.length();
    for(int i = 0; i < sz; i++) {
        if(b[i] == ' ') continue;
        bb += tolower(b[i]);
    }
    sort(all(bb));
    
    cout << "Case " << tt << ": ";
    if(aa == bb) cout << "Yes\n";
    else cout << "No\n";
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
