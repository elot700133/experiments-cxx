// reverse a singly linked list
ListNode* reverseList(ListNode* head) {
    // iterative
    // keep 3 pointers
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* cur = head;
    while(cur != nullptr) {
        next = cur->next;

        cur->next = prev;

        // advance prev and cur one step forward.
        prev = cur;
        cur = next;
    }
    return prev;
}
// reverse a singly linked list, for loop style
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* cur = head;
    for(; cur!=nullptr; prev=cur, cur=next) {
        next = cur->next;
        cur->next = prev;
    }
    return prev;
}

// template for using two pointers techniques
// can find cycling link list
bool twoPointersTemplateExample{
    // Initialize slow & fast pointers
    ListNode* slow = head;
    ListNode* fast = head;
    /**
     * Change this condition to fit specific problem.
     * Attention: remember to avoid null-pointer error
     **/
    while (slow && fast && fast->next) {
        slow = slow->next;          // move slow pointer one step each time
        fast = fast->next->next;    // move fast pointer two steps each time
        if (slow == fast) {         // change this condition to fit specific problem
            return true;
        }
    }
    return false;   // change return value to fit specific problem
}

// remove nth node from the end of singly linked list
// need clean up
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p1 = head;
    ListNode* p2 = head;
    int i=0;
    while(p1 != nullptr) {
        i++;

        if (i >= n+2) {
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    if (n < i)
        p2->next = p2->next->next;
    else if (n==i)
        if (i!=1)
            head = head->next;
        else
            head = nullptr;


    //printf("p2 = %d\n",p2->val);
    //printf("i = %d\n",i);
    return head;
}
