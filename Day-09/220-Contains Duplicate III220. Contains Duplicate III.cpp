//https://leetcode.com/problems/contains-duplicate-iii/description/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums,
                                       int indexDiff,
                                       int valueDiff) {

        set<long long> s;

        for (int i = 0; i < nums.size(); i++) {

            auto it = s.lower_bound((long long)nums[i] - valueDiff);

            if (it != s.end() && *it <= (long long)nums[i] + valueDiff)
                return true;

            s.insert(nums[i]);

            if (s.size() > indexDiff)
                s.erase(nums[i - indexDiff]);
        }

        return false;
    }
};

