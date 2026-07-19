class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> grid = mat;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n , vector<int>(m , 0));
        vector<vector<int>> result(n , vector<int>(m));

        queue<pair<pair<int , int> , int>> q ;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0){
                    q.push({{i , j} , 0});
                    vis[i][j] = 1;
                    result[i][j] = 0 ;
                }
            }
        }

        int delrow[4] = {-1 , 0 , 1 , 0};
        int delcol[4] = {0 , -1 , 0 , 1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 ){
                        vis[nrow][ncol] = 1;
                        q.push({{nrow , ncol} , dist+1});
                        result[nrow][ncol] = dist + 1 ;
                    }
            }
        }

        return result ;


    }
};