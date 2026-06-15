class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        // Your code goes here
         vector<pair<double, int>> items;
        int n = val.size();

        for(int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, i});
        }

        sort(items.rbegin(), items.rend());

        double totalValue = 0.0;

        for(auto &item : items) {
            int index = item.second;

            if(capacity >= wt[index]) {
                totalValue += val[index];
                capacity -= wt[index];
            }
            else {
                totalValue += ((double)capacity * val[index]) / wt[index];
                break;
            }
        }

        return totalValue;
    }
};