// Time:  O(n * (logn)^2)
// Space: O(n)

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(rbegin(tasks), rend(tasks));
        sort(begin(workers), end(workers));
        int left = 1, right = min(size(tasks), size(workers));
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (!check(tasks, workers, pills, strength, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    bool check(const vector<int>& tasks, const vector<int>& workers,
               int pills, int strength,
               int x) {

        multiset<int> w(cbegin(workers) + (size(workers) - x), cend(workers));
        for (int i = size(tasks) - x; i < size(tasks); ++i) {
            auto it = w.lower_bound(tasks[i]);
            if (it != end(w)) {
                w.erase(it);
                continue;
            }
            if (pills) {
                it = w.lower_bound(tasks[i] - strength);
                if (it != end(w)) {
                    w.erase(it);
                    --pills;
                    continue;
                }
            }
            return false;
        }
        return true;
    }
};
