// Time:  O(n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{}
	current, carry := dummy, 0

	for l1 != nil || l2 != nil {
		val := carry
		if l1 != nil {
			val += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			val += l2.Val
			l2 = l2.Next
		}
		carry, val = val / 10, val % 10
		current.Next = &ListNode{Val: val}
		current = current.Next
	}

	if carry == 1 {
		current.Next = &ListNode{Val: 1}
	}

	return dummy.Next
}
