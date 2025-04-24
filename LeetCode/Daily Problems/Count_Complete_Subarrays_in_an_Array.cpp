// Problem Link --> https://leetcode.com/problems/count-complete-subarrays-in-an-array/?envType=daily-question&envId=2025-04-24

// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> se;
        for (auto x: nums) {
            se.insert(x);
        }
        int distinct_elements = se.size();
        se.clear();
        map<int, int> cnt;
        int ans = 0, n = nums.size();
        for (int i = 0, j = 0; i < n; i++) {
            se.insert(nums[i]);
            cnt[nums[i]]++;
            if (se.size() == distinct_elements) {
                while (cnt[nums[j]] >= 1) {
                    ans += n - i;
                    cnt[nums[j]]--;
                    j++;
                    if (cnt[nums[j - 1]] == 0) {
                        se.erase(nums[j - 1]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    vector<int> v = {1, 2, 3, 1, 2};
    int ans = solution.countCompleteSubarrays(v);
    cout << ans << '\n';

  return 0;
}
