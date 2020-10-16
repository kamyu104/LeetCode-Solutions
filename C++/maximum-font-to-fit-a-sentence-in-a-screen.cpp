// Time:  O(n + logm), n is the length of text, m is the number of fonts
// Space: O(1)

class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        vector<int> count(26);
        for (const auto& c : text) {
            ++count[c - 'a'];
        }
        int left = 0, right = size(fonts) - 1;
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (!check(count, w, h, fonts, fontInfo, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right >= 0 ? fonts[right] : -1;
    }

private:
    bool check(const vector<int>& count, int w, int h, const vector<int>& fonts, FontInfo& fontInfo, int x) {
        if (fontInfo.getHeight(fonts[x]) > h) {
            return false;
        }
        int width = 0;
        for (int c = 0; c < size(count); ++c) {
            width += count[c] * fontInfo.getWidth(fonts[x], 'a' + c);
            if (width > w) {
                return false;
            }
        }
        return true;
    }
};
