// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        static const string S = "croak";
        vector<int> lookup(5);
        int result = 0;
        for (const auto& c : croakOfFrogs) {
            int i = S.find(c);
            ++lookup[i];
            if (lookup[(i - 1 + lookup.size()) % lookup.size()]) {
                --lookup[(i - 1 + lookup.size()) % lookup.size()];
            } else if (i == 0) {
                ++result;
            } else {
                return -1;
            }
        }
        return result == lookup.back() ? result : -1;
    }
};
