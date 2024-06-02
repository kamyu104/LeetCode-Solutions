// Time:  O(nlogn)
// Space: O(1)

// sort
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        int result = 0, curr = 0;
        for (const auto& m : meetings) {
            result += max((m[0] - 1) - curr, 0);
            curr = max(curr, m[1]);
        }
        result += max(days - curr, 0);
        return result;
    }
};
