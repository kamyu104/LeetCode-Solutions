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

        // 1. we can represent each alphabet 1..26 as generating functions:
        //    G1(x) = 1 + x^1/1! + x^2/2! + x^3/3! + ... + x^count1/count1!
        //    G2(x) = 1 + x^1/1! + x^2/2! + x^3/3! + ... + x^count2/count2!
        //    ...
        //    G26(x) = 1 + x^1/1! + x^2/2! + x^3/3! + ... + x^count26/count26!
        //
        // 2. let G1(x)*G2(x)*...*G26(x) = c0 + c1*x1 + ... + ck*x^k, k is the max number s.t. ck != 0
        //    => ci (1 <= i <= k) is the number we need to divide when permuting i letters
        //    => the answer will be : c1*1! + c2*2! + ... + ck*k!
        
        vector<double> coeff(tiles.size() + 1);
        coeff[0] = 1.0;
        for (int i = 0; i < 26; ++i) {
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
            result += int(round(coeff[i] * fact[i]));
        }
        return result;
    }
};

// Time:  O(r), r is the value of result
// Space: O(n)
class Solution2 {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char,int> count;
        for (const auto& c : tiles) {
            ++count[c];
        }
        return backtracking(&count);
    }

private:
    int backtracking(unordered_map<char,int> *count) {
        int total = 0;
        for (auto& c : *count) {
            if (c.second) {
                --c.second;
                total += 1 + backtracking(count);
                ++c.second;
            }
        }
        return total;
    }
};

