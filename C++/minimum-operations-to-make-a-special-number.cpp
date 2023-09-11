// Time:  O(n)
// Space; O(1)

// math, greedy
class Solution {
public:
    int minimumOperations(string num) {
        static const string target1 = "05";
        static const string target2 = "27";

        vector<int> lookup(10);
        for (int i = size(num) - 1; i >= 0; --i) {
            if ((target1.find(num[i]) != string::npos && lookup[0]) ||
                (target2.find(num[i]) != string::npos && lookup[5])) {
                return (size(num) - i) - 2;
            }
            lookup[num[i] - '0'] = 1;
        }
        return size(num) - lookup[0];
    }
};
