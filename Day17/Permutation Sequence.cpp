class Solution {
public:
    string getPermutation(int n, int k) {
        // Your code goes here
          vector<int> numbers;
        int fact = 1;

        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        k--; 

        string ans = "";

        while (true) {
            ans += to_string(numbers[k / fact]);

            numbers.erase(numbers.begin() + (k / fact));

            if (numbers.empty())
                break;

            k %= fact;
            fact /= numbers.size();
        }
        return ans;
    }
};