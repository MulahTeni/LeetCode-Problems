class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = int(maze.size()), cols = int(maze[0].size());
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<array<int, 3>> q;     // i, j, depth
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';
        while (!q.empty()) {
            auto [currRow, currCol, currDist] = q.front();
            q.pop();
            if (currRow == 0 || currRow == rows - 1 || currCol == 0 || currCol == cols - 1)
                return currDist + 1;
            for(auto [dRow, dCol] : dirs){
                int nextRow = currRow + dRow, nextCol = currCol + dCol;
                if (0 <= nextRow && nextRow < rows && 0 <= nextCol && nextCol < cols && maze[nextRow][nextCol] == '.') {
                    maze[nextRow][nextCol] = '+';
                    q.push({nextRow, nextCol, currDist + 1});
                }
            }
        }
        return -1;
    }
};
