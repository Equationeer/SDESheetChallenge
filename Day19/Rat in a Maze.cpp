class Solution{
public:
    
    void solve(int row, int col,vector<vector<int>>& grid,vector<vector<int>>& vis, string path,vector<string>& ans,
               int n) {
        
        if(row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

        vis[row][col] = 1;
        if(row + 1 < n &&
           grid[row + 1][col] == 1 &&
           !vis[row + 1][col]) {
            
            solve(row + 1, col, grid, vis,
                  path + 'D', ans, n);
        }
        if(col - 1 >= 0 &&
           grid[row][col - 1] == 1 &&
           !vis[row][col - 1]) {
            
            solve(row, col - 1, grid, vis,
                  path + 'L', ans, n);
        }
        if(col + 1 < n &&
           grid[row][col + 1] == 1 &&
           !vis[row][col + 1]) {
            
            solve(row, col + 1, grid, vis,
                  path + 'R', ans, n);
        }

        if(row - 1 >= 0 &&
           grid[row - 1][col] == 1 &&
           !vis[row - 1][col]) {
            
            solve(row - 1, col, grid, vis,
                  path + 'U', ans, n);
        }

        vis[row][col] = 0; 
    }

    vector<string> findPath(vector<vector<int> > &grid) {
        //your code goes here
        int n = grid.size();
        vector<string> ans;

        if(grid[0][0] == 0)
            return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        solve(0, 0, grid, vis, "", ans, n);

        return ans;
    }
};