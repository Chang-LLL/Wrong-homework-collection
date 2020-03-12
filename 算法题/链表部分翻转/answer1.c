/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:

    /*
        直接用单向链表的定义求解，需要先获知翻转子链表的头部、尾部，然后从头到尾遍历一遍。
        复杂度为 O(n)，实现复杂，容易出错。
    */
   
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* before = NULL;    // 当前局部交换之间的那个节点
        ListNode* now = head;    // 当前局部交换的头部
        ListNode* last = head;    // 正在交换的节点
        ListNode* now_before = NULL;   // 辅助节点，方便交换俩节点顺序
        ListNode* now_next = NULL;   // 辅助节点，方便交换俩节点顺序
        bool has_end = false;    // 是否不够长
        bool new_head_is_confirmed = false;
        ListNode* new_head = NULL;

        // 得到新的头结点
        if(k == 1) return head;
        while(++count < k){
            last = last->next;
            if(last == NULL) return head;
        }
        last = head;

        count = 0;
        while(1){
            while(++count < k){     // 得到当前局部交换的最后一个节点
                if(last == NULL) {
                    has_end = true;
                    break;
                } // 最后剩余节点保持原序
                else {
                    last = last->next;
                }
            }
            if(has_end || last == NULL) break;
            else{    // 开始交换
                // printf("now first is [%d], last is [%d], before is[%d]\n ", now->val, last->val, before ? before->val : -1);
                if(before != NULL) before->next = last;
                before = now;
                now_next = now->next;
                now->next = last->next;
                now_before = now;
                now = now_next;
                now_next = now->next;
                count = 0;
                while(++ count < k){
                    // printf("now handling [%d], now_before is [%d]\n", now->val, now_before->val);
                    now_next = now->next;
                    now->next = now_before;
                    now_before = now;
                    now = now_next;
                }
            }

            if(!new_head_is_confirmed){
                new_head = last;
                new_head_is_confirmed = true;
            }

            last = now;
            has_end = false;
            count = 0;

            // ListNode* test = new_head;
            // printf("%d",test->val);
            // test = test->next;
            // while(test!=NULL){
            //     printf("->%d", test->val);
            //     test = test->next;
            // }
            // printf("\n");
        }
        return new_head;
    }
};