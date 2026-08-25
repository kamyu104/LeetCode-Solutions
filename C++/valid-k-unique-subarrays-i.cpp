// Time:  O(n + q)
// Space: O(n)

// two pointers, hash table, prefix sum
class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        const auto& min_left = [&](int k) {
            vector<int> result(size(nums), size(nums));
            unordered_map<int, int> cnt;
            for (int right = 0, left = 0; right < size(nums); ++right) {
                ++cnt[nums[right]];
                while (size(cnt) == k + 1) {
                    --cnt[nums[left]];
                    if (!cnt[nums[left]]) {
                        cnt.erase(nums[left]);
                    }
                    ++left;
                }
                if (size(cnt) == k) {
                    result[right] = left;
                }
            }
            return result;
        };

        const auto& left = min_left(k);
        const auto& right = min_left(k - 1);
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        unordered_map<int, uint64_t> h;
        vector<uint64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            if (!h.count(nums[i])) {
                h[nums[i]] = rng();
            }
            prefix[i + 1] = prefix[i] ^ h[nums[i]];
        }
        vector<bool> result;
        result.reserve(size(queries));
        for (const auto& q : queries) {
            const auto& l = q[0];
            const auto& r = q[1];
            result.emplace_back((r - l + 1) % 2 == 0 && (prefix[r + 1] ^ prefix[l]) == 0 && left[r] <= l && l < right[r]);
        }
        return result;
    }
};

// Time:  O((n + q) * logn)
// Space: O(n + q)
// hash table, prefix sum, fenwick tree
class Solution2 {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        unordered_map<int, uint64_t> h;
        vector<uint64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            if (!h.count(nums[i])) {
                h[nums[i]] = rng();
            }
            prefix[i + 1] = prefix[i] ^ h[nums[i]];
        }
        vector<vector<pair<int, int>>> groups(size(nums));
        for (int i = 0; i < size(queries); ++i) {
            groups[queries[i][1]].emplace_back(i, queries[i][0]);
        }
        vector<bool> result(size(queries));
        BIT bit(size(nums));
        unordered_map<int, int> lookup;
        for (int r = 0; r < size(nums); ++r) {
            if (lookup.count(nums[r])) {
                bit.add(lookup[nums[r]], -1);
            }
            lookup[nums[r]] = r;
            bit.add(lookup[nums[r]], 1);
            for (const auto& [i, l] : groups[r]) {
                result[i] = (r - l + 1) % 2 == 0 && (prefix[r + 1] ^ prefix[l]) == 0 && bit.query(r) - bit.query(l - 1) == k;
            }
        }
        return result;
    }

private:
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
};

// Time:  O(qlogq + (n + q) * sqrt(n))
// Space: O(n + q)
// sort, coordinate compression, mo's algorithm
class Solution3 {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        // reference: https://cp-algorithms.com/data_structures/sqrt_decomposition.html
        const auto& mo_s_algorithm = [&]() {
            unordered_map<int, int> cnt;
            int distinct = 0, odd = 0;
            const auto& add = [&](int i) {
                ++cnt[nums[i]];
                odd += (cnt[nums[i]] & 1) ? 1 : -1;
            };

            const auto& remove = [&](int i) {
                --cnt[nums[i]];
                odd += (cnt[nums[i]] & 1) ? 1 : -1;
                if (!cnt[nums[i]]) {
                    cnt.erase(nums[i]);
                }
            };

            const auto& get_ans = [&]() {
                return (size(cnt) == k && odd == 0);
            };

            vector<bool> result(size(queries), false);
            const int block_size = sqrt(size(nums)) + 1;
            vector<int> idxs(size(queries));
            iota(begin(idxs), end(idxs), 0);
            sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
                const auto& i = queries[a][0] / block_size;
                const auto& j = queries[b][0] / block_size;
                return i != j ? i < j : (i & 1 ? queries[a][1] < queries[b][1] : queries[a][1] > queries[b][1]);
            });
            int left = 0, right = -1;
            for (const auto& i : idxs) {
                const auto& l = queries[i][0];
                const auto& r = queries[i][1];
                while (left > l) {
                    --left;
                    add(left);
                }
                while (right < r) {
                    ++right;
                    add(right);
                }
                while (left < l) {
                    remove(left);
                    ++left;
                }
                while (right > r) {
                    remove(right);
                    --right;
                }
                result[i] = get_ans();
            }
            return result;
        };

        return mo_s_algorithm();
    }
};
