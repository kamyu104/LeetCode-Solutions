// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int result = 0, prev = 0;
        for (const auto& curr : rungs) {
            result += ceil_divide(curr - prev, dist) - 1;
            prev = curr;
        }
        return result;
    }

private:
    int ceil_divide(int a, int b) {
        return (a + (b - 1)) / b;
    }
};
