#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* detectCycle(ListNode* A) {
    if(A->next == nullptr)return nullptr;
    ListNode *fast = A, *slow = A, *ptr;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)break;
        
    }
    if(fast==nullptr || fast->next==nullptr)return nullptr;
    slow = A;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
    
}

int main(){
    ListNode* A = nullptr;

    // generate a linked list with cycle in it.
    // The algorithm returns the beginning of the
    // cycle. If there is no cycle then it returns.
    // NULL

    ListNode* ans = detectCycle(A);

    return 0;
}