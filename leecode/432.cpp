#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
struct MyListNode {
    string key;
    int val;
    MyListNode* next;
    MyListNode* last;
    MyListNode() : key(""),val(0), next(nullptr),last(nullptr) {}
};
class AllOne {
public:
    MyListNode* head = new MyListNode;
    MyListNode* tail = new MyListNode;
    MyListNode* ptr = head;
    AllOne() {
        head->next = tail;
        tail->last = head;
    }

    void inc(string key) {
        find(key);
        if ( ptr!= tail) {
            ptr->val = ptr->val + 1;
            while (ptr->next != tail && ptr->val > ptr->next->val )
            {
                MyListNode* pre = ptr->last;
                MyListNode* next = ptr->next;
                MyListNode* nextnext = next->next;
                pre->next = next;
                next->last = pre;
                next->next = ptr;
                ptr->last = next;
                ptr->next = nextnext;
                nextnext->last = ptr;
            }
        }
        else {
            MyListNode* thisPtr = new MyListNode;
            thisPtr->key = key;
            thisPtr->val = 1;
            MyListNode* first = head->next;
            head->next = thisPtr;
            thisPtr->last = head;
            thisPtr->next = first;
            first->last = thisPtr;
        }
    }

    void dec(string key) {
        find(key);
        ptr->val = ptr->val - 1;
        if (ptr->val == 0) {
            MyListNode* pre = ptr->last;
            MyListNode* next = ptr->next;
            pre->next = next;
            next->last = pre;
        }
        else if (ptr->last != head && ptr->val < ptr->last->val) {
            MyListNode* pre = ptr->last;
            MyListNode* prepre = pre->last;
            MyListNode* next = ptr->next;
            prepre->next = ptr;
            ptr->last = prepre;
            ptr->next = pre;
            pre->last = ptr;
            pre->next = next;
            next->last = pre;
        }
    }

    string getMaxKey() {
        if (tail->last == head) {
            return "";
        }
        else {
            return tail->last->key;
        }
    }

    string getMinKey() {
        if (head->next == tail)
        {
            return "";
        }
        else {
            return head->next->key;
        }
    }
private:
    void find(string key) {
        ptr = head;
        while (ptr != tail)
        {
            if (ptr->key == key) {
                return;
            }
            else {
                ptr = ptr->next;
            }
        }
    }
};
int main() {
    vector<string> fun = { "AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey" };
    vector<string> param = { {} ,{"hello"},{"hello"},{},{},{"leet"},{},{} };
    AllOne* a = nullptr;
    for (int i = 0; i < fun.size() && i < param.size(); i++) {
        if (fun[i] == "AllOne")
        {
            a = new AllOne();
            cout << "null  ";
        }
        else if (fun[i] == "inc")
        {
            a->inc(param[i]);
            cout << "null  ";
        }
        else if (fun[i] == "dec")
        {
            a->dec(param[i]);
            cout << "null  ";
        }
        else if (fun[i] == "getMaxKey")
        {
            cout<< a->getMaxKey()<<"  ";
        }
        else if (fun[i] == "getMinKey")
        {
            cout<< a->getMinKey()<<"  ";
        }
    }
}
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */