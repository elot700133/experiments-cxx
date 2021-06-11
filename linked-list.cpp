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
