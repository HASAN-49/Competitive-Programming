// Problem Link --> https://leetcode.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> f(n + 1, false);
        for (int i = 2; i * i <= n; i++) {
            if (!f[i]) {
                for (int j = i * i; j <= n; j += i) {
                    f[j] = true;
                }
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (!f[i]) cnt++;
        }
        return cnt;
    }
};
