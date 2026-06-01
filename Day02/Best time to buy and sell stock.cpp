class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int minPrice = arr[0];
        int maxProfit = 0;

        for(int i = 1; i < n; i++) {
            minPrice = min(minPrice, arr[i]);
            maxProfit = max(maxProfit, arr[i] - minPrice);
        }

        return maxProfit;
    }
};