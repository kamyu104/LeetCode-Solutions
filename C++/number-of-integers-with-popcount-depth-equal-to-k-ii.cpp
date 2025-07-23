// Time:  precompute: O((logr) * log(logr) + log*(r) * (logr)) = O((logr) * log(logr)), r = max(n)
//        runtime:    O(nlogr + max_k * n + nlogn + qlogn)
// Space: O(logr + max_k * n)

// fenwick tree
class BIT {
public:
    BIT(int n) : bit_(n + 1) {  // 0-indexed
    }
    
    void add(int i, int val) {
        ++i;
        for (; i < size(bit_); i += lower_bit(i)) {
            bit_[i] += val;
        }
    }

    int query(int i) const {
        ++i;
        int total = 0;
        for (; i > 0; i -= lower_bit(i)) {
            total += bit_[i];
        }
        return total;
    }

private:
    int lower_bit(int i) const {
        return i & -i;
    }
    
    vector<int> bit_;
};

int bit_length(int64_t x) {
    return (x ? std::__lg(x) : -1) + 1;
}

int ceil_log2(int64_t x) {
    return std::__lg(x - 1) + 1;
};

pair<vector<int>, int> init() {
    int64_t MAX_N = 1e15;
    static const int MAX_BIT_LEN = bit_length(MAX_N);
    vector<int> D(MAX_BIT_LEN + 1, 0);
    for (int i = 2; i < size(D); ++i) {
        D[i] = D[__builtin_popcount(i)] + 1;
    }
    int MAX_K = 0;
    for (; MAX_N != 1; ++MAX_K) {  // O(log*(MAX_N)) times
        MAX_N = ceil_log2(MAX_N);
    }
    return {D, MAX_K};
}

const auto& [D, MAX_K] = init();
class Solution {
public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        const auto& count = [](int64_t x) {
            return x != 1 ? D[__builtin_popcountll(x)] + 1 : 0;
        };

        vector<BIT> bit(MAX_K + 1, BIT(size(nums)));
        for (int i = 0; i < size(nums); ++i) {
            bit[count(nums[i])].add(i, +1);
        }
        vector<int> result;
        for (const auto& q : queries) {
            if (q[0] == 1) {
                const int l = q[1], r = q[2], k = q[3];
                assert(k < size(bit));
                result.emplace_back(bit[k].query(r) - bit[k].query(l - 1));
            } else {
                const auto& i = q[1], &x = q[2];
                const auto& old_d = count(nums[i]);
                const auto& new_d = count(x);
                if (new_d != old_d) {
                    bit[old_d].add(i, -1);
                    bit[new_d].add(i, +1);
                }
                nums[i] = x;
            }
        }
        return result;
    }
};
