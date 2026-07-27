class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int , int>>> adj(n);
        for(auto vec : flights){
            int u = vec[0];
            int v = vec[1];
            int c = vec[2];

            adj[u].push_back({v , c});
        }
        // {cost , {k , node}}
        queue<pair<int , pair<int , int>>> pq ;

        pq.push({0 , {0 , src}});
        vector<int> prices(n , INT_MAX);
        prices[src] = 0 ;

        int ans = INT_MAX ;

        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();

            int currCost = it.first ;
            int stop = it.second.first ;
            int node = it.second.second ;

            if(stop > k + 1) continue ;
            
            if(node == dst && stop <= k+1){
                ans = min(ans , currCost);
            }

            for(auto it : adj[node]){
                int next = it.first ;
                int cost = it.second ;
                int newStop = stop + 1 ;
                if(currCost + cost < prices[next] && newStop <= k+1){
                    prices[next] = currCost + cost ;
                    pq.push({prices[next] , {newStop, next}});
                }
            }
        }
        if(ans == INT_MAX) return -1 ;
        return ans ;

    }
};