// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        static const int INF = numeric_limits<int>::max();
        int result = INF;
        for (int i = 0; i < size(words); ++i) {
            if (words[i] == target) {
                result = min(result, min(abs(i - startIndex), (abs(static_cast<int>(size(words)) - abs(i - startIndex)))));
            }
        }
        return result != INF ? result : -1;
    }
};
