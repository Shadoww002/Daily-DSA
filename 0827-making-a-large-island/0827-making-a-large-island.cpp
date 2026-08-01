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
    int getSize(int n) { return size[n]; }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DSU ds(n * n);

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};

        vector<vector<int>> vis(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int row = i;
                int col = j;

                int node = row * n + col;

                if (vis[row][col] == 0 && grid[row][col] == 1) {
                    vis[row][col] = 1;

                    for (int delta = 0; delta < 4; delta++) {
                        int nr = row + dr[delta];
                        int nc = col + dc[delta];

                        if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                            vis[nr][nc] == 1 && grid[nr][nc] == 1) {
                            int newNode = nr * n + nc;

                            if (ds.findUltParent(newNode) !=
                                ds.findUltParent(node)) {
                                ds.UnionBySize(newNode, node);
                            }
                        }
                    }
                }
            }
        }

        int maxArea = 0;
        for (int i = 0; i < n * n; i++) {
            maxArea = max(maxArea, ds.getSize(i));
        }
        unordered_set<int>st ;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int row = i;
                int col = j;

                int node = row * n + col;
                if (vis[row][col] == 0 && grid[row][col] == 0) {
                    vis[row][col] = 1;

                    for (int delta = 0; delta < 4; delta++) {
                        int nr = row + dr[delta];
                        int nc = col + dc[delta];

                        if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                            vis[nr][nc] == 1 && grid[nr][nc] == 1)
                        {
                            int newNode = nr * n + nc;
                            st.insert(ds.findUltParent(newNode));
                        }
                    }
                }
                int area = ds.getSize(node);
                for(int x : st){
                    area += ds.getSize(x);
                }
                st.clear();
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};