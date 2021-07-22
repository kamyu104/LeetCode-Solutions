// Time:  O(m * n)
// Space: O(l), l is min(len(arr) for arr in arrays)

class Solution {
public:
    vector<int> longestCommomSubsequence(vector<vector<int>>& arrays) {
        const auto min_cit = min_element(cbegin(arrays), cend(arrays),
                                         [](const auto& a, const auto& b) {
                                             return size(a) < size(b);
                                         });
        vector<int> result = *min_cit;
        for (auto cit = cbegin(arrays); cit != cend(arrays); ++cit) {
            if (cit == min_cit) {
                continue;
            }
            vector<int> new_result;
            for (int i = 0, j = 0; i != size(result) && j != size(*cit);) {
                if (result[i] < (*cit)[j]) {
                    ++i;
                } else if (result[i] > (*cit)[j]) {
                    ++j;
                } else {
                    new_result.emplace_back(result[i]);
                    ++i;
                    ++j;
                }
            }
            result = move(new_result);
        }
        return result;
    }
};

// Time:  O(m * n)
// Space: O(k), k is min(m * n, max(x for arr in arrays for x in arr))
class Solution2 {
public:
    vector<int> longestCommomSubsequence(vector<vector<int>>& arrays) {
        unordered_map<int, int> lookup;
        for (const auto& arr : arrays) {
            for (const auto& x : arr) {
                ++lookup[x];
            }
        }
        vector<int> result;
        for (const auto& x : arrays[0]) {
            if (lookup[x] == size(arrays)) {
                result.emplace_back(x);
            }
        }
        return result;
    }
};
