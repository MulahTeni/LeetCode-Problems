class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int stepC = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<array<int, 3>> q;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==2) q.push({i, j, 0});
            }
        }
        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        bool found=false;
        while(!q.empty()){
            auto [k, l, step] = q.front();
            stepC = max(stepC, step);
            q.pop();
            for(auto& [i, j] : dirs){
                int currRow = k + i;
                int currCol = l + j;
                if(currCol>=0 && currCol<m && currRow>=0 && currRow<n){
                    if(grid[currRow][currCol]==1){
                        grid[currRow][currCol]=2;
                        found = true;
                        q.push({currRow, currCol, step+1});
                    }
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1) return -1;
            }
        }
        if(!found)  return 0;
        return stepC;
    }
};