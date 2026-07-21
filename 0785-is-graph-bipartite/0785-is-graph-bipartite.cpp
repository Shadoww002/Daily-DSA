class Solution {
private :
    bool dfs(int node , vector<vector<int>> &graph , vector<int> &vis , int color){
        vis[node] = color;

        for(auto it : graph[node]){
            if(vis[it] == -1){
                if(dfs(it , graph , vis , !color) == false) return false ;
            }
            else if(vis[it] == vis[node]){
                return false ;
            }

        }

        return true ; 
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, -1);

        int color = 0 ;
        for(int i = 0 ; i<n ; i++){
            if(vis[i] == -1){
                if(dfs(i , graph , vis , color) == false) return false ;
            }
        }

        return true ;
    }
};