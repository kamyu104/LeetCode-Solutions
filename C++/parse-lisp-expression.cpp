// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int evaluate(string expression) {
        vector<string> tokens{""};
        unordered_map<string, string> lookup;
        vector<pair<vector<string>, unordered_map<string, string>>> stk;
        for (const auto& c : expression) {
            if (c == '(') {
                if (tokens[0] == "let") {
                    evaluate(tokens, &lookup);
                }
                stk.emplace_back(tokens, lookup);
                tokens = {""};
            } else if (c == ' ') {
                tokens.emplace_back("");
            } else if (c == ')') {
                const auto& val = evaluate(tokens, &lookup);
                tie(tokens, lookup) = move(stk.back());
                stk.pop_back();
                tokens.back() += val;
            } else {
                tokens.back().push_back(c);
            }
        }
        return stoi(tokens[0]);
    }

private:
    string evaluate(const vector<string>& tokens, unordered_map<string, string>* lookup) {
        static const unordered_set<string> operators{"add", "mult"};
        if (operators.count(tokens[0])) {
            const auto& a = stoi(getval(*lookup, tokens[1]));
            const auto& b = stoi(getval(*lookup, tokens[2]));
            return to_string(tokens[0] == "add" ? a + b : a * b);
        } 
        for (int i = 1; i < tokens.size() - 1; i += 2) {
            if (!tokens[i + 1].empty()) {
                (*lookup)[tokens[i]] = getval(*lookup, tokens[i + 1]);
            }
        }
        return getval(*lookup, tokens.back());
    }
    
    string getval(const unordered_map<string, string>& lookup, const string& x) {
        return lookup.count(x) ? lookup.at(x) : x;
    }
};
