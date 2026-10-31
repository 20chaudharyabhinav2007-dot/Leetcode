
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> d1(m, vector<long long>(n, 0));
        vector<vector<vector<int>>> d2(
            m, vector<vector<int>>(n, vector<int>(2, -2))
        );
        function<int(int, int, int)> solve = [&](int i, int j, int dir) -> int {
            if (i >= m || j >= n)
                return -1;
            if (grid[i][j] == 0)
                return i * n + j;
            if (d2[i][j][dir] != -2)
                return d2[i][j][dir];
            if (dir == 0)
                return d2[i][j][dir] = solve(i + 1, j, 1);
            else
                return d2[i][j][dir] = solve(i, j + 1, 0);
        };
        d1[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (d1[i][j] == 0 || grid[i][j] == 1)
                    continue;
                if (i == m - 1 && j == n - 1)
                    continue;
                int r = solve(i, j + 1, 0);
                int d = solve(i + 1, j, 1);

                if (r != -1) {
                    d1[r / n][r % n] =
                        (d1[r / n][r % n] + d1[i][j]) % MOD;
                }
                if (d != -1) {
                    d1[d / n][d % n] =
                        (d1[d / n][d % n] + d1[i][j]) % MOD;
                }
            }
        }
        return d1[m - 1][n - 1];
    }
};
