/*
��ʼʱ��?n �����ݴ��ڹر�״̬����һ�֣��㽫������е��ݡ��������ĵڶ��֣��㽫��ÿ�������ݹر�һ����

�����֣���ÿ�������ݾ��л�һ�����ݵĿ��أ������򿪱�رգ��رձ�򿪣����� i �֣���ÿ i �����ݾ��л�һ�����ݵĿ��ء�ֱ���� n �֣���ֻ��Ҫ�л����һ�����ݵĿ��ء�

�ҳ������� n?�ֺ��ж��ٸ����ŵĵ��ݡ�

?

 ʾ�� 1��



 ���룺n = 3
 �����1
 ���ͣ�
 ��ʼʱ, ����״̬ [�ر�, �ر�, �ر�].
 ��һ�ֺ�, ����״̬ [����, ����, ����].
 �ڶ��ֺ�, ����״̬ [����, �ر�, ����].
 �����ֺ�, ����״̬ [����, �ر�, �ر�].

 ��Ӧ�÷��� 1����Ϊֻ��һ�����ݻ����š�
 ʾ�� 2��

 ���룺n = 0
 �����0
 ʾ�� 3��

 ���룺n = 1
 �����1
 ?

  ��ʾ��

  0 <= n <= 109

*/
#include <vector>
using namespace std;
class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt((double)n);
        //    if (n == 0) {
        //         return 0;
        //     }
        //     int num = 0;
        //     vector<bool> light(n,false);
        //     for (int i = 1; i <= n; i++) {
        //         if (getFactor(i)) {
        //             num++;
        //         }
        //     }
        //     return num;
    }
    bool getFactor(int n) {
        bool res = false;
        if (sqrt((double)n) == (int)sqrt((double)n)) {
            res = true;
        }
        return res;
    }
};