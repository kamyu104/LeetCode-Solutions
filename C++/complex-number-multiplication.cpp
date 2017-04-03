// Time:  O(1)
// Space: O(1)

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char op;
        stringstream ssa(a), ssb(b);
        ssa >> ra >> op >> ia;
        ssb >> rb >> op >> ib;
        string result = to_string(ra * rb - ia * ib);
        result += "+";
        result += to_string(ra * ib + rb * ia);
        result += "i";
        return result;
    }
};
