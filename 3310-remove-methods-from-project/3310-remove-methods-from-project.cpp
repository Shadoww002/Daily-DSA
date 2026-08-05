class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto vec : invocations) {
            adj[vec[0]].push_back(vec[1]);
        }

        vector<int> vis(n, 0);
        vis[k] = 1;
        queue<int> q;
        q.push(k);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (vis[it] == 0) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }

        
        for (auto vec : invocations) {
            int u = vec[0];
            int v = vec[1];
            if (vis[u] == 0 && vis[v] == 1) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};