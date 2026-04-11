// Time:  O(nlogn)
// Space: O(n)

// sort, binary search
class Solution {
public:
    int maximumTeamSize(vector<int>& startTime, vector<int>& endTime) {
        vector<int> sorted_start(startTime);
        ranges::sort(sorted_start);
        vector<int> sorted_end(endTime);
        ranges::sort(sorted_end);
        int result = 0;
        for (int i = 0; i < size(startTime); ++i) {
            const int left = distance(cbegin(sorted_end), lower_bound(cbegin(sorted_end), cend(sorted_end), startTime[i]));
            const int right = distance(cbegin(sorted_start), upper_bound(cbegin(sorted_start), cend(sorted_start), endTime[i]));
            result = max(result, right - left);
        }
        return result;
    }
};
