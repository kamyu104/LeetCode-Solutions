package leetcode

// ListNode represents a non-negative number.
// You are given two linked lists representing two non-negative numbers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	results := &ListNode{}
	node := results
	node1 := l1
	node2 := l2

	overten := false

	for node1 != nil || node2 != nil {

		tmp := 0

		if node1 != nil {
			tmp = tmp + node1.Val
			node1 = node1.Next
		}

		if node2 != nil {
			tmp = tmp + node2.Val
			node2 = node2.Next
		}
		if overten {
			tmp++
		}

		if tmp >= 10 {
			overten = true
			tmp -= 10
		} else {
			overten = false
		}

		node.Val = tmp

		if node1 != nil || node2 != nil {
			node.Next = &ListNode{}
			node = node.Next
		}
	}

	if overten {
		node.Next = &ListNode{}
		node = node.Next
		node.Val = 1
	}

	return results
}
