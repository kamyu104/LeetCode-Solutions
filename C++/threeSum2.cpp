// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            vector<vector<int> > ans;
            const int target = 0;

            sort(num.begin(), num.end());
            auto last = num.rend();
            for(auto a = num.rbegin(); a < prev(last, 2); ++a) {
                if(a > num.rbegin() && *a == *(a - 1))
                    continue;
                auto b = next(a);
                auto c = prev(last);

                while(b < c) {
                    if(b > next(a) && *b == *(b - 1)) {
                        ++b;
                    }
                    else if(c < prev(last) && *c == *(c + 1)) { 
                        --c;
                    }
                    else {
                        const int sum = *a + *b + *c;

                        if(sum < target)
                            --c;
                        else if(sum > target)
                            ++b;
                        else {
                            ans.push_back({ *c, *b, *a});
                            ++b;
                            --c;
                        }
                    }
                }
            }

            return ans;
        }
};

