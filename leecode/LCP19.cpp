#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int minimumOperations(string leaves) {
        int length = leaves.length();
        //int str = 0;
        int num_of_1 = 0;
        for (int i = 0; i < length; i++)
        {
            if (leaves[i] == 'r') {
               // uint64_t ii = 1;
               // str =str + (ii << i);
                num_of_1++;
            }
        }
        int sum = 0;
        // ��[0,i]��(i,j)��[j,n-1]
        for (int i = 1; i < length; i++)
        {
            int y1 = 0;                                // ���r�ĸ���
            for (int k = 0; k < i;k++) {               
                if(leaves[k]=='r')
                y1++;
            }
            for (int j = length-1; j >i; j--) {
                int y2 = 0;                             // �Ҳ�1�ĸ���
                
                for (int k = 0; k < (length - j); k++) {
                    if (leaves[j - k]);
                    y2++;
                }
                int r1 = j - i - (num_of_1 - y1 - y2);
                int temp = y1 + y2 + r1;
                sum = temp > sum ? temp : sum;
            }
            
        }
        return length-sum;
    }
};
int main() {
    //string str = "ryyryyyrryyyyyryyyrrryyyryryyyyryyrrryryyyryrryrrrryyyrrrrryryyrrrrryyyryyryrryryyryyyyryyrryrryryy";
    string str = "yry";
    cout << Solution().minimumOperations(str);

}