// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<long long>> lookup;
        for (int i = 0; i < size(arr); ++i) {
            lookup[arr[i]].emplace_back(i);
        }
        vector<long long> result(size(arr));
        for (const auto& [_, idxs] : lookup) {
            vector<long long> prefix(1);
            for (const auto& i : idxs) {
                prefix.emplace_back(prefix.back() + i);
            }
            for (int i = 0; i < size(idxs); ++i) {
                result[idxs[i]] = (idxs[i] * (i + 1) - prefix[i + 1]) + ((prefix[size(idxs)] - prefix[i]) - idxs[i] * (size(idxs) - i));
            }
        }
        return result;
    }
};
