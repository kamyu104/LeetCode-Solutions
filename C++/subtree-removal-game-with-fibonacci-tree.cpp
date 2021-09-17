// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool findGameWinner(int n) {
        // every 6 grundy numbers in binary:
        // 0000, (XXXX+1)01, (XXXX+1)11, (((XXXX+1))^((XXXX+1)+1))10, (XXXX+1)11, (XXXX+1)11
        return n % 6 != 1;
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
