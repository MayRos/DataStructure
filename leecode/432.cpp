#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//using namespace std;
class AllOne {
    unordered_map<string, list<pair<unordered_set<string>, int>>::iterator> m;
    list<pair<unordered_set<string>, int>> list;
public:
    AllOne() {}

    void inc(string key) {
    }

    void dec(string key) {
    }

    string getMaxKey() {
    }

    string getMinKey() {
    }
private:
    
};
//int main() {
//    vector<string> fun = { "AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey" };
//    vector<string> param = { {} ,{"hello"},{"hello"},{},{},{"leet"},{},{} };
//    AllOne* a = nullptr;
//    for (int i = 0; i < fun.size() && i < param.size(); i++) {
//        if (fun[i] == "AllOne")
//        {
//            a = new AllOne();
//            cout << "null  ";
//        }
//        else if (fun[i] == "inc")
//        {
//            a->inc(param[i]);
//            cout << "null  ";
//        }
//        else if (fun[i] == "dec")
//        {
//            a->dec(param[i]);
//            cout << "null  ";
//        }
//        else if (fun[i] == "getMaxKey")
//        {
//            cout<< a->getMaxKey()<<"  ";
//        }
//        else if (fun[i] == "getMinKey")
//        {
//            cout<< a->getMinKey()<<"  ";
//        }
//    }
//}
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */