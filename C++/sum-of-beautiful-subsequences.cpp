// Time:  precompute: O(rlogr), r = max_nums
//        runtime:    O(mx + nlogr * (log(nlogr) + logn)), mx = max(nums)
// Space: O(rlogr)

// number theory, bit, fenwick tree
const int MOD = 1e9 + 7;

class BIT {
public:
    BIT(int n) : bit_(n + 1) {  // 0-indexed
    }
    
    void add(int i, int val) {
        ++i;
        for (; i < size(bit_); i += lower_bit(i)) {
            bit_[i] = (bit_[i] + val) % MOD;
        }
    }

    int query(int i) const {
        ++i;
        int total = 0;
        for (; i > 0; i -= lower_bit(i)) {
            total = (total + bit_[i]) % MOD;
        }
        return total;
    }

private:
    inline int lower_bit(int i) const {
        return i & -i;
    }
    
    vector<int> bit_;
};

const auto& factors = [](int n) {  // Time: O(nlogn)
    vector<vector<int>> result(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            result[j].emplace_back(i);
        }
    }
    return result;
};

const auto& phi_sieve = [](int n) {  // Time: O(nlog(logn))
    vector<int> phi(n + 1);
    iota(begin(phi), end(phi), 0);
    for (int i = 2; i <= n; ++i) {
        if (phi[i] != i) {
            continue;
        }
        for (int j = i; j <= n; j += i) {
            phi[j] -= phi[j] / i;
        }
    }
    return phi;
};

const int MAX_NUM = 7 * 1e4;
const auto& FACTORS = factors(MAX_NUM);
const auto& PHI = phi_sieve(MAX_NUM);
class Solution {
public:
    int totalBeauty(vector<int>& nums) {
        const auto& count = [&](const auto& arr){
            unordered_set<int> arr_set(cbegin(arr), cend(arr));
            vector<int> sorted_arr(cbegin(arr_set), cend(arr_set));
            sort(begin(sorted_arr), end(sorted_arr));
            unordered_map<int, int> val_to_idx;
            for (int i = 0; i < size(sorted_arr); ++i) {  // coordinate compression
                val_to_idx[sorted_arr[i]] = i;
            }
            BIT bit(size(val_to_idx));
            for (const auto& x : arr) {
                bit.add(val_to_idx[x], bit.query(val_to_idx[x] - 1) + 1);
            }
            return bit.query(size(val_to_idx) - 1);
        };

        const auto& mx = ranges::max(nums);
        vector<vector<int>> lookup(ranges::max(nums) + 1);
        for (const auto& x : nums) {
            for (const auto& d : FACTORS[x]) {
                lookup[d].emplace_back(x);
            }
        }
        int result = 0;
        vector<int> cnt(mx + 1);
        for (int64_t g = size(cnt) - 1; g >= 1; --g) {
            result = (result + (static_cast<int64_t>(PHI[g]) * count(lookup[g])) % MOD) % MOD;
        }
        return result;
    }
};

// Time:  precompute: O(rlogr), r = max_nums
//        runtime:    O(mx * log(mx) + nlogr * (log(nlogr) + logn)), mx = max(nums)
// Space: O(rlogr)
// number theory, bit, fenwick tree
class Solution2 {
public:
    int totalBeauty(vector<int>& nums) {
        const auto& count = [&](const auto& arr){
            unordered_set<int> arr_set(cbegin(arr), cend(arr));
            vector<int> sorted_arr(cbegin(arr_set), cend(arr_set));
            sort(begin(sorted_arr), end(sorted_arr));
            unordered_map<int, int> val_to_idx;
            for (int i = 0; i < size(sorted_arr); ++i) {  // coordinate compression
                val_to_idx[sorted_arr[i]] = i;
            }
            BIT bit(size(val_to_idx));
            for (const auto& x : arr) {
                bit.add(val_to_idx[x], bit.query(val_to_idx[x] - 1) + 1);
            }
            return bit.query(size(val_to_idx) - 1);
        };

        const auto& mx = ranges::max(nums);
        vector<vector<int>> lookup(ranges::max(nums) + 1);
        for (const auto& x : nums) {
            for (const auto& d : FACTORS[x]) {
                lookup[d].emplace_back(x);
            }
        }
        int result = 0;
        vector<int> cnt(mx + 1);
        for (int64_t g = size(cnt) - 1; g >= 1; --g) {
            cnt[g] = count(lookup[g]);
            for(int ng = g + g; ng <= mx; ng += g){
                cnt[g] = ((cnt[g] - cnt[ng]) % MOD + MOD) % MOD;
            }
            result = (result + (g * cnt[g]) % MOD) % MOD;
        }
        return result;
    }
};
