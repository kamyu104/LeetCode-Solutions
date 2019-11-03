// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x1 = 0, y1 = 0;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }
            x1 += int(s1[i] == 'x');
            y1 += int(s1[i] == 'y');
        }
        if (x1 % 2 !=  y1 % 2) {  // impossible
            return -1;
        }
        // case1: per xx or yy needs one swap, (x1 / 2 + y1 / 2) 
        // case2: per xy or yx needs two swaps, (x1 % 2 + y1 % 2)
        return x1 / 2 + y1 / 2 + x1 % 2 + y1 % 2;
    }
};
