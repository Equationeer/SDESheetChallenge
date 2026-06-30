class Solution{	
	public:
		string longestCommonPrefix(vector<string>& str){
			//your code goes here
            if (str.empty()) return "";

        string prefix = str[0];

        for (int i = 1; i < str.size(); i++) {
            int j = 0;

            while (j < prefix.size() && j < str[i].size() &&prefix[j] == str[i][j]) {
                j++;
            }

            prefix = prefix.substr(0, j);

            if (prefix.empty())
                return "";
        }

        return prefix;
		}
};