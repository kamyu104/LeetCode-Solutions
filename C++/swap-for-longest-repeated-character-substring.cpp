// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxRepOpt1(string text) {
        static const int K = 1;
        int result = 0, max_count = 0;
        unordered_map<char, int> total_count, count;
        int left = 0;
        for (int i = 0; i < text.length(); ++i) {
            ++total_count[text[i]];
            ++count[text[i]];
            max_count = max(max_count, count[text[i]]);
            if (i - left + 1 - max_count > K) {
                --count[text[left++]];
            }
            result = max(result, min(i - left + 1, total_count[text[i]]));
        }
        return result;
    }
};
