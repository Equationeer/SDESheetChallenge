class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {

        int count1 = 0, count2 = 0;
        int candidate1 = -1, candidate2 = -1;
        for (int num : nums) {

            if (num == candidate1) {
                count1++;
            }
            else if (num == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;

        for (int num : nums) {
            if (num == candidate1)
                count1++;
            else if (num == candidate2)
                count2++;
        }

        vector<int> ans;

        int limit = nums.size() / 3;

        if (count1 > limit)
            ans.push_back(candidate1);

        if (count2 > limit)
            ans.push_back(candidate2);

        sort(ans.begin(), ans.end());

        return ans;
    }
};