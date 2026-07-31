class DSU {
    vector<int> parent, size;

public:
    DSU(int num) {
        parent.resize(num + 1);
        size.resize(num + 1, 1);

        for (int i = 0; i <= num; i++) {
            parent[i] = i;
        }
    }

    int findUltParent(int n) {
        if (parent[n] == n) {
            return n;
        }
        return parent[n] = findUltParent(parent[n]);
    }

    void UnionBySize(int u, int v) {
        int ult_pu = findUltParent(u);
        int ult_pv = findUltParent(v);
        if (ult_pu == ult_pv)
            return;

        int size_pu = size[ult_pu];
        int size_pv = size[ult_pv];

        if (size_pu < size_pv) {
            parent[ult_pu] = ult_pv;
            size[ult_pv] += size[ult_pu];
        }

        else {
            parent[ult_pv] = ult_pu;
            size[ult_pu] += size[ult_pv];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        int mrow = 0 ;
        int mcol = 0 ;
        for(auto it : stones){
            mrow = max(mrow , it[0]);
            mcol = max(mcol , it[1]);
        }

        DSU ds(mrow + mcol+1);
        unordered_map<int , int> mp ;

        for(auto it : stones){
            int rowNode = it[0];
            int colNode = it[1] + mrow + 1;

            ds.UnionBySize(rowNode , colNode);
            mp[rowNode] = 1 ;
            mp[colNode] = 1;
        }
        int count = 0;
        for (auto it : mp) {
            if (ds.findUltParent(it.first) == it.first) {
                count++;
            }
        }
        return n - count;
    }
};