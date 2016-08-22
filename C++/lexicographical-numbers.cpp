// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
 
        for (int i = 1, num = 1; result.size() < n; i = num + 1) {
            for (int k = 0; i * pow(10, k) <= n; ++k) {
                result.emplace_back(i * pow(10, k));
            }

            for (num = result.back() + 1; num <= n && num % 10; ++num) {
                result.emplace_back(num);
            }

            if (num % 10 == 0) {
                --num;
            } else {
                num /= 10;
            }

            while (num % 10 == 9) {
                num /= 10;
            }
        }

        return result;
    }
};
