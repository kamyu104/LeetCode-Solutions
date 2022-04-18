// Time:  O(n + l)
// Space: O(min(n, l))

// line sweep
class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        unordered_map<int, int> cnt;
        for (int i = 0; i < size(lights); ++i) {
            ++cnt[max(lights[i][0] - lights[i][1], 0)];
            --cnt[min(lights[i][0] + lights[i][1], n - 1) + 1];
        }
        int result = 0, curr = 0;
        for (int i = 0; i < size(requirement); ++i) {
            if (cnt.count(i)) {
                curr += cnt[i];
            }
            if (curr >= requirement[i]) {
                ++result;
            }
        }
        return result;
    }
};
