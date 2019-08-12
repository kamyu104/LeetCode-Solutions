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
        for (int count = 0; count < K; ++count) {
            const auto& i = arr_[uniform_int_distribution<int>{left, right}(gen_)];
            const auto& l = lower_bound(inv_idx_[i].cbegin(), inv_idx_[i].cend(), left);
            const auto& r = upper_bound(inv_idx_[i].cbegin(), inv_idx_[i].cend(), right);
            if (r - l >= threshold) {
                return i;
            }
        }
        return -1;
    }

private:
    static constexpr int Q = 10000;
    static constexpr double ERROR_RATE = 0.001;
    static constexpr int K = log(Q / ERROR_RATE) / log(2) + 1;
    const vector<int>& arr_;
    unordered_map<int, vector<int>> inv_idx_;
    default_random_engine gen_;
};

// Time:  ctor:  O(n)
//        query: O(nlogn)
// Space: O(n)
class MajorityChecker2 {
public:
    MajorityChecker2(vector<int>& arr) : arr_(arr) {
        for (int i = 0; i < arr_.size(); ++i) {
            inv_idx_[arr_[i]].emplace_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for (const auto& [i, group] : inv_idx_) {
            if (group.size() < threshold) {
                continue;
            }
            const auto& l = lower_bound(group.cbegin(), group.cend(), left);
            const auto& r = upper_bound(group.cbegin(), group.cend(), right);
            if (r - l >= threshold) {
                return i;
            }
        }
        return -1;
    }

private:
    const vector<int>& arr_;
    unordered_map<int, vector<int>> inv_idx_;
};
