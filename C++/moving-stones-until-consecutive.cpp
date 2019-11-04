// Time:  O(1)
// Space: O(1)

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> s = {a, b, c};
        sort(s.begin(), s.end());
        if (s[0] + 1 == s[1] && s[1] + 1 == s[2]) {
            return {0, 0};
        }
        return {(s[0] + 2 >= s[1] || s[1] + 2 >= s[2]) ? 1 : 2,
                s[2] - s[0] - 2};
    }
};

// Time:  O(1)
// Space: O(1)
class Solution2 {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> stones = {a, b, c};
        sort(stones.begin(), stones.end());
        int left = 0, min_moves = numeric_limits<int>::max();
        int max_moves = stones.back() - stones.front() - (stones.size() - 1);
        for (int right = 0; right < stones.size(); ++right) {
            while (stones[right] - stones[left] + 1 > stones.size()) {  // find window size <= len(stones)
                ++left;
            }
            min_moves = min(min_moves, static_cast<int>(stones.size()) - (right - left + 1));
        }
        return {min_moves, max_moves};
    }
};
