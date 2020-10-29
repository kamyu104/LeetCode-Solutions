// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode dummy;
        auto curr = &dummy;
        while (poly1 && poly2) {
            if (poly1->power > poly2->power) {
                curr->next = poly1;
                curr = curr->next;
                poly1 = poly1->next;
            } else if (poly1->power < poly2->power) {
                curr->next = poly2;
                curr = curr->next;
                poly2 = poly2->next;
            } else {
                auto coef = poly1->coefficient + poly2->coefficient;
                if (coef) {
                    curr->next = new PolyNode(coef, poly1->power);
                    curr = curr->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
        curr->next = poly1 ? poly1 : poly2;
        return dummy.next;
    }
};
