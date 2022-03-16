#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
struct ListNode {
    string key;
    int val;
    ListNode* next;
    ListNode* last;
    ListNode() : key(""),val(0), next(nullptr),last(nullptr) {}
    /*ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}*/
};
class AllOne {
public:
    unordered_map<string,int> unorder_map;
    map<int, vector<string>> order_map;
    AllOne() {
        //cout << "init" << endl;
    }

    void inc(string key) {
        if (unorder_map.find(key) != unorder_map.end()) {
            int n = unorder_map[key];
            unorder_map[key] = n + 1;
            order_map[n].erase(order_map[n].)
        }
        else {
            unorder_map[key] = 1;
            order_map[1].push_back(key);
        }
    }

    void dec(string key) {
        unorder_map[key] = unorder_map[key] - 1;
        if (unorder_map[key] == 0) {

        }
    }

    string getMaxKey() {
        cout << "getMAxKey" << endl;
        return "max";
    }

    string getMinKey() {
        cout << "getMinKey" << endl;
        return "min";
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