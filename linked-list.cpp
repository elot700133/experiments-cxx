//==============================================================
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

//========================================================================
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

//===============================================================================
// Intersection of Two Linked Lists
// Given the heads of two singly linked-lists headA and headB, 
// return the node at which the two lists intersect. 
// If the two linked lists have no intersection at all, return null.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // brute force
        #if 0
        // O(M*N)
        // O(1)
        ListNode* pA = headA;
        while(pA != nullptr) {
            ListNode* pB = headB;
            while(pB != nullptr) {
                if(pA == pB) return pA;
                pB = pB->next;
            }
            pA = pA->next;
        }
        return nullptr;
        #endif
        
        // hash table
        #if 0
        // O(M+N)
        // O(M)
        std::map<ListNode*,bool> mapA,mapB;
        ListNode* pA = headA;
        while(pA != nullptr) {
            mapA[pA] = true;
            pA = pA->next;
        }
        ListNode* pB = headB;
        while(pB != nullptr) {
            if(mapA.find(pB) != mapA.end()) return pB;
            pB = pB->next;
        }
        return nullptr;
        #endif
        
        // two pointer approach
        ListNode* pA = headA;
        int lenA = 0;
        while(pA != nullptr) {
            lenA++;
            pA = pA->next;
        }
        ListNode* pB = headB;
        int lenB = 0;
        while(pB != nullptr) {
            lenB++;
            pB = pB->next;
        }

        if (lenA > lenB) {
            return helper(headA, headB, lenA, lenB);
        }
        else {
            return helper(headB, headA, lenB, lenA);
        }
        return nullptr;
    }
    
    ListNode* helper(ListNode* headLong, ListNode* headShort, int lenLong, int lenShort) {
            ListNode* pLong = headLong;
            int diff = lenLong - lenShort;
            int i = 0;
            while(pLong != nullptr) {
                i++;
                if(i-1 == diff) {
                    break;
                }
                pLong = pLong->next;
            }
            
            ListNode* pShort = headShort;
            while(pLong != nullptr) {
                if (pLong == pShort) return pShort;
                pLong = pLong->next;
                pShort = pShort->next;
            }
        return nullptr;
    }
};


//====================================================
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

// recursive
ListNode* reverseList(ListNode* head) {
    return recursive(nullptr, head);
}
ListNode* recursive(ListNode* prev, ListNode* cur) {
    if(cur == nullptr) {
        return prev;
    }

    ListNode* next = cur->next;
    cur->next = prev;

    return recursive(cur, next);
}
