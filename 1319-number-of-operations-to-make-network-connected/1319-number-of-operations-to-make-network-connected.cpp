class DSU{
    vector<int> parent , size ;
    public :
    DSU(int n){
        parent.resize(n);

        size.resize(n , 1);
        for(int i = 0 ; i <  n  ; i++){
            parent[i] = i ;
        }
    }

    int FindParent(int node){
        if(parent[node] == node){
            return node ;
        }
        return parent[node] = FindParent(parent[node]);
    }
    
    void UnionBySize(int u  , int v){
        int ult_pu = FindParent(u);
        int ult_pv = FindParent(v);

        if(ult_pu == ult_pv) return ;

        if(size[ult_pu] < size[ult_pv]){
            parent[ult_pu] = ult_pv ;
        }
        else if(size[ult_pu] > size[ult_pv]){
            parent[ult_pv] = ult_pu ;
        }
        else{
            parent[ult_pu] = ult_pv ;
            size[ult_pv] ++ ;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        for(auto vec : connections){
            ds.UnionBySize(vec[0] , vec[1]);
        }

        int count = 0 ; 
        for(int i = 0 ; i < n ; i++){
            if(ds.FindParent(i) == i){
                count++ ;
            }
        }

        int cables = connections.size();

        if(cables < n-1) return -1 ;
        return count - 1;

    }
};