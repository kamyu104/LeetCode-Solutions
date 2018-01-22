// Time:  +:        O(d * t), t is the number of terms, d is the average degree of terms
//        -:        O(d * t)
//        *:        O(d * t^2)
//        eval:     O(d * t)
//        to_list:  O(d * tlogt)
// Space: O(e + d * t), e is the number of evalvars

class Poly {
public:
    Poly() {}
    
    Poly(const string& expr) {
        vector<string> key;
        if (is_number(expr)) {
            polies_[key] = stoi(expr);
        } else {
            key.emplace_back(expr);
            ++polies_[key];
        }
    }
    
    void update(const vector<string>& key, int val) {
        polies_[key] += val;
        if (polies_[key] == 0) {
            polies_.erase(key);
        }
    }
    
    operator vector<string>() {  // Time:  O(d * tlogt)
        map<vector<string>, int, Compare<vector<string>>> sorted(polies_.begin(), polies_.end());
        vector<string> result;
        for (const auto& kvp : sorted) {
            vector<string> tmp(kvp.first);
            tmp.emplace(tmp.begin(), to_string(kvp.second));
            result.emplace_back(join(tmp, "*"));
        }
        return result;
    }

    Poly operator+(const Poly &rhs) const {  // Time:  O(d * t)
        Poly result;
        for (const auto& kvp : polies_) {
            result.update(kvp.first, kvp.second);
        }
        for (const auto& kvp : rhs.polies_) {
            result.update(kvp.first, kvp.second);
        }
        return result;
    }

    Poly operator-(const Poly &rhs) const {  // Time:  O(d * t)
        Poly result;
        for (const auto& kvp : polies_) {
            result.update(kvp.first, kvp.second);
        }
        for (const auto& kvp : rhs.polies_) {
            result.update(kvp.first, -kvp.second);
        }
        return result;
    }

    Poly operator*(const Poly &rhs) const {  // Time:  O(d * t^2)
        Poly result;
        for (const auto& kvp1 : polies_) {
            for (const auto& kvp2 : rhs.polies_) {
                result.update(merge(kvp1.first, kvp2.first),
                              kvp1.second * kvp2.second);
            }
        }
        return result;
    }

    Poly eval(const unordered_map<string, int>& lookup) const {  // Time:  O(d * t)
        Poly result;
        for (const auto& kvp : polies_) {
            vector<string> key;
            int c = kvp.second;
            for (const auto& token : kvp.first) {
                if (lookup.count(token)) {
                    c *= lookup.at(token);
                } else {
                    key.emplace_back(token);
                }
            }
            result.update(key, c);
        }
        return result;
    }
    
private:
    bool is_number(const std::string &s) {
      return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
    }
    
    vector<string> merge(const vector<string>& arr1, const vector<string>& arr2) const {
        vector<string> result;
        int i = 0, j = 0;
        while (i < arr1.size() || j < arr2.size()) {
            if (j == arr2.size()) {
                result.emplace_back(arr1[i++]);
            } else if (i == arr1.size()) {
                result.emplace_back(arr2[j++]);
            } else if (arr1[i] < arr2[j]) {
                result.emplace_back(arr1[i++]);
            } else {
                result.emplace_back(arr2[j++]);
            }
        }
        return result;
    }
    
    string join(const vector<string>& strings, const string& delim) {
        if (strings.empty()) {
            return "";
        }
        ostringstream imploded;
        copy(strings.begin(), prev(strings.end()), ostream_iterator<string>(imploded, delim.c_str()));
        return imploded.str() + *prev(strings.end());
    }
    
    template<typename ContType>
    class Compare {
       public:
          bool operator()
              (const ContType& x,const ContType& y) {
              return x.size() != y.size() ? x.size() > y.size() : x < y;
          }
    };

    template<typename ContType>
    struct Hash {
        size_t operator()(const ContType& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<typename ContType::value_type>{}(i)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };
    
    unordered_map<vector<string>, int, Hash<vector<string>>> polies_;
};

class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, int> lookup;
        for (int i = 0; i < evalvars.size(); ++i) {
            lookup[evalvars[i]] = evalints[i];
        }
        return parse(expression).eval(lookup);
    }

private:
    Poly parse(const string& s) {
        if (s.empty()) {
            return Poly();
        }
        stack<Poly> operands;
        stack<char> operators;
        string operand;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (isalnum(s[i])) {
                operand.push_back(s[i]);
                if (i == 0 || !isalnum(s[i - 1])) {
                    reverse(operand.begin(), operand.end());
                    operands.emplace(Poly(operand));
                    operand.clear();
                }
            } else if (s[i] == ')' || s[i] == '*') {
                operators.emplace(s[i]);
            } else if (s[i] == '+' || s[i] == '-') {
                while (!operators.empty() && operators.top() == '*') {
                     compute(operands, operators);
                }
                operators.emplace(s[i]);
            } else if (s[i] == '(') {
                while (operators.top() != ')') {
                    compute(operands, operators);
                }
                operators.pop();
            }
        }
        while (!operators.empty()) {
            compute(operands, operators);
        }
        return operands.top();
    }

    template<typename T>
    void compute(stack<T>& operands, stack<char>& operators) {
        const auto left = operands.top();
        operands.pop();
        const auto right = operands.top();
        operands.pop();
        const char op = operators.top();
        operators.pop();
        if (op == '+') {
            operands.emplace(left + right);
        } else if (op == '-') {
            operands.emplace(left - right);
        } else if (op == '*') {
            operands.emplace(left * right);
        }
    }
};
