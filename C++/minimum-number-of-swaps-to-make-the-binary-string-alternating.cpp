// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minSwaps(string s) {
        int ones = count(cbegin(s), cend(s), '1');
        int zeros = size(s) - ones;
        if (abs(ones - zeros) > 1) {
            return -1;
        }
        if (ones > zeros) {
            return cost(s, 1);
        }
        if (ones < zeros) {
            return cost(s, 0);
        }
        return min(cost(s, 1), cost(s, 0));
    }

private:
    int cost(const string& s, int x) {
        int diff = 0;
        for (const auto& c : s) {
            diff += (c - '0' != x);
            x ^= 1;
        }
        return diff / 2;
    }
};
