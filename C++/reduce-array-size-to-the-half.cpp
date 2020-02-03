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
        for (int c = arr.size() - 1; c >= 0; --c) {
            if (!counting_sort[c]) {
                continue;
            }
            int count = min(counting_sort[c],
                            ((int(arr.size()) + 1) / 2 - total - 1) / (c + 1) + 1);
            result += count;
            total += count * (c + 1);
            if (total >= (arr.size() + 1) / 2) {
                break;
            }
        }
        return result;
    }
};
