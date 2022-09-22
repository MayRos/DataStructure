class Solution {
public:
    int totalMoney(int n) {
        int nthWeek = n/7; // 第n周
        int nthWeekSum = 1+2+3+4+5+6;
        int sum = nthWeek*(nthWeek+1)/2*7+nthWeekSum*(nthWeek);
        int d = n-nthWeek*7;
        sum += (nthWeek)*d+d*(d+1)/2;
        return sum;
    }
};
