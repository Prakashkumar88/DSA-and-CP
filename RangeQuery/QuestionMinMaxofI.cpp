class SegTree {
private:
    vector<int> tree;
    int n;

    int merge(int left, int right) { return left + right; }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = 0;
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) update(2 * node, start, mid, idx, val);
            else update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return merge(
            query(2 * node, start, mid, l, r),
            query(2 * node + 1, mid + 1, end, l, r)
        );
    }

public:
    SegTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for (int i = 0; i < n; i++)
            pos2[nums2[i]] = i;

        SegTree segLeft(n), segRight(n);
        vector<int> left(n), right(n);

        for (int i = 0; i < n; i++) {
            int pos = pos2[nums1[i]];
            left[i] = segLeft.query(0, pos - 1);
            segLeft.update(pos, segLeft.query(pos, pos) + 1);
        }

        for (int i = n - 1; i >= 0; i--) {
            int pos = pos2[nums1[i]];
            right[i] = segRight.query(pos + 1, n - 1);
            segRight.update(pos, segRight.query(pos, pos) + 1);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += 1LL * left[i] * right[i];

        return ans;
    }
};
