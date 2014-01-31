// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            vector<int> last(26, -1);
            int start = 0;
            int ans = 0;

            for(int i = 0; i < s.size(); ++i) {
                if(last[s[i] - 'a'] >= start) {     // meet a repeated character
                    ans = max(i - start, ans);      // recount max length of substring
                    start = last[s[i] - 'a'] + 1;   // update start index next to the repeated one
                }
                last[s[i] - 'a'] = i;               // update last index
            }

            return max(static_cast<int>(s.size()) - start, ans); // recount max length of substring due to end
        }
};
