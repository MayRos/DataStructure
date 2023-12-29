#include <vector>
using namespace std;
class Solution
{
public:
    int buyChoco(vector<int>& prices, int money)
    {
        int min_1 = prices[0] < prices[1] ? prices[0] : prices[1];
        int min_2 = prices[0] < prices[1] ? prices[1] : prices[0];
        for (int i = 2; i < prices.size(); i++) {
            if (prices[i] < min_1) {
                min_2 = min_1;
                min_1 = prices[i];
            }
            else if (prices[i]<min_2) {
                min_2 = prices[i];
            }
        }
        return (min_1 + min_2 > money) ? money : (money - (min_1 + min_2));
    }
};