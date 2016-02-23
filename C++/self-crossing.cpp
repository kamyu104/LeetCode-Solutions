// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() >= 5 && x[3] == x[1] && x[4] + x[0] >= x[2]) {
            // Crossing in a loop:
            //     2
            // 3 ┌────┐
            //   └─══>┘1
            //   4  0  (overlapped)  
            return true;
        }

        for (int i = 3; i < x.size(); ++i) {
            if (x[i] >= x[i - 2] && x[i - 3] >= x[i - 1]) {
                // Case 1:
                //    i-2
                // i-1┌─┐
                //    └─┼─>i
                //     i-3
                return true;
            } else if (i >= 5 && x[i - 4] <= x[i - 2] && x[i] + x[i - 4] >= x[i - 2] &&
                       x[i - 1] <= x[i - 3] && x[i - 1] + x[i - 5] >= x[i - 3]) {
                // Case 2:
                //    i-4
                //    ┌──┐ 
                //    │i<┼─┐
                // i-3│ i-5│i-1
                //    └────┘
                // i-2
                return true;
            }
        }
        return false;
    }
};
