class Solution {
public:
    int myAtoi(string input) {
        // Your code goes here
         int n = input.size();
        int i = 0;

        while (i < n && input[i] == ' ')
            i++;
        int sign = 1;
        if (i < n && (input[i] == '+' || input[i] == '-')) {
            if (input[i] == '-')
                sign = -1;
            i++;
        }

        long long num = 0;

        while (i < n && isdigit(input[i])) {
            int digit = input[i] - '0';

            num = num * 10 + digit;

            if (sign == 1 && num > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -num < INT_MIN)
                return INT_MIN;

            i++;
        }

        return (int)(sign * num);
    }
};
