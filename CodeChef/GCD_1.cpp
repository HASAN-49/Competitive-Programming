// بسم الله الرحمن الرحيم
// Problem Link --> https://www.codechef.com/problems/GCD_1

#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define ll long long
#define ull unsigned long long
#define ld long double

#define all(a) a.begin(), a.end() 
#define allr(a) a.rbegin(), a.rend()
#define out(x) cout << x << endl
#define outs(x) cout << x << " "

#define yes cout << "Yes\n"
#define no cout << "No\n"
#define endl '\n'
#define nline cout << '\n'

#define pi 3.14159265358979323846
#define Mm 998244353
const int M = 1e9 + 7;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 3e5 + 9;
vector<int> p;
bool check[N];

void f() {
    for (int i = 2; i < N; i++) {
        if (!check[i]) {
            for (int j = i * i; j < N; j += i) {
                check[j] = true;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (!check[i]) {
            p.push_back(i);
        }
    }
}

void solve(int tc) {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i%2) {
                if (j%2) cout << "2 ";
                else cout << "3 ";
            }
            else {
                if (j%2) cout << "3 ";
                else cout << "2 ";
            }
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    test 
    solve(k++);

    return 0;
}
