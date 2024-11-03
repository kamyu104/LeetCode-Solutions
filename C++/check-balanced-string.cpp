// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    bool isBalanced(string num) {
        const auto& f = [&](int i) {
            int result = 0;
            for (; i < size(num); i += 2) {
                result += num[i] - '0';
            }
            return result;
        };

        return f(0) == f(1);
    }
};
