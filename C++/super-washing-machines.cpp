// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % machines.size() != 0) {
            return -1;
        }
        
        int result = 0, target = sum / machines.size(), curr = 0;
        for (const auto& n : machines) {
            curr += n - target;
            result = max(result, max(n - target, abs(curr)));
        }
        return result;
    }
};
