// Time:  O(n * (logn)^2)
// Space: O(n)

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        for (const auto& i : deck) {
            ++count[i];
        }
        int result = 0;
        for (const auto& kvp : count) {
            result = gcd(result, kvp.second);
        }
        return result > 1;
    }

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
};
