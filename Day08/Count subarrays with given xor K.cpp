class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        unordered_map<int, int> mp;

        int xr = 0;
        int count = 0;
        mp[0] = 1;

        for (int num : nums) {
            xr ^= num;

            count += mp[xr ^ k];

            mp[xr]++;
        }
        return count;
    }
};