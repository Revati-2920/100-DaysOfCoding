// https://leetcode.com/problems/smallest-missing-multiple-of-k/?envType=daily-question&envId=2026-08-25

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_set<int> seen(nums.begin(), nums.end());

        int multiple = k;

        while (seen.count(multiple)) {
            multiple += k;
        }

        return multiple;
    }
};
