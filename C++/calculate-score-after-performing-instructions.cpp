// Time:  O(n)
// Space: O(n)

// simulation
class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int64_t result = 0;
        vector<bool> lookup(size(instructions));
        for (int i = 0; 0 <= i && i < size(instructions);) {
            if (lookup[i]) {
                break;
            }
            lookup[i] = true;
            if (instructions[i] == "add") {
                result += values[i];
                ++i;
            } else {
                i += values[i];
            }
        }
        return result;
    }
};
