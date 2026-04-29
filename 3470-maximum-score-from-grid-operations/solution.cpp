template <typename T, typename U, typename V>
struct segment_tree {
  vector<T> tree;
  U updater;
  V combiner;
  segment_tree(int n, T default_value, U updater, V combiner) : tree(2 * n, default_value), updater(updater), combiner(combiner) {}
  inline void update(int i, T v) {
    for (tree[i] = updater(tree[i += tree.size() >> 1], v); i > 1; i >>= 1)
      tree[i >> 1] = combiner(tree[i], tree[i ^ 1]);
  }
  invoke_result_t<V, T, T> query(int l, int r, invoke_result_t<V, T, T> default_value) { // [l, r)
    auto ans = default_value;
    for (l += tree.size() >> 1, r += tree.size() >> 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        ans = combiner(ans, tree[l++]);
      if (r & 1)
        ans = combiner(ans, tree[--r]);
    }
    return ans;
  }
};

class Solution {
public:
  long long maximumScore(vector<vector<int>> &g) {
    // Setting up IOI input

    int n = g.size();
    vector<int> x, y, w;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (g[i][j]) {
          x.push_back(j);
          y.push_back(i);
          w.push_back(g[i][j]);
        }
      }
    }
    int m = x.size();

    // IOI solution below

    vector l(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
      l[x[i]].push_back({y[i], w[i]});
    }
    for (int i = 0; i < n; i++) {
      ranges::sort(l[i]);
    }
    auto combine = [](long long x, long long y) {
      return max(x, y);
    };
    segment_tree dp(n, 0LL, combine, combine), dp2(n, 0LL, combine, combine);
    long long ans = 0, pcur = 0, cur = 0;
    for (int i = 0; i < n; i++) {
      vector<pair<int, long long>> apply, apply2;
      {
        long long sum = 0, mx = max(pcur, dp2.query(0, n, 0));
        for (int pj = 0; auto [j, v] : l[i]) {
          mx = max(mx, dp.query(pj, j, 0) - sum);
          sum += v;
          pj = j;
          apply.push_back({j, sum + mx});
        }
      }
      if (i > 0) {
        ranges::reverse(l[i]);
        long long sum = 0, mx = pcur;
        for (int pj = n - 1; auto [j, v] : l[i]) {
          mx = max(mx, dp2.query(j + 1, pj + 1, 0) - sum);
          sum += v;
          pj = j;
          apply2.push_back({j, sum + mx});
        }
      }
      pcur = cur;
      for (auto [j, res] : apply) {
        dp.update(j, res);
        cur = max(cur, res);
        if (i < n - 1) {
          ans = max(ans, res);
        }
      }
      for (auto [j, res] : apply2) {
        dp2.update(j, res);
        ans = max(ans, res);
      }
    }
    return ans;
  }
};
