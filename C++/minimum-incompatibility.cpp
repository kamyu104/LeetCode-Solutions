// Time:  O(nlogn + k * n)
// Space: O(n)

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        return min(greedy<less<int>>(nums, k), greedy<greater<int>>(nums, k));
    }

private:
    template<typename T>
    int greedy(const vector<int>& nums, int k) {
        map<int, int, T> count;
        for (const auto& num : nums) {
            ++count[num];
        }
        for (const auto& [_, cnt] : count) {
            if (cnt > k) {
                return -1;
            }
        }
        
        vector<vector<int>> stks(k);
        int curr = 0;
        int remain = size(nums);
        while (remain) {  // the while loop runs O(k) times, and the inner loops runs O(n) times
            for (auto& [x, cnt] : count) {  // fill the deterministic elements into the remaining subsets
                if (cnt != size(stks) - curr) {
                    continue;
                }
                for (int i = curr; i < size(stks); ++i) {
                    stks[i].emplace_back(x);
                }
                remain -= cnt;
                cnt = 0;
            }
            for (auto& [x, cnt] : count) {  // greedily fill the element until the first subset is full
                if (!cnt) {
                    continue;
                }
                stks[curr].emplace_back(x);
                --remain;
                --cnt;
                if (size(stks[curr]) == size(nums) / k) { 
                    ++curr;
                    break;
                }
            }
        }
        return accumulate(cbegin(stks), cend(stks), 0,
                          [](const auto& a, const auto& b) {
                              return a + (*max_element(cbegin(b), cend(b)) - *min_element(cbegin(b), cend(b)));
                          });
    }
};

// Time:  O(max(n * 2^n, 3^n))
// Space: O(2^n)
class Solution2 {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        const vector<int> candidates = findCandidates(nums, k);  // Time: O(n * 2^n)
        const int total = (1 << size(nums)) - 1;
        vector<int> dp(total + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int mask = 0; mask <= total; ++mask) {  // Time: O(3^n)
            if (__builtin_popcount(mask) % (size(nums) / k) != 0) {
                continue;
            }
            // submask enumeration:
            // => sum(nCr(n, k) * 2^k for k in xrange(n+1)) = (1 + 2)^n = 3^n
            // => Time: O(3^n), see https://cp-algorithms.com/algebra/all-submasks.html
            for (int submask = mask; submask; submask = (submask - 1) & mask) {
                if (candidates[submask] == numeric_limits<int>::max() ||
                    dp[mask - submask] == numeric_limits<int>::max()) {
                    continue;
                }
                dp[mask] = min(dp[mask], dp[mask - submask] + candidates[submask]);
            }
        }
        return dp.back() != numeric_limits<int>::max() ? dp.back() : -1;
    }

private:                        
    vector<int> findCandidates(const vector<int>& nums, int k) {
        const int total = (1 << size(nums)) - 1;
        vector<int> result(total + 1, numeric_limits<int>::max());
        for (int mask = 0; mask <= total; ++mask) {
            if (__builtin_popcount(mask) != size(nums) / k) {
                continue;
            }
            int lookup = 0;
            int mx = 0, mn = numeric_limits<int>::max();
            bool duplicated = false;
            for (int i = 0; i < size(nums); ++i) {
                if ((mask & (1 << i)) == 0) {
                    continue;
                }
                if (lookup & (1 << nums[i])) {
                    duplicated = true;
                    break;
                }
                lookup |= (1 << nums[i]);
                mx = max(mx, nums[i]);
                mn = min(mn, nums[i]);
            }
            if (duplicated) {
                continue;
            }
            result[mask] = mx - mn;
        }
        return result;
    }
};

// Time:  O(sum(i*d * nCr(i*d, d) * nCr(n, i*d) for i in xrange(1, k+1))) < O(sum(n * 2^m * nCr(n, m) for m in xrange(n+1))) = O(n * 3^n)
// Space: O(n * k)
class Solution_TLE {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        unordered_map<string, int> lookup;
        int result = backtracking(nums, size(nums) / k, &lookup);
        return result != numeric_limits<int>::max() ? result : -1;
    }

private:
    int backtracking(const vector<int>& nums, int d, unordered_map<string, int> *lookup) {
        if (empty(nums)) {
            return 0;
        }
        string k = key(nums);
        if (!lookup->count(k)) {
            int ret = numeric_limits<int>::max();
            combinations(size(nums), d,
                         [this, &nums, &d, &lookup, &ret](const vector<int>& idxs) {
                             unordered_set<int> new_nums_set;
                             for (const auto& idx : idxs) {
                                 new_nums_set.emplace(nums[idx]);
                             }
                             if (size(new_nums_set) < d) {
                                 return;
                             }
                             int mx = *max_element(cbegin(new_nums_set), cend(new_nums_set));
                             int mn = *min_element(cbegin(new_nums_set), cend(new_nums_set));
                             vector<int> left;
                             for (const auto& num : nums) {
                                 if (new_nums_set.count(num)) {
                                     new_nums_set.erase(num);
                                     continue;
                                 }
                                 left.emplace_back(num);
                             }
                             int result = backtracking(left, d, lookup);
                             if (result != numeric_limits<int>::max()) {
                                 ret = min(ret, mx - mn + result);
                             }
                         });
            (*lookup)[k] = ret;
        }
        return (*lookup)[k];
    }

    string key(const vector<int>& nums) {
        string result;
        for (const auto& num : nums) {
            result += to_string(num);
            result.push_back(',');
        }
        return result;
    }

    void combinations(int n, int k, const function<void (const vector<int>&)>& callback) {
        static const auto& next_pos =
            [](const auto& n, const auto& k, const auto& idxs) {
                int i = k - 1;
                for (; i >= 0; --i) {
                    if (idxs[i] != i + n - k) {
                        break;
                    }
                }
                return i;
            };
    
        vector<int> idxs(k);
        iota(begin(idxs), end(idxs), 0);
        callback(idxs);
        for (int i; (i = next_pos(n, k, idxs)) >= 0;) {
            ++idxs[i];
            for (int j = i + 1; j < k; ++j) {
                idxs[j] = idxs[j - 1] + 1;
            }
            callback(idxs);
        }
    }
};
