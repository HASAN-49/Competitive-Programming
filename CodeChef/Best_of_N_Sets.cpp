#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int x, y;
	    cin >> x >> y;
	    x = max(x, y);
	    cout << x * 2 - 1 << endl;
	}
	return 0;
}
