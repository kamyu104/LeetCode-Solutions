// Time:  O(2 * (1 + (9/49) + (9/49)^2 + ...)) = O(2/(1-(9/49)) = O(2.45)
// Space: O(1)

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (true) {
            int x = (rand7() - 1) * 7 + (rand7() - 1);
            if (x < 40) {
                return x % 10 + 1;
            }
        }
    }
};
