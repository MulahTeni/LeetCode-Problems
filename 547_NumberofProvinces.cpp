class Solution {
public:
    void dfs(vector<vector<int>>& graph, int k, vector<bool>& visited){
        int n = graph.size();
        visited[k]=true;
        for(int i=0; i<n; ++i){
            if(graph[k][i] == 1 && !visited[i]){
                dfs(graph, i, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count=0;
        for(int i=0; i<n; ++i){
            if(!visited[i]){
                ++count;
                dfs(isConnected, i, visited);
            }
        }
        return count;
    }
};