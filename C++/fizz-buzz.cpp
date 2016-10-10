// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;

        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) {
                result.emplace_back("FizzBuzz");
            } else if (i % 5 == 0) {
                result.emplace_back("Buzz");
            } else if (i % 3 == 0) {
                result.emplace_back("Fizz");
            } else {
                result.emplace_back(to_string(i));
            }
        }

        return result;
    }
};
