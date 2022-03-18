#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class CQueue {
public:
    stack<int>  a;
    stack<int>  b;
    CQueue() {
        while (!a.empty())
        {
            a.pop();
        }
        while (!b.empty())
        {
            b.pop();
        }
    }

    void appendTail(int value) {
        a.push(value);
    }

    int deleteHead() {
        if (b.empty()) {
            while (!a.empty())
            {
                b.push(a.top());
                a.pop();
            }
        }

        if (b.empty()) {
            return -1;
        }
        int i = b.top();
        b.pop();
        return i;
    }
};

//int main() {
//    vector<string> in1 = { "CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead" };
//    vector<int> in2 = { {} ,{},{5},{2},{},{} };
//    
//    CQueue a; 
//    for (int i = 0; i < in1.size(); i++)
//    {
//        
//        if (in1[i] == "CQueue") {
//            a = CQueue();
//            cout << "null  ";
//        }
//        else if (in1[i] == "appendTail") {
//            a.appendTail(in2[i]);
//            cout << "null  ";
//        }
//        else if (in1[i] == "deleteHead") {
//            cout << a.deleteHead() << "  ";
//        }
//    }
//    //cout << "hello";
//}