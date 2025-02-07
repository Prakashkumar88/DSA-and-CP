#include <bits/stdc++.h>
using namespace std;
// Given an array of 2n numbers, each number from 1 to n in it occurs exactly twice. We say that the segment y intersects the segment x if exactly one occurrence of the number y is between the occurrences of the number x. Find for each segment i how many segments there are that intersect with it.
// Optimization and Compiler Settings
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)
const int INF = 1e9 + 10;

// Control Flow
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define f0r(i, a) for (int i = 0; i < (a); i++)
#define fOrd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define f0rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)

// Types
#define ll long long
#define vi vector<int>
#define vll vector<ll>

// Segment Tree class
class SegmentTree
{
private:
    vi tree;
    int n;

    int merge(int left, int right)
    {
        return left + right;
    }

    int query(int node, int start, int end, int L, int R)
    {
        if (R < start || L > end)
        {
            return 0; // Out of range.
        }
        if (L <= start && end <= R)
        {
            return tree[node]; // Fully within range.
        }

        int mid = (start + end) / 2;
        int leftResult = query(2 * node, start, mid, L, R);
        int rightResult = query(2 * node + 1, mid + 1, end, L, R);
        return merge(leftResult, rightResult);
    }

    void update(int node, int start, int end, int idx, int value)
    {
        if (start == end)
        {
            tree[node] = value; // Update the leaf node.
        }
        else
        {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, value);
            else
                update(2 * node + 1, mid + 1, end, idx, value);

            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

public:
    SegmentTree(int size)
    {
        n = size;
        tree.resize(4 * n, 0); // Initialize the tree with zeroes.
    }

    void update(int idx, int value)
    {
        update(1, 1, n, idx, value);
    }

    int query(int L, int R)
    {
        return query(1, 1, n, L, R);
    }
};

void solve()
{
    int n;
    cin >> n;

    vi pos(2 * n + 1, 0), ans(n + 1, 0), v(2 * n + 2);
    FOR(i, 1, 2 * n + 1)
    {
        cin >> v[i];
    }

    SegmentTree segTree(2 * n);

    // First and second pass through the array
    FOR(time, 0, 2)
    {
        FOR(i, 1, 2 * n + 1)
        {
            int num = v[i];

            if (pos[num] == 0)
            {
                pos[num] = i;
                segTree.update(i, 1); // Mark position as active.
            }
            else
            {
                segTree.update(pos[num], 0); // Deactivate previous position.
                int count = segTree.query(pos[num], i); // Query for active indices in range.
                ans[num] += count; // Update answer for this segment.
                pos[num] = 0;      // Reset position for reuse.
            }
        }

        reverse(v.begin() + 1, v.end()); // Reverse array for the second pass.
    }

    // Output results.
    FOR(i, 1, n + 1)
    {
        cout << ans[i] << sp;
    }
    cout << nl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
