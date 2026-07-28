class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int , int>>> adj(n +1);

        for(auto vec : times){
            int u = vec[0];
            int v = vec[1];
            int t = vec[2];

            adj[u].push_back({v , t});
        }

        vector<int> dist(n+1 , INT_MAX);
        dist[k] = 0 ;

        queue<pair<int , int>> q ;
        q.push({0 , k});

        while(!q.empty()){
            int node = q.front().second ;
            int time = q.front().first ;
            q.pop();

            if(time > dist[node]) continue ;
            for(auto it : adj[node]){
                int newNode = it.first ;
                int newTime = it.second ;

                if(time + newTime < dist[newNode]){
                    dist[newNode] = time + newTime ;
                    q.push({dist[newNode] , newNode});
                }
            }
        }

        int ans = INT_MIN;

        for(int i = 1 ; i <= n ; i++){
            int num = dist[i];
            if(num == INT_MAX) return -1 ;
            else if (num > ans) ans = num;
        }
        return ans ;
    }
};