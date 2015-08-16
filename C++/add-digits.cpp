// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
