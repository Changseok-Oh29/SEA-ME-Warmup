class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n]; // index = node, element = adj, cost
        //make graph
        for(auto i : flights) {
            adj[i[0]].push_back({i[1], i[2]});
        }

        queue<pair<int, pair<int, int>>> q; // {stops, {node, dist}}
        q.push({0, {src, 0}}); // stops, node, dist(cost)
        vector<int> dist(n, 1e9); //initialize graph
        dist[src] = 0;

        while(!q.empty()) {
            auto i = q.front();
            q.pop();
            int stops = i.first;
            int node = i.second.first;
            int cost = i.second.second;

            if(stops > k) continue;
            for(auto iter: adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;

                if(cost + edW < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + edW;
                    q.push({stops+1, {adjNode, cost + edW}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
