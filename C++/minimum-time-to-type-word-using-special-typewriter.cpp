// Time:  O(n)
// Space; O(1)

class Solution {
public:
    int minTimeToType(string word) {
        int result = 0;
        char prev = 'a';
        for (const auto& c : word) {
            result += min(abs(c - prev), 26 - abs(c - prev)) + 1;
            prev = c;
        }
        return result;
    }
};
