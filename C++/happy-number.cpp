// Time:  O(k), where k is the steps to be happy number
// Space: O(k)

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (n != 1 && !visited.count(n)) {
            visited.emplace(n);
            n = nextNumber(n);
        }
        return n == 1;
    }

    int nextNumber(int n) {
        int sum = 0;
        while (n) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }
};
