// Time:  ctor:  O(n)
//        query: O(klogn), k = log2(Q/ERROR_RATE)
// Space: O(n)

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr)
      : arr_(arr)
      , gen_((random_device())())
    {
        for (int i = 0; i < arr_.size(); ++i) {
            inv_idx_[arr_[i]].emplace_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for (int i = 0; i < K; ++i) {
            const auto& m = arr_[uniform_int_distribution<int>{left, right}(gen_)];
            if (count(inv_idx_, m, left, right) >= threshold) {
                return m;
            }
        }
        return -1;
    }

private:
    int count(const unordered_map<int, vector<int>>& inv_idx, int m, int left, int right) {
        const auto& l = lower_bound(inv_idx_[m].cbegin(), inv_idx_[m].cend(), left);
        const auto& r = upper_bound(inv_idx_[m].cbegin(), inv_idx_[m].cend(), right);
        return r - l;
    }

    static constexpr int Q = 10000;
    static constexpr double ERROR_RATE = 0.001;
    static constexpr int K = log(Q / ERROR_RATE) / log(2) + 1;
    const vector<int>& arr_;
    unordered_map<int, vector<int>> inv_idx_;
    default_random_engine gen_;
};
