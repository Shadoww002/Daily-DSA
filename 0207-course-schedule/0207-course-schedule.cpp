class Solution {
private :
    bool dfs(int node , vector<vector<int>>&adj , vector<int>&vis , vector<int> &pathvis){
        vis[node] = 1 ;
        pathvis[node] = 1 ;
        for(auto it : adj[node]){
            if(vis[it] == 0){
                if(dfs(it , adj , vis , pathvis) == true) return true ;
            }

            else if(pathvis[it]) return true;
        }

        pathvis[node] = 0 ;
        return false ;
    }


public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses ;
        vector<vector<int>> adj(n);

        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        vector<int> vis(n , 0);
        vector<int> pathvis(n , 0);

        for(int i = 0 ; i < n ; i++){
            if(vis[i] == 0){
                if(dfs(i , adj , vis , pathvis) == true) return false ;
            }
        }
        return true ;
    }
};