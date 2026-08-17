// Time:  O(r), r = len(requests)
// Space: O(1)

// array
class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int result = requests[0];
        for (int i = 0; i + 1 < size(requests); ++i) {
            result += abs(requests[i + 1] - requests[i]);
        }
        return result;
    }
};
