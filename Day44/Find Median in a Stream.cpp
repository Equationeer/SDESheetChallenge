class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {

        priority_queue<int> left; 

        priority_queue<int, vector<int>, greater<int>> right; 

        vector<double> ans;

        for (int x : arr) {

            if (left.empty() || x <= left.top())
                left.push(x);
            else
                right.push(x);

            if (left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            }
            else if (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }

            if (left.size() == right.size()) {
                ans.push_back((left.top() + right.top()) / 2.0);
            } else {
                ans.push_back((double)left.top());
            }
        }

        return ans;
    }
};