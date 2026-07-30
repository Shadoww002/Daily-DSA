class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);

        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int FindParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = FindParent(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int ult_pu = FindParent(u);
        int ult_pv = FindParent(v);

        if (ult_pu == ult_pv)
            return;

        if (size[ult_pu] < size[ult_pv]) {
            parent[ult_pu] = ult_pv;
            size[ult_pv] += size[ult_pu];
        } else {
            parent[ult_pv] = ult_pu;
            size[ult_pu] += size[ult_pv];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                } else {
                    ds.UnionBySize(i, mp[mail]);
                }
            }
        }
        vector<vector<string>> merged(n);
        for (auto it : mp) {
            string mail = it.first;
            int node = ds.FindParent(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (merged[i].size() == 0)
                continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : merged[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};