// بسم الله الرحمن الرحيم
// Problem Link --> https://atcoder.jp/contests/dp/tasks/dp_i?lang=en

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
const int mod = 1e9 + 7;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 3005;
int n;
double p[N], dp[N][N];
bool is_visited[N][N];

double f(int i, int head, int tail) {
    if (i == n + 1) {
        if (head > tail) return 1;
        return 0;
    }
    if (is_visited[i][head]) return dp[i][head];
    double ans = p[i] * f(i + 1, head + 1, tail);
    ans += (1.0 - p[i]) * f(i + 1, head, tail + 1);
    is_visited[i][head] = true;
    dp[i][head] = ans;
    return ans;
}

void solve(int tc) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cout << fixed << setprecision(10) << f(1, 0, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
