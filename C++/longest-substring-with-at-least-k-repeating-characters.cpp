// Time:  O(26 * n) = O(n)
// Space: O(26) = O(1)

// Recursive solution.
class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstringHelper(s, k, 0, s.size());
    }

private:
    int longestSubstringHelper(const string& s, int k, int start, int end) {
        vector<int> count(26);
        for (int i = start; i < end; ++i) {
            ++count[s[i] - 'a'];
        }
        
        int max_len = 0;
        for (int i = start; i < end;) {
            while (i < end && count[s[i] - 'a'] < k) {
                ++i;
            }
            if (i == end) {
                break;
            }

            int j = i;
            while (j < end && count[s[j] - 'a'] >= k) {
                ++j;
            }
            if (i == start && j == end) {
                return end - start; 
            }

            max_len = max(max_len, longestSubstringHelper(s, k, i, j));
            i = j;
        }
        return max_len;
    }
};
