/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp {
    bool operator ()(const ListNode *p1, const ListNode *p2) const {
        return p1->val > p2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode *, vector <ListNode *>, cmp> que;
        for (int i=0, sz=lists.size ();i<sz;i++){
            if (lists[i] != NULL)    que.push (lists[i]);
        }
        ListNode *head = new ListNode (-1), *tmp = head; head->next = NULL;
        while (!que.empty ()){
            ListNode *p = que.top (); que.pop();
            tmp->next = p; tmp = tmp->next;
            if (p->next)    que.push (p->next);
        }
        return head->next;
    }
};


/*divide and conquer*/

class Solution {
public:
    ListNode *go (vector <ListNode *>& lists, int a, int b){
        if (a > b)  return NULL;
        if (a == b) return lists[a];
        int mid = (a + b)>>1;
        ListNode *left = go (lists, a, mid);
        ListNode *right = go (lists, mid+1, b);
        if (left == NULL)   return right;
        if (right == NULL)  return left;
        ListNode *res = NULL, *tmp;
        if (left->val < right->val) res = left, left=left->next;
        else                        res = right, right=right->next;
        tmp = res;
        while (left || right){
            if (left==NULL || (right!=NULL && right->val < left->val))
                tmp->next = right, right = right->next;
            else
                tmp->next = left, left = left->next;
            tmp = tmp->next;
        }
        return res;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = NULL;
        res = go (lists, 0, lists.size ()-1);
        return res;
    }
};