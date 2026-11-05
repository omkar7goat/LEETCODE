class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Result matrix initialized with -1 to serve as the 'visited' tracker
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        
        // Step 1: Multi-source initialization
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int delr[4] = {-1, 1, 0, 0};
        int delc[4] = {0, 0, -1, 1};
        
        // Step 2: Single BFS traversal
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int nr = r + delr[k];
                int nc = c + delc[k];
                
                // If within bounds and not yet visited
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc}); // Marked visited immediately upon push
                }
            }
        }
        
        return dist;
    }
};