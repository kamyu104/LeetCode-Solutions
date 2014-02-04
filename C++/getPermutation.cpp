// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
    public:
        string getPermutation(int n, int k) {
            string s(n, '0');

            for(int i = 0; i < n; ++i) {
                s[i] += i + 1;
            }

            return kth_permutation(s, k);
        }

    private:
        int factorial(int n) {
            int sum = 1;
            for(int i = n; i >= 1; --i) {
                sum *= i;
            }
            return sum;
        }

        // Cantor Encoding
        template<typename Sequence>
            Sequence kth_permutation(const Sequence &seq, int k) {
                const int n = seq.size();
                Sequence ans;
                Sequence S(seq);
                int base = factorial(n - 1);
                --k;

                for(int i = n - 1; i > 0; k %= base, base /= i, --i) {
                    auto a = next(S.begin(), k / base);
                    ans.push_back(*a);
                    S.erase(a);
                }

                ans.push_back(S[0]);

                return ans;
            }
};
