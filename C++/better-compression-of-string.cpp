// Time:  O(n + 26)
// Space: O(26)

// freq table, counting sort
class Solution {
public:
    string betterCompression(string compressed) {
        vector<int> cnt(26);
        for (int i = 0, x = -1, curr = 0; i < size(compressed); ++i) {
            if (!isdigit(compressed[i])) {
                x = compressed[i] - 'a';
                continue;
            }
            curr = curr * 10 + (compressed[i] - '0');
            if (i + 1 == size(compressed) || !isdigit(compressed[i + 1])) {
                cnt[x] += curr;
                curr = 0;
            }
        }
        string result;
        for (int i = 0; i < size(cnt); ++i) {
            if (!cnt[i]) {
                continue;
            }
            result.push_back('a' + i);
            result.append(to_string(cnt[i]));
        }
        return result;
    }
};
