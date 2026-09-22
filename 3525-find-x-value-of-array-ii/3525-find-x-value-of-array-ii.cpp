class Solution {
public:
    struct Node {
        int product;
        int cnt[5];
    };
    int k;
    vector<Node> tree;
    Node merge(Node a, Node b) {
    Node c;
    c.product = (a.product * b.product) % k;
    for (int i = 0; i < k; i++)
        c.cnt[i] = a.cnt[i];
    for (int i = 0; i < k; i++)
        c.cnt[(a.product * i) % k] += b.cnt[i];
    return c;
}

    void build(int v, int l, int r, vector<int>& nums) {
        if (l == r) {
            tree[v].product = nums[l] % k;
            for (int i = 0; i < k; i++)
                tree[v].cnt[i] = 0;
            tree[v].cnt[tree[v].product] = 1;
            return;
        }
        int m = (l + r) / 2;
        build(v * 2, l, m, nums);
        build(v * 2 + 1, m + 1, r, nums);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }

    void update(int v, int l, int r, int pos, int val) {
        if (l == r) {
            tree[v].product = val % k;
            for (int i = 0; i < k; i++)
                tree[v].cnt[i] = 0;
            tree[v].cnt[tree[v].product] = 1;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m)
            update(v * 2, l, m, pos, val);
        else
            update(v * 2 + 1, m + 1, r, pos, val);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }

    Node query(int v, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[v];
        int m = (l + r) / 2;
        if (qr <= m)
            return query(v * 2, l, m, ql, qr);
        if (ql > m)
            return query(v * 2 + 1, m + 1, r, ql, qr);
        Node a = query(v * 2, l, m, ql, qr);
        Node b = query(v * 2 + 1, m + 1, r, ql, qr);
        return merge(a, b);
    }
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        int n = nums.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, nums);
        vector<int> ans;
        for (auto q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];
            update(1, 0, n - 1, index, value);
            Node temp = query(1, 0, n - 1, start, n - 1);
            ans.push_back(temp.cnt[x]);
        }
        return ans;
    }
};