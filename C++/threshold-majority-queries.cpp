// Time:  O(nlogn + qlogq + (n + q) * sqrt(n) + q * n)
// Space: O(n + q)

// sort, coordinate compression, mo's algorithm
class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> sorted_nums(nums);
        sort(begin(sorted_nums), end(sorted_nums));
        sorted_nums.erase(unique(begin(sorted_nums), end(sorted_nums)), end(sorted_nums));
        unordered_map<int, int> num_to_idx;
        for (int i = 0; i < size(sorted_nums); ++i) {
            num_to_idx[sorted_nums[i]] = i;
        } 
        
        // reference: https://cp-algorithms.com/data_structures/sqrt_decomposition.html
        const auto& mo_s_algorithm = [&]() {
            vector<int> cnt(size(num_to_idx));
            vector<int> cnt2(size(nums) + 1);
            int max_freq = 0;
            const auto& add = [&](int i) {
                const auto& idx = num_to_idx[nums[i]];
                if (cnt[idx]) {
                    --cnt2[cnt[idx]];
                }
                ++cnt[idx];
                ++cnt2[cnt[idx]];
                max_freq = max(max_freq, cnt[idx]);
            };

            const auto& remove = [&](int i) {
                const auto& idx = num_to_idx[nums[i]];
                --cnt2[cnt[idx]];
                if (!cnt2[max_freq]) {
                    --max_freq;
                }
                --cnt[idx];
                if (cnt[idx]) {
                    ++cnt2[cnt[idx]];
                }
            };

            const auto& get_ans = [&](int t) {
                if (max_freq < t) {
                    return -1;
                }
                int i = 0;
                for (; i < size(cnt); ++i) {
                    if (cnt[i] == max_freq) {
                        break;
                    }
                }
                return sorted_nums[i];
            };

            vector<int> result(size(queries), -1);
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
                const auto& t = queries[i][2];
                while (left > l) {
                    left -= 1;
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
                result[i] = get_ans(t);
            }
            return result;
        };

        return mo_s_algorithm();
    }
};

// Time:  O(nlogn + qlogq + (n + q) * sqrt(n) * logn)
// Space: O(n + q)
// sort, coordinate compression, mo's algorithm, bst
class Solution2 {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> sorted_nums(nums);
        sort(begin(sorted_nums), end(sorted_nums));
        sorted_nums.erase(unique(begin(sorted_nums), end(sorted_nums)), end(sorted_nums));
        unordered_map<int, int> num_to_idx;
        for (int i = 0; i < size(sorted_nums); ++i) {
            num_to_idx[sorted_nums[i]] = i;
        } 
    
        // reference: https://cp-algorithms.com/data_structures/sqrt_decomposition.html
        const auto& mo_s_algorithm = [&]() {
            vector<int> cnt(size(num_to_idx));
            vector<multiset<int>> lookup(size(nums) + 1);
            int max_freq = 0;
            const auto& add = [&](int i) {
                const auto& idx = num_to_idx[nums[i]];
                if (cnt[idx]) {
                    auto it = lookup[cnt[idx]].find(nums[i]);
                    lookup[cnt[idx]].erase(it);
                }
                ++cnt[idx];
                lookup[cnt[idx]].emplace(nums[i]);
                max_freq = max(max_freq, cnt[idx]);
            };

            const auto& remove = [&](int i) {
                const auto& idx = num_to_idx[nums[i]];
                auto it = lookup[cnt[idx]].find(nums[i]);
                lookup[cnt[idx]].erase(it);
                if (empty(lookup[max_freq])) {
                    --max_freq;
                }
                --cnt[idx];
                if (cnt[idx]) {
                    lookup[cnt[idx]].emplace(nums[i]);
                }
            };

            const auto& get_ans = [&](int t) {
                return max_freq >= t ? *begin(lookup[max_freq]) : -1;
            };

            vector<int> result(size(queries), -1);
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
                const auto& t = queries[i][2];
                while (left > l) {
                    left -= 1;
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
                result[i] = get_ans(t);
            }
            return result;
        };

        return mo_s_algorithm();
    }
};
