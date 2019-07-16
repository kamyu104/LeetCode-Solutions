// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int result = 0, accu = 0;
        unordered_map<int, int> lookup;
        for (int i = 0; i < hours.size(); ++i) {
            accu += (hours[i] > 8) ? 1 : -1;
            if (accu > 0) {
                result = i + 1;
            } else if (lookup.count(accu - 1)) {
                // lookup[accu-1] is the leftmost idx with smaller accu,
                // because for i from 1 to some positive k,
                // lookup[accu-i] is a strickly increasing sequence
                result = max(result, i - lookup[accu - 1]);
            }
            if (!lookup.count(accu)) {
                lookup[accu] = i;
            }
        }
        return result;
    }
};
