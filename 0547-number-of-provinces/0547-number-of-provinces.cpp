class DSU{
    vector<int> rank , parent;
    
    public :
    
    DSU(int n){
        rank.resize(n+1 , 0);
        parent.resize(n+1);
        for(int i = 0 ;i <= n ; i++){
            parent[i] = i ;
        }
    }
    
    int Find(int node){
        if(parent[node] == node){
            return node ;
        }
        return parent[node] = Find(parent[node]);
    }
    
    void Union(int u ,int v){
        int ult_pu = Find(u);
        int ult_pv = Find(v);
        
        if(ult_pv == ult_pu) return ;
        
        if(rank[ult_pu] < rank[ult_pv]){
            parent[ult_pu] = ult_pv;
        }
        else if(rank[ult_pu] > rank[ult_pv]){
            parent[ult_pv] = ult_pu;
        }
        else {
            parent[ult_pv] = ult_pu;
            rank[ult_pu] ++ ;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU ds(n);

        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j] == 1) ds.Union(i , j);
            }
        }

        int count = 0 ; 
        for(int i = 0 ; i < n ; i ++){
            if(ds.Find(i) == i){
                count++ ;
            }
        }

        return count ;


    }
};