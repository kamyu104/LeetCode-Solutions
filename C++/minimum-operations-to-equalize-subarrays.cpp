// Time:  O((n + q) * logn)
// Space: O(nlogn)

// prefix sum, persistent segment tree, binary search
class PersistentSegmentTree {
public:
    PersistentSegmentTree(const auto& vals) 
      : sorted_unique_vals_(vals) {

        sort(begin(sorted_unique_vals_), end(sorted_unique_vals_));
        sorted_unique_vals_.erase(unique(begin(sorted_unique_vals_), end(sorted_unique_vals_)), end(sorted_unique_vals_));
        n_ = size(sorted_unique_vals_);
        val_to_idx_.reserve(n_);
        for (int i = 0; i < n_; ++i) {
            val_to_idx_[sorted_unique_vals_[i]] = i;
        }
        build(vals);
    }

    int64_t query(int l, int r) {
        int a = roots_[l];
        int b = roots_[r + 1];
        int64_t left_cnt = 0, left_total = 0;
        auto med_cnt = ((r - l + 1) / 2) + 1;
        int left = 0, right = n_ - 1;
        while (left < right) {
            const auto& mid = left + (right - left) / 2;
            const auto& cnt = nodes_[nodes_[b].left].cnt - nodes_[nodes_[a].left].cnt;
            if (med_cnt <= cnt) {
                a = nodes_[a].left;
                b = nodes_[b].left;
                right = mid;
            } else {
                left_cnt += cnt;
                left_total += nodes_[nodes_[b].left].total - nodes_[nodes_[a].left].total;
                med_cnt -= cnt;
                a = nodes_[a].right;
                b = nodes_[b].right;
                left = mid + 1;
            }
        }
        return (sorted_unique_vals_[left] * left_cnt - left_total) +
               (((nodes_[roots_[r + 1]].total - nodes_[roots_[l]].total - left_total)) - sorted_unique_vals_[left] * ((r - l + 1) - left_cnt));
    }

private:
    inline int new_node() {
        nodes_.emplace_back();
        return size(nodes_) - 1;
    }

    inline int copy_node(int idx) {
        nodes_.emplace_back(nodes_[idx]);
        return size(nodes_) - 1;
    }

    void build(const auto& vals) {
        int root = new_node();
        roots_.emplace_back(root);
        for (const auto& x : vals) {
            root = copy_node(root);
            roots_.emplace_back(root);
            int curr = root;
            int left = 0, right = n_ - 1;
            const auto& i = val_to_idx_[x];
            while (left < right) {
                ++nodes_[curr].cnt;
                nodes_[curr].total += x;
                const auto& mid = left + (right - left) / 2;
                if (i <= mid) {
                    curr = nodes_[curr].left = copy_node(nodes_[curr].left);
                    right = mid;
                } else {
                    curr = nodes_[curr].right = copy_node(nodes_[curr].right);
                    left = mid + 1;
                }
            }
            ++nodes_[curr].cnt;
            nodes_[curr].total += x;
        }
    }

    struct Node {
        int left = 0;
        int right = 0;
        int cnt = 0;
        int64_t total = 0;
    };

    int n_;
    vector<int64_t> sorted_unique_vals_;
    unordered_map<int64_t, int> val_to_idx_;
    vector<Node> nodes_;
    vector<int> roots_;
};

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, int k,  vector<vector<int>>& queries) {
        vector<int> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + (i - 1 >= 0 && nums[i] % k != nums[i - 1] % k ? 1 : 0);
        }
        vector<int64_t> vals(size(nums));
        for (int i = 0; i < size(vals); ++i) {
            vals[i] = nums[i] / k;
        }
        PersistentSegmentTree pst(vals);
        vector<long long> result;
        result.reserve(size(queries));
        for (const auto& q : queries) {
            const auto& s = q[0], &t = q[1];
            result.emplace_back(prefix[t + 1] - prefix[s + 1] == 0 ? pst.query(s, t) : -1);
        }
        return result;
    }
};
