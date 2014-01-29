// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
        int longestConsecutive(vector<int> &num) {
            if (num.size() == 0)
                return 0;
            unordered_map<int, int> hash;
            int ans{1};
            for (auto &i: num) {
                if (hash[i] != 0) {
                    continue;
                }
                hash[i] = 1;
                int leftbound{hash[i - 1]}, rightbound{hash[i + 1]}; // get neighbor info
                hash[i - leftbound] = hash[i + rightbound] = 1 + leftbound + rightbound; // update left and right bound info
                ans = max(ans, 1 + leftbound + rightbound);
            }
            return ans;
        }
};
