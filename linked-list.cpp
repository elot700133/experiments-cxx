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

//-------------------------------------------------
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        #if 0
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr) {
            if (cur->val == val) {
                if(prev)
                {
                    prev->next = cur->next;
                    cur = cur->next;
                }
                else
                {
                    head = cur->next;
                    cur = cur->next;
                    prev = nullptr;
                }
            }
            else {
                prev = cur;
                cur = cur->next;
            }
            
        }
        return head;
        #endif
        
        //better solution
        #if 1
        ListNode* temp;

        while(head != 0 && head->val == val){

            head = head->next;
        }

        if(head == 0)
        {
            return NULL;
        }

        temp = head;

        while(temp->next != 0){

            if(temp->next->val == val){

                temp->next = temp->next->next;
            }

            else{
                temp = temp->next;
            }
        }

        return head; 
    #endif
    }
};


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        
        ListNode* odd = head;
        ListNode* even_head = head->next;
        ListNode* even = head->next;
        while(odd && even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};

// Merge two list
//requirement
// can list be empty?
// can content be other than numbers?
// are there negative number?
// what is max an min of allowed numbers?
// size of list?

// algo
// Using one loop until l1 or l2 is exhausted
// inside the loop, it will compare valu of l1 or l2, the smaller or non null value will 
// be assigned to resulting list node, then increment the node that was used or assigned.

// performance
// O(m+n)
// memory 2(m+n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        
        if (!cur1 && !cur2) {
            return nullptr;
        }
        if (!cur1 && cur2)
            return cur2;
        else if (cur1 && !cur2)
            return cur1;
        

        ListNode* cur3 = nullptr;
        ListNode* head = nullptr;
        
        if(cur1->val > cur2->val) {
            cur3 = cur2;
            cur2 = cur2->next;
        }
        else {
            cur3 = cur1;
            cur1 = cur1->next;
        }
        
        head = cur3;
        
        while(cur1 && cur2) {
            if(cur1->val > cur2->val) {
                cur3->next = cur2;
                cur3 = cur3->next;
                cur2 = cur2->next;
            }
            else {
                cur3->next = cur1;
                cur3 = cur3->next;
                cur1 = cur1->next;
            }
        }
        
        if (cur1)
            cur3->next = cur1;
        else
            cur3->next = cur2;
        
        return head;
        
    }
};

#if 0
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* r = nullptr;
        ListNode* head = nullptr;
        while(l1 != nullptr || l2 != nullptr)
        {
            int c = 0;
            
            if (l1 && l2)
            {
                if (l1->val < l2->val)
                {
                    c = l1->val;
                    l1 = l1->next;
                }
                else
                {
                    c = l2->val;
                    l2 = l2->next;
                }
            }
            else
            {
                if (l1)
                {
                    c = l1->val;
                    l1 = l1->next;
                }
                if (l2)
                {
                    c = l2->val;
                    l2 = l2->next;
                }
            }
            


            if (head == nullptr)
            {
                // first time
                head = new ListNode(c);
                r = head;
            }
            else
            {
                r->next = new ListNode(c);
                r = r->next;
            }

        }
        return head;
    }
};
#endif
