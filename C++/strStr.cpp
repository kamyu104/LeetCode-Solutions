// Time Complexity: O(m + n)
// Space Complexity: O(n)

class Solution {
    public:
        char *strStr(char *haystack, char *needle) {
            string target(haystack);
            string pattern(needle);

            if(target.size() < pattern.size())
                return nullptr;

            if(pattern.size() == 0)
                return haystack;

            int i = kmp(target, pattern);

            return (i != -1)? haystack + i : nullptr;
        }
    private:
        int kmp(const string &target, const string &pattern) {
            const auto m = target.size();
            const auto n = pattern.size();

            vector<int> failure(n, -1);
            for(int i = 1, j = -1; i < n; ++i) {
                while(j >= 0 && pattern[j + 1] != pattern[i])
                    j = failure[j];
                if(pattern[j + 1] == pattern[i])
                    ++j;
                failure[i] = j;
            }

            for(int i = 0, j = -1; i < m; ++i) {
                while(j >= 0 && pattern[j + 1] != target[i])
                    j = failure[j];
                if(pattern[j + 1] == target[i])
                    ++j;
                if(j == n - 1) {
                    return i - j;
                }
            }

            return -1;
        }
};
