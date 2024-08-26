// Time:  O(n + (n + logr) + nlog(logr) + nlogn) = O(nlogn), assumed log(x) takes O(1) time
// Space: O(n)

// sort, two pointers, sliding window, fast exponentiation
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        static const double EPS = 1e-15;
        const auto& count = [](const auto& x, int target) {
            return static_cast<int>(target - x + EPS);
        };

        if (multiplier == 1) {
            return nums;
        }
        using P = pair<double, int>;
        vector<P> vals;
        for (int i = 0; i < size(nums); ++i) {
            vals.emplace_back(log(nums[i]) / log(multiplier), i);
        }
        sort(begin(vals), end(vals));
        int right = 1;
        for (int left = 0; right <= static_cast<int>(vals.back().first) + 1; ++right) {
            for (; left < size(vals) && count(vals[left].first, right) >= 1; ++left);
            if (k - left < 0) {
                --right;
                break;
            }
            k -= left;
        }
        if (right == static_cast<int>(vals.back().first) + 2) {
            --right;
        }
        for (int idx = 0; idx < size(vals); ++idx) {
            const auto& [x, i] = vals[idx];
            const int c = count(x, right);
            if (c <= 0) {
                break;
            }
            nums[i] *= pow(multiplier, c);
        }
        vals.clear();
        for (int i = 0; i < size(nums); ++i) {
            vals.emplace_back(nums[i], i);
        }
        sort(begin(vals), end(vals));
        const int q =  k / size(nums), r = k % size(nums);
        const int m = pow(multiplier, q);
        vector<int> result(size(nums));
        for (int idx = 0; idx < size(vals); ++idx) {
            const auto& [x, i] = vals[idx];
            result[i] = x * m * (idx < r ? multiplier : 1);
        }
        return result;
    }
};

// Time:  O(n + min(n, k) * log(logr) + nlog(logr) + nlogn) = O(nlogr), assumed log(x) takes O(1) time
// Space: O(n)
// binary search, sort, fast exponentiation
class Solution2 {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        static const double EPS = 1e-15;
        const auto& binary_search_right = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        const auto& count = [](const auto& x, int target) {
            return static_cast<int>(target - x + EPS);
        };

        if (multiplier == 1) {
            return nums;
        }
        using P = pair<double, int>;
        vector<P> vals;
        for (int i = 0; i < size(nums); ++i) {
            vals.emplace_back(log(nums[i]) / log(multiplier), i);
        }
        sort(begin(vals), end(vals));
        const auto& check = [&](const auto& target) {
            int result = 0;
            for (const auto& [x, i] : vals) {
                const int c = count(x, target);
                if (c <= 0) {
                    break;
                }
                result += c;
            }
            return result <= k;
        };

        const int target = binary_search_right(1, static_cast<int>(vals.back().first) + 1, check);
        for (int idx = 0; idx < size(vals); ++idx) {
            const auto& [x, i] = vals[idx];
            const int c = count(x, target);
            if (c <= 0) {
                break;
            }
            k -= c;
            nums[i] *= pow(multiplier, c);
        }
        vals.clear();
        for (int i = 0; i < size(nums); ++i) {
            vals.emplace_back(nums[i], i);
        }
        sort(begin(vals), end(vals));
        const int q =  k / size(nums), r = k % size(nums);
        const int m = pow(multiplier, q);
        vector<int> result(size(nums));
        for (int idx = 0; idx < size(vals); ++idx) {
            const auto& [x, i] = vals[idx];
            result[i] = x * m * (idx < r ? multiplier : 1);
        }
        return result;
    }
};

// Time:  O(min(nlogr, k) * logn + nlogn) = O(nlogn * logr)
// Space: O(n)
// heap, sort, fast exponentiation
class Solution3 {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        using P = pair<int, int>;
        vector<P> vals;
        for (int i = 0; i < size(nums); ++i) {
            vals.emplace_back(nums[i], i);
        }
        priority_queue<P, vector<P>, greater<P>> min_heap(cbegin(vals), cend(vals));
        const int mx = ranges::max(nums);
        for (; k; --k) {
            const auto [x, i] = min_heap.top(); min_heap.pop();
            if (x >= mx) {
                break;
            }
            nums[i] *= multiplier;
            min_heap.emplace(nums[i], i);
        }
        vals.clear();
        for (int i = 0; i < size(nums); ++i) {
            vals.emplace_back(nums[i], i);
        }
        sort(begin(vals), end(vals));
        const int q =  k / size(nums), r = k % size(nums);
        const int m = pow(multiplier, q);
        vector<int> result(size(nums));
        for (int idx = 0; idx < size(vals); ++idx) {
            const auto& [x, i] = vals[idx];
            result[i] = x * m * (idx < r ? multiplier : 1);
        }
        return result;
    }
};

// Time:  O(n + klogn)
// Space: O(n)
// simulation, heap
class Solution4 {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        using P = pair<int, int>;
        vector<P> vals;
        for (int i = 0; i < size(nums); ++i) {
            vals.emplace_back(nums[i], i);
        }
        priority_queue<P, vector<P>, greater<P>> min_heap(cbegin(vals), cend(vals));
        for (int _ = 0; _ < k; ++_) {
            const auto [x, i] = min_heap.top(); min_heap.pop();
            nums[i] *= multiplier;
            min_heap.emplace(nums[i], i);
        }
        return nums;
    }
};

// Time:  O(k * n)
// Space: O(1)
// simulation
class Solution5 {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        for (int _ = 0; _ < k; ++_) {
            const int i = distance(cbegin(nums), min_element(cbegin(nums), cend(nums)));
            nums[i] *= multiplier;
        }
        return nums;
    }
};
