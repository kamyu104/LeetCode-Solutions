// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        string addBinary(string a, string b) {
            size_t carry = 0;
            string ans;

            for(auto ai = a.rbegin(), bi = b.rbegin(); ai != a.rend() || bi != b.rend();) {
                const size_t av = (ai != a.rend())? *ai - '0' : 0;
                const size_t bv = (bi != b.rend())? *bi - '0' : 0;
                const size_t val = (av + bv + carry) % 2;
                carry = (av + bv + carry) / 2;
                ans.push_back( val + '0' );

                if(ai != a.rend())
                    ++ai;
                if(bi != b.rend())
                    ++bi;
            }
            if(carry)
                ans.push_back('1');

            reverse(ans.begin(), ans.end());

            return ans;
        }
};
