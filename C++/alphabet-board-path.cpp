// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string alphabetBoardPath(string target) {
        string result;
        int x = 0, y = 0;
        for (const auto& c : target) {
            int x1 = (c - 'a') % 5, y1 = (c - 'a') / 5;
            result += string(max(y - y1, 0), 'U');
            result += string(max(x - x1, 0), 'L');
            result += string(max(x1 - x, 0), 'R');
            result += string(max(y1 - y, 0), 'D');
            result += "!";
            x = x1, y = y1;
        }
        return result;
    }
};
