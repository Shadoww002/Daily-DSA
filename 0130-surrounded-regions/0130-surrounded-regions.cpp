class Solution {
private:
    void dfs(int row , int col , vector<vector<char>>&grid , vector<vector<int>> &vis){
        vis[row][col] = 1;

        int dr[4] = {1 , 0 , -1 , 0};
        int dc[4] = {0 , 1 , 0 , -1};

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i<4 ; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n &&
                vis[nrow][ncol] == 0 && grid[nrow][ncol] == 'O'){
                    dfs(nrow , ncol , grid , vis);
                }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m , vector<int>(n , 0));

        for(int i = 0 ; i < m ; i++){
            if(board[i][0] == 'O' && vis[i][0] == 0){
                dfs(i , 0 , board , vis);
            }
            if(board[i][n-1] == 'O' && vis[i][n-1] == 0){
                dfs(i , n-1 , board , vis);
            }
        }

        for(int j = 0 ; j < n ; j++){
            if(board[0][j] == 'O' && vis[0][j] == 0 ){
                dfs(0 , j , board , vis);
            }
            if(board[m-1][j] == 'O' && vis[m-1][j] ==0 ){
                dfs(m-1 , j, board , vis);
            }
        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};