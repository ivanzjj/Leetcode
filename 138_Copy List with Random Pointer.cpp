class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)   return head;
        RandomListNode* p, *q;
        for (p=head;p!=NULL;p=p->next->next){
            q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
        }
        for (p=head;p!=NULL;p=p->next->next){
            if (p->random){
                p->next->random = p->random->next;
            }
        }
        RandomListNode *res = NULL;
        
        for (p=head;p!=NULL;p=p->next){
            if (res == NULL){
                res = q = p->next;
            }   
            else{
                q->next = p->next;
                q = q->next;
            }
            p->next = p->next->next;
        }
        q->next = NULL;
        return res;
    }
};