class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> dist(n , vector<int>(n , INT_MAX));
        dist[0][0] = 1 ;

        priority_queue<pair<int , pair<int , int>> , 
                    vector<pair<int , pair<int ,int>>> ,
                    greater<pair<int , pair<int , int>>>
                    > pq ;

        pq.push({1 , {0 , 0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(dis > dist[row][col]) continue ;

            for(int dr = -1 ; dr <= 1 ; dr++){
                for(int dc = -1 ; dc <=1 ; dc++){
                    int nrow = row + dr ;
                    int ncol = col + dc ;
                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol < n &&
                        grid[nrow][ncol] == 0 && (dis + 1) < dist[nrow][ncol])
                        {
                            dist[nrow][ncol] = dis + 1 ;
                            pq.push({dis+1 ,{nrow , ncol}});
                        }
                }
            }
        }
        if(dist[n-1][n-1] == INT_MAX) return -1 ;
        return dist[n-1][n-1];

    }
};