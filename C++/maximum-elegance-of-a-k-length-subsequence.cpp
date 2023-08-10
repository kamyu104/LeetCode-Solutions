// Time:  O(nlogk)
// Space: O(k)

// partial sort, bst, greedy
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        partial_sort(begin(items), begin(items) + k, end(items), greater<vector<int>>());
        vector<int> stk;
        vector<bool> lookup(size(items));
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
        multiset<pair<int, int>> bst;
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
            lookup2[c - 1] = p;
            bst.emplace(p, c);
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

// Time:  O(nlogn)
// Space: O(n)
// sort, greedy
class Solution2 {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(rbegin(items), rend(items));
        vector<int> stk;
        vector<bool> lookup(size(items));
        int64_t result = 0, curr = 0, l = 0;
        for (int i = 0; i < size(items); ++i) {
            if (i < k) {
                if (lookup[items[i][1] - 1]) {
                    stk.emplace_back(items[i][0]);
                }
                curr += items[i][0];
            } else {
                if (!lookup[items[i][1] - 1]) {
                    if (empty(stk)) {
                        break;
                    }
                    curr += items[i][0] - stk.back(); stk.pop_back();
                }
            }
            if (!lookup[items[i][1] - 1]) {
                lookup[items[i][1] - 1] = true;
                ++l;
            }
            result = max(result, curr + l * l);
        }
        return result;
    }
};
