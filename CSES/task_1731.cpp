// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 5005;
vector<int> dp(N, 0);

struct Trie {
  struct Node {
    int next[26];
    bool flg;
    Node() {
      memset(next, -1, sizeof next);
      flg = false;
    }
  };

  vector<Node> trie;
  Trie() {
    trie.push_back(Node()); // root
  }

  void insert(const string &s) { // O(s.size())
    int n = 0; // current node
    for (auto ch: s) {
      int c = ch - 'a';
      if (trie[n].next[c] == -1) {
        trie[n].next[c] = trie.size();
        trie.push_back(Node());
      }
      n = trie[n].next[c];
    }
    trie[n].flg = true;
  }

  int count_ways(int start, string s) {
    int ways = 0, n = s.size(), node = 0;
    for (int i = start; i < n; i++) {
      if (trie[node].next[s[i] - 'a'] == -1) return ways;
      node = trie[node].next[s[i] - 'a'];
      if (trie[node].flg) ways = (dp[i + 1] + ways) % mod;
    }
    return ways;
  }
};

void solve() {
  string s; cin >> s;
  int n = s.size();

  Trie trie;
  int q; cin >> q;
  while (q--) {
    string t; cin >> t;
    trie.insert(t);
  }

  dp[n] = 1; // Base case
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = trie.count_ways(i, s);
    // cout << dp[i] << '\n';
  }

  cout << dp[0] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
