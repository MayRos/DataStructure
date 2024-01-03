#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode* next) : val(x), next(next) { }
};
 
class Solution
{
public:
    ListNode* reverseNode(ListNode* head)
    {
        ListNode* current = head;
        ListNode* reverse = new ListNode(head->val);;
        while (nullptr!= current->next) {
            ListNode* next = new ListNode(current->next->val);
            next->next = reverse;
            reverse = next;
            current = current->next;
        }
        return reverse;
    }
    ListNode* removeNodes(ListNode* head)
    {
        head = reverseNode(head);
        ListNode* current = head;
        while (nullptr != current->next) {
            if (current->next->val < current->val) {
                current->next = current->next->next;
            }
            else {

            current = current->next;
            }
        }
        head = reverseNode(head);

        return head;
    }
    ListNode* initNodes(vector<int> nums)
    {
        ListNode* index = new ListNode(nums[0]);
        ListNode* head = index;;
        for (int i = 1; i < nums.size(); i++) {
            ListNode* temp = new ListNode(nums[i]);
            index->next = temp;
            index = index->next;
        }
        return head;
    }
    void print(ListNode* head)
    {
        ListNode* current = head;
        while (nullptr != current) {
            cout << current->val << "\t";
            current = current->next;
        }
        cout << "\n";
    }
};
int main()
{
    vector<int> a = {998,961,943,721,480,522,133,129,276,362,616,52,117,300,274,862,487,715,272,232,543,275,68,144,656,623,317,63,908,565,880,12,920,467,559,91,698};
    Solution s;
    ListNode* head = s.initNodes(a);
    s.print(head);
    ListNode* node = s.removeNodes(head);
    s.print(node);
}