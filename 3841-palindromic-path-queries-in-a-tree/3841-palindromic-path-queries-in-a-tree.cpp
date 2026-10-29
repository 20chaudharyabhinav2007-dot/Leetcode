class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> graph(n);
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int log = 1;
        while ((1 << log) <= n) log++;
        vector<vector<int>> parent(log, vector<int>(n));
        vector<int> level(n, 0), inTime(n), outTime(n);
        vector<int> order, par(n, -1);
        vector<int> st = {0};
        par[0] = 0;
        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            inTime[u] = order.size();
            order.push_back(u);
            for (int v : graph[u]) {
                if (v == par[u]) continue;
                par[v] = u;
                level[v] = level[u] + 1;
                st.push_back(v);
            }
        }
        vector<int> size(n, 1);
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            size[par[u]] += size[u];
        }
        for (int u = 0; u < n; u++) {
            outTime[u] = inTime[u] + size[u] - 1;
            parent[0][u] = par[u];
        }
        for (int j = 1; j < log; j++) {
            for (int u = 0; u < n; u++) {
                parent[j][u] = parent[j - 1][parent[j - 1][u]];
            }
        }
        auto findLCA = [&](int u, int v) {
            if (level[u] < level[v]) swap(u, v);
            int diff = level[u] - level[v];
            for (int j = 0; j < log; j++) {
                if (diff & (1 << j)) {
                    u = parent[j][u];
                }
            }
            if (u == v) return u;
            for (int j = log - 1; j >= 0; j--) {
                if (parent[j][u] != parent[j][v]) {
                    u = parent[j][u];
                    v = parent[j][v];
                }
            }
            return parent[0][u];
        };
        vector<int> prefix(n, 0);
        for (int u : order) {
            prefix[u] = 1 << (s[u] - 'a');
            if (u != 0) {
                prefix[u] ^= prefix[par[u]];
            }
        }
        vector<int> tree(n + 2, 0);
        auto update = [&](int idx, int val) {
            for (; idx <= n + 1; idx += idx & -idx) {
                tree[idx] ^= val;
            }
        };
        auto getMask = [&](int idx) {
            int res = 0;
            for (; idx > 0; idx -= idx & -idx) {
                res ^= tree[idx];
            }
            return res;
        };
        auto updateSubtree = [&](int u, int change) {
            update(inTime[u] + 1, change);
            update(outTime[u] + 2, change);
        };
        vector<bool> ans;
        for (string &query : queries) {
            string op;
            int u;
            char ch;
            stringstream input(query);
            input >> op >> u;

            if (op == "update") {
                input >> ch;
                int oldChar = 1 << (s[u] - 'a');
                int newChar = 1 << (ch - 'a');
                int change = oldChar ^ newChar;
                updateSubtree(u, change);
                s[u] = ch;
            } 
            else {
                int v;
                input >> v;
                int common = findLCA(u, v);
                int mask1 = prefix[u] ^ getMask(inTime[u] + 1);
                int mask2 = prefix[v] ^ getMask(inTime[v] + 1);
                int pathMask = mask1 ^ mask2 ^ (1 << (s[common] - 'a'));
                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};