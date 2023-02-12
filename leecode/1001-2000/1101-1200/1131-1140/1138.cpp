#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string alphabetBoardPath(string target) {
        char current = 'a';
        string res = "";

        for(int i=0;i<target.size();i++){
            int row = (target[i]-'a') / 5 - (current-'a') / 5;
            int col = (target[i]-'a') % 5 - (current-'a') % 5;
            if(target[i])
            while (row<0)
			{
                res += 'U';
                row++;
            }
            while (col<0)
            {
                res += 'L';
                col++;
            }
            while (col>0)
            {
                res += 'R';
                col--;
            }
            while (row>0)
            {
                res += 'D';
                row--;
            }
            res += '!';
            current = target[i];
        }
		return res;
    }

};
int main() {
    string tar = "leet";
    Solution s;
    string res= s.alphabetBoardPath(tar);
    cout << res<<"\t"<<res.compare("DDR!UURRR!!DDD!");
}