class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> adj(n , vector<int>(n , INT_MAX));

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u][v] = w ;
            adj[v][u] = w ;
        }

        for(int i = 0 ;i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == j) adj[i][j] = 0 ;
            }
        }

        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(adj[i][k] == INT_MAX || adj[k][j] == INT_MAX){
                        continue ;
                    }
                    else adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
                }
            }
        }
        int num = 0 ;
        int count = INT_MAX;
        for(int i = 0 ; i < n ; i ++){
            int cnt = 0 ;
            for(int j = 0 ; j < n ; j++){
                if(i != j && adj[i][j] <= distanceThreshold ){
                    cnt ++;
                }
            }
            if(cnt <= count){
                num = i ;
                count = cnt ;
            }
        }

        return num ;

    }
};