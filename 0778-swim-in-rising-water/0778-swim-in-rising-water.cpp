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
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<pair<int,pair<int,int>>> cells;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cells.push_back({grid[i][j],{i,j}});

        sort(cells.begin(),cells.end());

        DSU ds(n*n);

        vector<vector<int>> active(n,vector<int>(n,0));

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(auto &it:cells){

            int water=it.first;
            int r=it.second.first;
            int c=it.second.second;

            active[r][c]=1;

            int node=r*n+c;

            for(int k=0;k<4;k++){

                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n && active[nr][nc]){

                    int adj=nr*n+nc;
                    ds.UnionBySize(node,adj);
                }
            }

            if(ds.findUltParent(0)==ds.findUltParent(n*n-1))
                return water;
        }

        return -1;
    }
};