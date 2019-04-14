// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool divisorGame(int N) {
        // 1. if we get an even, we can choose x = 1
        //    to make the opponent always get an odd
        // 2. if the opponent gets an odd, he can only choose x = 1 or other odds
        //    and we can still get an even
        // 3. at the end, the opponent can only choose x = 1 and we win
        // 4. in summary, we win if only if we get an even and 
        //    keeps even until the opponent loses
        return N % 2 == 0;
    }
};
