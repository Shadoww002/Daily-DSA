class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<long long, long long>>> adj(n) ;
        long long mod = 1e9 + 7 ;
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int t = it[2];

            adj[u].push_back({v , t});
            adj[v].push_back({u , t});
        }
        // {time , node}
        priority_queue<pair<long long , long long> , vector<pair<long long , long long>> , greater<pair<long long,long long>>> q ;
        q.push({0 , 0});

        vector<long long> dist(n , LONG_MAX) , ways(n , 0);
        dist[0] = 0 ;
        ways[0] = 1 ;
        
        while(!q.empty()){
            auto it = q.top();
            q.pop();

            long long node = it.second ;
            long long currTime = it.first ;

            if(currTime > dist[node]) continue ;

            for(auto pair : adj[node]){
                int adjNode = pair.first ;
                int adjTime = pair.second ;

                if( currTime + adjTime < dist[adjNode]){
                    dist[adjNode] = currTime + adjTime ;
                    q.push({dist[adjNode] , adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (currTime + adjTime == dist[adjNode]){
                    ways[adjNode] =(ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];

    }
};