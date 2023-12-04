class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for(int i=0; i<n; ++i){
            string start = equations[i][0];
            string end = equations[i][1];
            double val = values[i];

            adj[start].push_back({end, val});
            adj[end].push_back({start, (double)1/val});

        }

        vector<double> res;
        for(auto q : queries){
            unordered_set<string> visited;
            res.push_back(dfs(q[0], q[1], visited));
        }
        return res;
    }
    double dfs(string start, string end, unordered_set<string> &visited) {
        if(adj.find(start)==adj.end())    return -1;
        if(start == end)    return 1;
        for(auto n : adj[start]){
            if(visited.count(n.first))  continue;
            visited.insert(n.first);
            double res = dfs(n.first, end, visited);
            if(res != -1)   return res*n.second;
        }
        return -1;
    }
};