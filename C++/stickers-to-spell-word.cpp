// Time:  O(T * S^T)
// Space: O(S^T + T^2)

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>> sticker_counts(stickers.size(), vector<int>(26));
        unordered_map<string, int> dp;
        for (int i = 0; i < stickers.size(); ++i) {
            for (const auto& c : stickers[i]) {
                ++sticker_counts[i][c - 'a'];
            }
        }
        dp[""] = 0;
        return minStickersHelper(sticker_counts, target, &dp);
    }
    
private:
    int minStickersHelper(const vector<vector<int>>& sticker_counts, const string& target,
                          unordered_map<string, int> *dp) {
        if (dp->count(target)) {
            return (*dp)[target];
        }
        int result = numeric_limits<int>::max();
        vector<int> target_count(26);
        for (const auto& c : target) {
            ++target_count[c - 'a'];
        }
        for (const auto& sticker_count : sticker_counts) {
            if (sticker_count[target[0] - 'a'] == 0) {
                continue; 
            }
            string new_target;
            for (int i = 0; i < target_count.size(); ++i) {
                if (target_count[i] - sticker_count[i] > 0) {
                    new_target += string(target_count[i] - sticker_count[i], 'a' + i);
                }
            }
            if (new_target.length() != target.length()) {
                int num = minStickersHelper(sticker_counts, new_target, dp);
                if (num != -1) {
                    result = min(result, 1 + num);
                }
            }
        }
        (*dp)[target] = (result == numeric_limits<int>::max()) ? -1 : result;
        return (*dp)[target];
    }
};