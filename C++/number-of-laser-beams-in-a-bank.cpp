// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result = 0, prev = 0;
        for (const auto& x : bank) {
            const auto& cnt = count(cbegin(x), cend(x), '1');
            if (!cnt) {
                continue;
            }
            result += prev * cnt;
            prev = cnt;
        }
        return result;
    }
};
