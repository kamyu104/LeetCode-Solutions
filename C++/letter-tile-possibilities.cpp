// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<double> fact(tiles.size() + 1);
        fact[0] = 1.0;
        for (int i = 1; i < fact.size(); ++i) {
            fact[i] = fact[i - 1] * i;
        }
        vector<int> count(26);
        for (const auto& c : tiles) {
            ++count[c - 'A'];
        }

        // we can represent each alphabet 1..26 as generating functions:
        //   G1(x) = 1 + x^1/1! + x^2/2! + x^3/3! + ... + x^num1/num1!
        //   G2(x) = 1 + x^1/1! + x^2/2! + x^3/3! + ... + x^num2/num2!
        //   ...
        //   G26(x) = 1 + x^1/1! + x^2/2! + x^3/3! + ... + x^num26/num26!
        //
        // let G1(x)*G2(x)*...*G26(x) = c0 + c1*x1 + ... + ck*x^k, k is the max number s.t. ck != 0
        // => ci (1 <= i <= k) is the number we need to divide when permuting i letters
        // => the answer will be : c1*1! + c2*2! + ... + ck*k!
        
        vector<double> coeff(tiles.size() + 1);
        for (int i = 0; i <= count[0]; ++i) {
            coeff[i] = 1.0 / fact[i];
        }
        for (int i = 1; i < 26; ++i) {
            vector<double> new_coeff(coeff.size());
            for (int j = 0; j < coeff.size(); ++j) {
                for (int k = 0; k <= count[i]; ++k) {
                    if (k + j >= new_coeff.size()) {
                        break;
                    }
                    new_coeff[j + k] += coeff[j] * 1.0 / fact[k]; 
                }
            }
            coeff = move(new_coeff);
        }

        int result = 0;
        for (int i = 1; i < coeff.size(); ++i) {
            result += coeff[i] * fact[i];
        }
        return result;
    }
};
