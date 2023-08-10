// Time:  O(nlogk)
// Space: O(k)

// partial sort, bst, greedy
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        partial_sort(begin(items), begin(items) + k, end(items), greater<vector<int>>());
        vector<bool> lookup(size(items));
        vector<int> stk;
        int64_t curr = 0, l = 0;
        for (int i = 0; i < k; ++i) {
            if (lookup[items[i][1] - 1]) {
                stk.emplace_back(items[i][0]);
            }
            curr += items[i][0];
            if (!lookup[items[i][1] - 1]) {
                lookup[items[i][1] - 1] = true;
                ++l;
            }
        }
        set<pair<int, int>> bst;
        vector<int> lookup2(size(items));
        for (int i = k; i < size(items); ++i) {
            const auto& p = items[i][0], &c = items[i][1];
            if (lookup[c - 1]) {
                continue;
            }
            if (lookup2[c - 1]) {
                if (lookup2[c - 1] >= p) {
                    continue;
                }
                bst.erase({lookup2[c - 1], c});
            }
            bst.emplace(p, c);
            lookup2[c - 1] = p;
            if (size(bst) > size(stk)) {
                auto it = begin(bst);
                lookup2[it->second - 1] = 0;
                bst.erase(it);
            }
        }
        int64_t result = curr + l * l;
        for (auto rit = rbegin(bst); rit != rend(bst); ++rit) {
            curr += rit->first - stk.back(); stk.pop_back();
            ++l;
            result = max(result, curr + l * l);
        }
        return result;
    }
};

// Time:  O(n + klogk)
// Space: O(n)
// quick select, sort, greedy
class Solution2 {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        const auto& nlargest = [](const auto& k, auto nums) {
            if (empty(nums)) {
                return vector<vector<int>>();
            }
            nth_element(begin(nums), begin(nums) + (k - 1), end(nums), greater<vector<int>>());
            sort(begin(nums), begin(nums) + k, greater<vector<int>>());
            return vector<vector<int>>(begin(nums), begin(nums) + k);
        };

        vector<bool> lookup(size(items));
        vector<int> stk;
        int64_t curr = 0, l = 0;
        for (const auto& x : nlargest(k, items)) {
            if (lookup[x[1] - 1]) {
                stk.emplace_back(x[0]);
            }
            curr += x[0];
            if (!lookup[x[1] - 1]) {
                lookup[x[1] - 1] = true;
                ++l;
            }
        }
        vector<int> lookup2(size(items));
        for (const auto& x : items) {
            if (lookup[x[1] - 1]) {
                continue;
            }
            lookup2[x[1] - 1] = max(lookup2[x[1] - 1], x[0]);
        }
        vector<vector<int>> candidates;
        for (int c = 0; c < size(lookup2); ++c) {
            if (lookup2[c]) {
                candidates.push_back({lookup2[c], c});
            }
        }
        int64_t result = curr + l * l;
        for (const auto& x : nlargest(min(size(stk), size(candidates)), candidates)) {
            curr += x[0] - stk.back(); stk.pop_back();
            ++l;
            result = max(result, curr + l * l);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, greedy
class Solution3 {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(rbegin(items), rend(items));
        vector<bool> lookup(size(items));
        vector<int> stk;
        int64_t curr = 0, l = 0;
        for (int i = 0; i < k; ++i) {
            if (lookup[items[i][1] - 1]) {
                stk.emplace_back(items[i][0]);
            }
            curr += items[i][0];
            if (!lookup[items[i][1] - 1]) {
                lookup[items[i][1] - 1] = true;
                ++l;
            }
        }
        int64_t result = curr + l * l;
        for (int i = k; i < size(items); ++i) {
            if (lookup[items[i][1] - 1]) {
                continue;
            }
            if (empty(stk)) {
                break;
            }
            curr += items[i][0] - stk.back(); stk.pop_back();
            lookup[items[i][1] - 1] = true;
            ++l;
            result = max(result, curr + l * l);
        }
        return result;
    }
};
