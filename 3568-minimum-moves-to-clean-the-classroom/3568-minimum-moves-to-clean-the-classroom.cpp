class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        vector<pair<int,int>> litter;
        int sr, sc;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S')
                    sr = i, sc = j;
                else if (classroom[i][j] == 'L')
                    litter.push_back({i, j});
            }
        }
        int k = litter.size();
        int full = (1 << k) - 1;
        queue<tuple<int,int,int,int,int>> q;
        q.push({sr, sc, 0, energy, 0});
        vector<vector<vector<int>>> vis(
            m, vector<vector<int>>(n, vector<int>(1 << k, -1))
        );
        vis[sr][sc][0] = energy;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [r, c, mask, e, moves] = q.front();
            q.pop();
            if (mask == full)
                return moves;
            if (e == 0)
                continue;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                if (classroom[nr][nc] == 'X')
                    continue;
                int ne = e - 1;
                int nmask = mask;
                for (int i = 0; i < k; i++) {
                    if (litter[i].first == nr && litter[i].second == nc)
                        nmask |= (1 << i);
                }
                if (classroom[nr][nc] == 'R')
                    ne = energy;
                if (ne > vis[nr][nc][nmask]) {
                    vis[nr][nc][nmask] = ne;
                    q.push({nr, nc, nmask, ne, moves + 1});
                }
            }
        }
        return -1;
    }
};