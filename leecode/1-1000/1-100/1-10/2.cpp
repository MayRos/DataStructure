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
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        
        ListNode* head = new ListNode;
        ListNode* c = head;
        bool isInit = true;
        while (a!=nullptr && b!= nullptr)
        {
            if (!isInit)
            {
                ListNode* cc = new ListNode;
                c->next = cc;
                c = c->next;
            }
            isInit = false;
            int sum =c->val+ a->val + b->val;
            a = a->next;
            b = b->next;
            c->val = sum % 10;
            if (sum / 10 > 0) {
                ListNode* cc = new ListNode;
                c->next = cc;
                c = c->next;
                c->val = sum / 10;
                isInit = true;
                continue;
            }
            isInit = false;
        }
        while (a!=nullptr)
        {
            if (!isInit)
            {
                ListNode* cc = new ListNode;
                c->next = cc;
                c = c->next;
            }
            int sum = c->val + a->val;
            a = a->next;
            c->val = sum % 10;
            if (sum / 10 > 0) {
                ListNode* cc = new ListNode;
                c->next = cc;
                c = c->next;
                c->val = sum / 10;
                isInit = true;
                continue;
            }
            isInit = false;
        }
        while (b != nullptr)
        {
            if (!isInit)
            {
                ListNode* cc = new ListNode;
                c->next = cc;
                c = c->next;
            }
            int sum = c->val + b->val;
            b = b->next;
            c->val = sum % 10;
            if (sum / 10 > 0) {
                ListNode* cc = new ListNode;
                c->next = cc;
                c = c->next;
                c->val = sum / 10;
                isInit = true;
                continue;
            }
            isInit = false;
        }
        return head;
    }
};
//int main() {
//    ListNode* head1 = new ListNode;
//    ListNode* head2 = new ListNode;
//    ListNode* l1 = head1;
//    ListNode* l2 = head2;
//    const vector<int> a = { 9,9,9,9,9,9,9};
//    const vector<int> b = { 9,9,9,9 };
//    for (int i = 0; i < a.size(); i++) {
//        l1->val = a[i];
//        ListNode *aa = new ListNode;
//        l1->next = aa;
//        l1 = l1->next;
//    }
//    for (int i = 0; i < b.size(); i++) {
//        l2->val = b[i];
//        ListNode* bb = new ListNode;
//        l2->next = bb;
//        l2 = l2->next;
//    }
//    ListNode* res = Solution().addTwoNumbers(head1, head2);
//    while (res != nullptr)
//    {
//        cout << res->val<<"  ";
//        res = res->next;
//    }
//}