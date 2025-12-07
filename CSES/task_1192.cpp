// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 1005;
vector<int> g[N];
bool vis[N][N];
int n, m;
string s[N];

bool is_ok(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int i, int j) {
  vis[i][j] = true;
  for (int k = 0; k < 4; k++) {
    int x = i + dx[k];
    int y = j + dy[k];
    if (is_ok(x, y) && !vis[x][y] && s[x][y] == '.') {
      dfs(x, y);
    }
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j] && s[i][j] == '.') {
        ans++;
        dfs(i, j);
      }
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
