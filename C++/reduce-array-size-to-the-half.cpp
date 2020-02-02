// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> counting_sort(arr.size());
        unordered_map<int, int> count;
        for (const auto& x : arr) {
            ++count[x];
        }
        for (const auto& [_, c] : count) {
            ++counting_sort[c - 1];
        }
        int result = 0, total = 0;
        for (int c = arr.size() - 1; c >= 0; -- c) {
            for (int i = 0; i < counting_sort[c]; ++i) {
                ++result;
                total += c + 1;
                if (total * 2 >= arr.size()) {
                    return result;
                }
            }
        }
        return result;
    }
};
