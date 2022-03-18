#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int minimumOperations(string leaves) {
        int length = leaves.length();
        int str = 0;
        int num_of_1 = 0;
        for (int i = 0; i < length; i++)
        {
            if (leaves[i] == 'r') {
                uint64_t ii = 1;
                str =str + (ii << i);
                num_of_1++;
            }
        }
        int sum = 0;
        // ��[0,i]��(i,j)��[j,n-1]
        for (int i = 0; i < length; i++)
        {
            int y1 = 0;                                // ���1�ĸ���
            int left = str >> (length - 1 - i);        // ����ֵ
            while (left) {                             // ��left��1�ĸ���y1
                y1 += left % 2;
                left = left >> 1;
            }
            for (int j = length-1; j >i+1; j--) {
                int y2 = 0;                             // �Ҳ�1�ĸ���
                int right = str;
                for (int k = 0; k < (length - j); k++) {
                    y2 += right % 2;
                    right = right >> 1;
                }
                int r1 = j - i - 1 - (num_of_1 - y1 - y2);
                int temp = y1 + y2 + r1;
                sum = temp > sum ? temp : sum;
            }
            
        }
        return length-sum;
    }
};
int main() {
    string str = "ryyryyyrryyyyyryyyrrryyyryryyyyryyrrryryyyryrryrrrryyyrrrrryryyrrrrryyyryyryrryryyryyyyryyrryrryryy";
    cout << Solution().minimumOperations(str);

}