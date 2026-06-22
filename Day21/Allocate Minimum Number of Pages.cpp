class Solution {
public:

    bool canAllocate(vector<int>& nums, int m, int maxPages) {
        int students = 1;
        long long pages = 0;

        for (int book : nums) {

            if (pages + book <= maxPages) {
                pages += book;
            }
            else {
                students++;
                pages = book;

                if (students > m)
                    return false;
            }
        }

        return true;
    }

    int findPages(vector<int>& nums, int m) {

        int n = nums.size();

        if (m > n)
            return -1;

        int low = *max_element(nums.begin(), nums.end());

        long long high = 0;
        for (int x : nums)
            high += x;

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canAllocate(nums, m, mid)) {
                ans = mid;
                high = mid - 1;    
            }
            else {
                low = mid + 1;      
            }
        }

        return ans;
    }
};