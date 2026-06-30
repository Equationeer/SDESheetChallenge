class Solution {
public:
    vector<int> search(string pat, string txt) {
        vector<int> ans;

        int n = txt.size();
        int m = pat.size();

        if (m > n) return ans;

        const int base = 256;
        const int mod = 1000000007;

        long long patHash = 0;
        long long txtHash = 0;
        long long power = 1;

        for (int i = 0; i < m - 1; i++)
            power = (power * base) % mod;

        for (int i = 0; i < m; i++) {
            patHash = (patHash * base + pat[i]) % mod;
            txtHash = (txtHash * base + txt[i]) % mod;
        }

        for (int i = 0; i <= n - m; i++) {
            if (patHash == txtHash) {
                if (txt.substr(i, m) == pat)
                    ans.push_back(i);
            }

            if (i < n - m) {
                txtHash = (txtHash - txt[i] * power % mod + mod) % mod;
                txtHash = (txtHash * base + txt[i + m]) % mod;
            }
        }

        return ans;
    }
};