// Time:  O(1)
// Space: O(1)

// greedy
class Solution {
public:
    int convertTime(string current, string correct) {
        static vector<int> OPS = {60, 15, 5, 1};
        int diff = (stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3))) -
                   (stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3)));
        int result = 0;
        for (const auto& x : OPS) {
            const int q = diff / x;
            diff %= x;
            result += q;
        }
        return result;
    }
};
