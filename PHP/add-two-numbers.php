/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {
 /**
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function addTwoNumbers($l1, $l2) {
        $num1 = $this->listToArray($l1);
        $num2 = $this->listToArray($l2);
        $sum = bcadd($num1, $num2);
		
		$result = $this->numberToLinkedList($sum);
		
        return $result;
    }

    private function listToArray(ListNode $list): string
    {
        $output = [];

        while ($list != null) {
            $output[] = $list->val;
            $list = $list->next;
        }

        return implode('', array_reverse($output));
    }

    private function numberToLinkedList(string $number): ListNode
    {
        $arr = array_reverse(str_split($number));

        if (empty($arr)) {
            return null;
        }

        $head = new ListNode($arr[0]);
        $curr = $head;

        for ($i = 1; $i < count($arr); $i++) {
            $node = new ListNode($arr[$i]);
            $curr->next = $node;
            $curr = $node;
        }

        return $head;
    }
}