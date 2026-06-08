class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {
        unordered_map<long long, int> mp;

        long long prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            if (prefixSum == k) {
                maxLen = i + 1;
            }

            if (mp.find(prefixSum - k) != mp.end()) {
                int len = i - mp[prefixSum - k];
                maxLen = max(maxLen, len);
            }
            if (mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }

        return maxLen;
    }
};