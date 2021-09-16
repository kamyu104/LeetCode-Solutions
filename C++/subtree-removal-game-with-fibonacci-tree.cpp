// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool findGameWinner(int n) {
        return n % 6 != 1;  // the cycle period is 6 observed from solution2, which could be proved by mathematical induction
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    bool findGameWinner(int n) {
        vector<int> grundy = {0, 1};
        for (int i = 2; i < n; ++i) {
            grundy[i % 2] = (grundy[(i - 1) % 2] + 1) ^ (grundy[(i - 2) % 2] + 1);
        }
        return grundy[(n - 1) % 2];  // colon principle, replace the branches by a non-branching stalk of length equal to their nim sum
    }
};
