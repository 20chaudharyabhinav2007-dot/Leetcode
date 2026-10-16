class Solution {
    const int MOD = 1e9 + 7;
    long long sum[400005] = {}, sq[400005] = {}, lazy[400005] = {};
    void apply(int node, int l, int r, long long x) {
        long long len = r - l + 1;
        sq[node] = (sq[node] + 2 * x * sum[node] + x * x * len) % MOD;
        sum[node] = (sum[node] + x * len) % MOD;
        lazy[node] += x;
    }
    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r) return;
        int mid = (l + r) / 2;
        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);
        lazy[node] = 0;
    }
    void update(int node, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return;
        if (l >= ql && r <= qr) {
            apply(node, l, r, 1);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);
        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
    }
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        fill(sum, sum + 4 * n + 5, 0);
        fill(sq, sq + 4 * n + 5, 0);
        fill(lazy, lazy + 4 * n + 5, 0);
        vector<int> last(100001, -1);
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            update(1, 0, n - 1, last[x] + 1, i);
            last[x] = i;
            ans = (ans + sq[1]) % MOD;
        }
        return ans;
    }
};