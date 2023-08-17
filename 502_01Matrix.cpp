/*
542. 01 Matrix
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.



Example 1:

Input: mat = [[0,0,0],
              [0,1,0],
              [0,0,0]]
Output: [[0,0,0],
         [0,1,0],
         [0,0,0]]

Example 2:

Input: mat = [[0,0,0],
              [0,1,0],
              [1,1,1]]
Output: [[0,0,0],
         [0,1,0],
         [1,2,1]]
*/

// Solution

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<array<int, 3>> q;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(mat[i][j] == 0)  q.push({i, j, 0});
            }
        }

        while(!q.empty()){
            auto [row, col, depth] = q.front();
            ++depth;
            q.pop();

            for(auto [dRow, dCol]: dirs){
                int nextRow = row + dRow;
                int nextCol = col + dCol;

                if(0 <= nextRow && 0 <= nextCol && nextCol < m && nextRow < n && mat[nextRow][nextCol] == 1 && res[nextRow][nextCol] == 0){
                    q.push({nextRow, nextCol, depth});
                    res[nextRow][nextCol] = depth;
                }
            }
        }
        return res;
    }
};
