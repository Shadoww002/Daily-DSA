class Solution {
private:
    void dfs(int row , int col , vector<vector<int>>&grid , vector<vector<int>> &vis){
        vis[row][col] = 1;

        int dr[4] = {1 , 0 , -1 , 0};
        int dc[4] = {0 , 1 , 0 , -1};

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i<4 ; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n &&
                vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    dfs(nrow , ncol , grid , vis);
                }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m , vector<int>(n , 0));

        for(int i = 0 ; i < m ; i++){
            if(grid[i][0] == 1 && vis[i][0] == 0){
                dfs(i , 0 , grid , vis);
            }
            if(grid[i][n-1] == 1 && vis[i][n-1] == 0){
                dfs(i , n-1 , grid , vis);
            }
        }

        for(int j = 0 ; j < n ; j++){
            if(grid[0][j] == 1 && vis[0][j] == 0 ){
                dfs(0 , j , grid , vis);
            }
            if(grid[m-1][j] == 1 && vis[m-1][j] ==0 ){
                dfs(m-1 , j, grid , vis);
            }
        }

        int count = 0 ;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    count ++ ;
                }
            }
        }

        return count ;
    }
};