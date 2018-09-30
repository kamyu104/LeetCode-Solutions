// Time:  O(n^3)
// Space: O(n^2)

class Solution {
private:
    template <typename A, typename B, typename C>
    struct TupleHash {
        size_t operator()(const tuple<A, B, C>& p) const {
            size_t seed = 0;
            A a; B b; C c;
            tie(a, b, c) = p;
            seed ^= std::hash<A>{}(a) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<B>{}(b) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<C>{}(c) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
    using Lookup = unordered_map<tuple<int, int, bool>, int, TupleHash<int, int, bool>>;

public:
    int catMouseGame(vector<vector<int>>& graph) {
        Lookup lookup;
        return move(graph, &lookup, MOUSE_START, CAT_START, true);
    }

private:
    enum Location {HOLE, MOUSE_START, CAT_START};
    enum Result {DRAW, MOUSE, CAT};

    int move(const vector<vector<int>>& graph, Lookup *lookup, int i, int other_i, bool is_mouse_turn) {
        const auto& key = make_tuple(i, other_i, is_mouse_turn);
        if (lookup->count(key)) {
            return (*lookup)[key];
        }

        (*lookup)[key] = DRAW;
        int skip, target, win, lose;
        if (is_mouse_turn) {
            tie(skip, target, win, lose) = make_tuple(other_i, HOLE, MOUSE, CAT);
        } else {
            tie(skip, target, win, lose) = make_tuple(HOLE, other_i, CAT, MOUSE);
        }
        for (const auto& nei : graph[i]) {
            if (nei == target) {
                (*lookup)[key] = win;
                return win;
            }
        }
        int result = lose;
        for (const auto& nei : graph[i]) {             
            if (nei == skip) {
                continue;
            }
            auto tmp = move(graph, lookup, other_i, nei, !is_mouse_turn);
            if (tmp == win) {
                result = win;
                break;
            }
            if (tmp == DRAW) {
                result = DRAW;
            }
        }
        (*lookup)[key] = result;
        return result;
    }
};
