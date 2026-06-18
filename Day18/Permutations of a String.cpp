class Solution {
public:
    void solve(string &s, vector<int> &used, string &curr,vector<string> &ans) {
        if (curr.size() == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

            used[i] = 1;
            curr.push_back(s[i]);

            solve(s, used, curr, ans);

            curr.pop_back();
            used[i] = 0;
        }
    }
    vector<string> permuteUnique(string s) {
        sort(s.begin(), s.end());

        vector<string> ans;
        vector<int> used(s.size(), 0);
        string curr = "";

        solve(s, used, curr, ans);

        return ans;
    }
};