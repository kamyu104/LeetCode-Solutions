// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            int ans = 0;
            int gap = INT_MAX;

            sort(num.begin(), num.end());
            auto last = num.end();
            for(auto a = num.begin(); a != prev(last, 2); a++) {
                auto b = next(a);
                auto c = prev(last);

                while(b != c) {
                    const int sum = *a + *b + *c;

                    if(gap > abs(target - sum)) {
                        gap = abs(target - sum);
                        ans = sum;
                    }
                    if(sum < target)
                        ++b;
                    else
                        --c;
                }
            }

            return ans;
        }
};
