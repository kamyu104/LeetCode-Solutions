// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countPoints(string rings) {
        static const unordered_map<char, int> bits = {{'R', 0b001}, {'G', 0b010}, {'B', 0b100}};

        unordered_map<int, int> rods;
        for (int i = 0; i < size(rings); i += 2) {
            rods[rings[i + 1] - '0'] |= bits.at(rings[i]);
        }
        return count_if(cbegin(rods), cend(rods), [](const auto& x) { return x.second == 0b111; });
    }
};
