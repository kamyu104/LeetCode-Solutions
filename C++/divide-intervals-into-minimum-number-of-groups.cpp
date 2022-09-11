// Time:  O(nlogn)
// Space: O(n)

// sort, line sweep
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> events;
        for (const auto& i : intervals) {
            ++events[i[0]];
            --events[i[1] + 1];
        }
        int result = 0, curr = 0;
        for (const auto& [t, d] : events) {
            curr += d;
            result = max(result, curr);
        }
        return result;
    }
};
