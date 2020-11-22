// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(begin(tasks), end(tasks),
             [](const auto& a, const auto& b) {
                 return a[1] - a[0] < b[1] - b[0];  // sort by waste in asc
             });
        int result = 0;
        // you can see proof here, https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/discuss/944633/Explanation-on-why-sort-by-difference
        for (const auto& task : tasks) {  // we need to pick all the wastes, so greedily to pick the least waste first is always better
            result = max(result + task[0], task[1]);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(begin(tasks), end(tasks),
             [](const auto& a, const auto& b) {
                 return a[1] - a[0] > b[1] - b[0];  // sort by save in desc
             });
        int result = 0, curr = 0;
        for (const auto& task : tasks) {  // we need to pick all the saves, so greedily to pick the most save first is always better
            result += max(task[1] - curr, 0);
            curr = max(curr, task[1]) - task[0];
        }
        return result;
    }
};
