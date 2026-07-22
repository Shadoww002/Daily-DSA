class Solution {
private:
    void bfs(int n , vector<vector<int>>& graph, vector<int>& indegree , vector<int> &topo) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] ==0 ) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto it : graph[node]) {
                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> rev(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                rev[it].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> topo;
        bfs( n ,rev , indegree , topo);

        sort(topo.begin() , topo.end());
        return topo ;
    }
};