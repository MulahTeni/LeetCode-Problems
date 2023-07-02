class Solution {
public:
    int res=0;
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj){
        for(auto& [child, sign] : adj[node]){
            if(child!=parent){
                res += sign;
                dfs(child, node, adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& con : connections){
            adj[con[0]].push_back({con[1], 1});
            adj[con[1]].push_back({con[0], 0});
        }
        dfs(0, -1, adj);
        return res;
    }
};
/*
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> canVisit(n, false);
        canVisit[0]=true;
        int edgeCount = connections.size();
        int res = 0;
        for(int i=0; i<edgeCount; ++i){
            if(canVisit[connections[i][1]]){
                canVisit[connections[i][0]] = true;
            }else if(!canVisit[connections[i][1]]){
                canVisit[connections[i][1]] = true;
                res++;
            }
        }
        return res;
    }
*/