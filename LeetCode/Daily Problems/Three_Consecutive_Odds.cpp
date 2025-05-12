// Problem Link --> https://leetcode.com/problems/three-consecutive-odds/?envType=daily-question&envId=2025-05-12

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int i = 2; i < n; i++) {
            if ((arr[i - 2] & 1) && (arr[i - 1] & 1) && (arr[i] & 1)) return true;
        }
        return false;
    }
};
