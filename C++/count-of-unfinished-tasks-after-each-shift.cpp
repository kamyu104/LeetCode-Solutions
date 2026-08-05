// Time:  O(n + mlogn)
// Space: O(n)

// prefix sum, binary search
class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        vector<int64_t> prefix(size(tasks) + 1);
        for (int i = 0; i < size(tasks); ++i) {
            prefix[i + 1] = prefix[i] + tasks[i];
        }
        vector<int> result(size(shifts));
        for (int64_t i = 0, total = 0; i < size(shifts); ++i) {
            total += shifts[i];
            if (total >= prefix.back()) {
                total = 0;
                continue;
            }
            result[i] = size(prefix) - distance(cbegin(prefix), upper_bound(cbegin(prefix), cend(prefix), total));
        }
        return result;
    }
};
