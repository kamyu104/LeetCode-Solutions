// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int longest = 0, start = 0, distinct_count = 0;
        array<int, 256> visited = {0};
        for (int i = 0; i < s.length(); ++i) {
            if (visited[s[i]] == 0) {
                ++distinct_count;
            }
            ++visited[s[i]];
            while (distinct_count > k) {
                --visited[s[start]];
                if (visited[s[start]] == 0) {
                    --distinct_count;
                }
                ++start;
            }
            longest = max(longest, i - start + 1);
        }
        return longest;
    }
};
