// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int result = 1;
        int curr_reachable = 0, reachable = 0;
        sort(clips.begin(), clips.end());
        for (const auto& clip : clips) {
            int left = clip[0], right = clip[1];
            if (left > reachable) {
                break;
            } else if (left > curr_reachable) {
                curr_reachable = reachable;
                ++result;
            }
            reachable = max(reachable, right);
            if (reachable >= T) {
                return result;
            }
        }
        return -1;
    }
};
