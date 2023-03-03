#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
using namespace std;

class Solution
{
public:
    vector<string> getFolderNames(vector<string>& names)
    {
        vector<string> res;
        map<string,int> set_;
        for (int i = 0; i < names.size(); i++) {
            if (set_.find(names[i]) == set_.end()) {
                res.push_back(names[i]);
                set_[names[i]] = 1;
            }
            else {
                int a = set_[names[i]];
                string temp = names[i]+"("+to_string(a)+")";
                while (set_.find(temp) != set_.end()) {
                    a++;
                    temp = names[i] + "(" + to_string(a) + ")";
                }
                res.push_back(temp);
                set_[temp] = 1;
                set_[names[i]] = a + 1;
            }
        }
        return res;
    }
};
int main()
{
    vector<string> src = {"gta","gta(1)","gta","avalon"};
    Solution s;
    vector<string> res = s.getFolderNames(src);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\t";
    }
}