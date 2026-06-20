class Solution {
public:
    int power(int base, int N, int M) {
        long long ans = 1;

        for (int i = 0; i < N; i++) {
            ans *= base;

            if (ans > M)
                return 2; 
        }

        if (ans == M)
            return 1;

        return 0; 
    }

    int NthRoot(int N, int M) {
        int low = 1, high = M;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int val = power(mid, N, M);

            if (val == 1)
                return mid;
            else if (val == 0)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};