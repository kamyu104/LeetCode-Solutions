// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(pieces); ++i) {
            lookup[pieces[i][0]] = i;
        }
        for (int i = 0; i < size(arr);) {
            if (!lookup.count(arr[i])) {
                return false;
            }
            for (const auto& c : pieces[lookup[arr[i]]]) {
                if (i == size(arr) || arr[i] != c) {
                    return false;
                }
                ++i;
            }
        }
        return true;
    }
};
