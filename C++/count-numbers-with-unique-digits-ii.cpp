// Time:  O(blogb)
// Space: O(1)

// hash table
class Solution {
public:
    int numberCount(int a, int b) {
        const auto& check = [](int x) {
            int lookup = 0;
            for (; x; x /= 10) {
                if (lookup & (1 << (x % 10))) {
                    return false;
                }
                lookup |= 1 << (x % 10);
            }
            return true;
        };

        int result = 0;
        for (; a <= b; ++a) {
            result += check(a);
        }
        return result;
    }
};
