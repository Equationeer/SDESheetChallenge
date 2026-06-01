class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        // Step 1: Find breakpoint
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // If no breakpoint exists
        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find next greater element
        for(int i = n - 1; i > ind; i--) {
            if(nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 3: Reverse remaining part
        reverse(nums.begin() + ind + 1, nums.end());
    }
};