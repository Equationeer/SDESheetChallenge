class Solution
{
public:
    int celebrity(vector<vector<int>> &M)
    {
        int n = M.size();

        int i = 0, j = n - 1;
        while (i < j)
        {
            if (M[i][j] == 1)
                i++;   
            else
                j--;    
        }

        int cand = i;

        for (int k = 0; k < n; k++)
        {
            if (k == cand)
                continue;

            if (M[cand][k] == 1 || M[k][cand] == 0)
                return -1;
        }

        return cand;
    }
};