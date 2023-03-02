#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string printBin(double num) {
        string res = "0.";
        double a = 1*0.5;
        while (num > 0 && res.size() <=32)
        {
            num *= 2;
            if (num >= 1) {
                res += "1";
                num -= 1;
            }
            else
            {
                res += "0";
            }
        }
        if (num == 0) {
            return res;
        }
        return "ERROR";
    }
};
int main() {
    Solution s;
    cout<<s.printBin(0.1);
}