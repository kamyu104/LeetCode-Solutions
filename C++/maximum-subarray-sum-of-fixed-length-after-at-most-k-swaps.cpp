// Time:  O(nlogn)
// Space: O(n)

template<typename T>
class BIT {
public:
    BIT(int n) : bit_(n + 1) {  // 0-indexed
    }

    void add(int i, T val) {
        ++i;
        for (; i < size(bit_); i += lower_bit(i)) {
            bit_[i] += val;
        }
    }

    T query(int i) const {
        ++i;
        T total = 0;
        for (; i > 0; i -= lower_bit(i)) {
            total += bit_[i];
        }
        return total;
    }

    int kth_element(int k) const {
        if (k <= 0) {
            return -1;
        }
        T total = 0;
        int pos = 0;
        for (int i = floor_log2_x(size(bit_) - 1); i >= 0; --i) {
            if (pos + (1 << i) < size(bit_) && !(total + bit_[pos + (1 << i)] >= k)) {
                total += bit_[pos + (1 << i)];
                pos += (1 << i);
            }
        }
        return (pos + 1) - 1;
    }

private:
    int lower_bit(int i) const {
        return i & -i;
    }

    int floor_log2_x(int x) const {
        return bit_width(static_cast<uint32_t>(x)) - 1;
    };

    vector<T> bit_;
};

// sort, coordinate compression, fenwick tree, greedy, sliding window
class Solution {
public:
    long long maxSum(vector<int>& nums, int length, int k) {
        enum Side { IN, OUT };

        k = min({k, length, static_cast<int>(size(nums)) - length});
        if (k == 0) {
            int64_t result = accumulate(cbegin(nums), cbegin(nums) + length, 0LL), curr = result;
            for (int i = length; i < size(nums); ++i) {
                curr += nums[i] - nums[i - length];
                result = max(result, curr);
            }
            return result;
        }
        vector<int> order(size(nums));
        iota(begin(order), end(order), 0);
        ranges::sort(order, {}, [&](int i) { return nums[i]; });
        vector<int> rank(size(nums));
        for (const auto& [i, x] : order | views::enumerate) {
            rank[x] = i;
        }
        vector<BIT<int>> cnt(2, BIT<int>(size(nums)));
        vector<BIT<int64_t>> total(2, BIT<int64_t>(size(nums)));
        const auto& update = [&](int i, Side side, int d) {
            cnt[side].add(rank[i], d);
            total[side].add(rank[i], static_cast<int64_t>(d) * nums[i]);
        };

        const auto& top_total = [&](Side side, int i) {
            return total[side].query(size(nums) - 1) - total[side].query(cnt[side].kth_element((side == IN ? length : size(nums) - length) - i));
        };

        for (int i = 0; i < length; ++i) {
            update(i, IN, +1);
        }
        for (int i = length; i < size(nums); ++i) {
            update(i, OUT, +1);
        }
        int64_t result = total[IN].query(size(nums) - 1);
        int curr = 0;
        for (int i = 0; i < length; ++i) {
            curr += rank[i] >= size(nums) - length;
        }
        for (int left = 0; left + length - 1 < size(nums); ++left) {
            if (curr >= length - k) {
                int64_t result = 0;
                for (int i = 0; i < size(nums); ++i) {
                    if (rank[i] >= size(nums) - length) {
                        result += nums[i];
                    }
                }
                return result;
            }
            result = max(result, top_total(IN, length - k) + top_total(OUT, k));
            const auto& right = left + length;
            if (right >= size(nums)) {
                continue;
            }
            update(left, IN, -1);
            update(left, OUT, +1);
            update(right, OUT, -1);
            update(right, IN, +1);
            curr += (rank[right] >= size(nums) - length) - (rank[left] >= size(nums) - length);
        }
        return result;
    }
};

// Time:  O(n * (logn)^2)
// Space: O(n)
// sort, coordinate compression, fenwick tree, binary search, sliding window
class Solution2 {
public:
    long long maxSum(vector<int>& nums, int length, int k) {
        enum Side { IN, OUT };

        const auto& binary_search_right = [](int left, int right, const auto& check) {
            while (left <= right) {
                const int mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        k = min({k, length, static_cast<int>(size(nums)) - length});
        if (k == 0) {
            int64_t result = accumulate(cbegin(nums), cbegin(nums) + length, 0LL), curr = result;
            for (int i = length; i < size(nums); ++i) {
                curr += nums[i] - nums[i - length];
                result = max(result, curr);
            }
            return result;
        }
        vector<int> order(size(nums));
        iota(begin(order), end(order), 0);
        ranges::sort(order, {}, [&](int i) { return nums[i]; });
        vector<int> rank(size(nums));
        for (const auto& [i, x] : order | views::enumerate) {
            rank[x] = i;
        }
        vector<BIT<int>> cnt(2, BIT<int>(size(nums)));
        vector<BIT<int64_t>> total(2, BIT<int64_t>(size(nums)));
        const auto& update = [&](int i, Side side, int d) {
            cnt[side].add(rank[i], d);
            total[side].add(rank[i], static_cast<int64_t>(d) * nums[i]);
        };

        const auto& kth_element = [&](Side side, int i) {
            return nums[order[cnt[side].kth_element(i)]];
        };

        const auto& top_total = [&](Side side, int i) {
            return total[side].query(size(nums) - 1) - total[side].query(cnt[side].kth_element((side == IN ? length : size(nums) - length) - i));
        };

        for (int i = 0; i < length; ++i) {
            update(i, IN, +1);
        }
        for (int i = length; i < size(nums); ++i) {
            update(i, OUT, +1);
        }
        int64_t result = total[IN].query(size(nums) - 1);
        for (int left = 0; left + length - 1 < size(nums); ++left) {
            const auto& i = binary_search_right(1, k, [&](int i) {
                return kth_element(OUT, (size(nums) - length) - i + 1) - kth_element(IN, i) > 0;
            });
            result = max(result, top_total(IN, length - i) + top_total(OUT, i));
            const auto& right = left + length;
            if (right >= size(nums)) {
                continue;
            }
            update(left, IN, -1);
            update(left, OUT, +1);
            update(right, OUT, -1);
            update(right, IN, +1);
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// sort, two pointers, greedy, sliding window
class Solution3 {
public:
    long long maxSum(vector<int>& nums, int length, int k) {
        k = min({k, length, static_cast<int>(size(nums)) - length});
        int64_t result = accumulate(cbegin(nums), cbegin(nums) + length, 0LL), curr = result;
        if (k == 0) {
            for (int i = length; i < size(nums); ++i) {
                curr += nums[i] - nums[i - length];
                result = max(result, curr);
            }
            return result;
        }
        vector<int> order(size(nums));
        iota(begin(order), end(order), 0);
        ranges::sort(order, {}, [&](int i) { return nums[i]; });
        for (int left = 0; left + length - 1 < size(nums); ++left) {
            const auto& right = left + length;
            int64_t total = curr;
            for (int _ = 0, i = 0, j = size(nums) - 1; _ < k; ++_, ++i, --j) {
                for (; !(left <= order[i] && order[i] < right); ++i);
                for (; left <= order[j] && order[j] < right; --j);
                if (nums[order[j]] - nums[order[i]] <= 0) {
                    break;
                }
                total += nums[order[j]] - nums[order[i]];
            }
            result = max(result, total);
            if (right >= size(nums)) {
                continue;
            }
            curr += nums[right] - nums[left];
        }
        return result;
    }
};
