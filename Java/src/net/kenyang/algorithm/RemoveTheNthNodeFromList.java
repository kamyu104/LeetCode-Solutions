public class RemoveTheNthNodeFromList {

    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode() {}
     *     ListNode(int val) { this.val = val; }
     *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     * }
     */
    public void remove_curr_node(ListNode node){
        if (node.next != null)
            node.next = node.next.next;
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode beforeList = new ListNode(0);
        beforeList.next = head;
        int size = 0;
        head = beforeList;
        ListNode tail = beforeList;
        while (size < n) {
            head = head.next;
            size ++;
        }
        while (head.next != null) {
            head = head.next;
            tail = tail.next;
        }
        remove_curr_node(tail);
        return beforeList.next;
    }
}
