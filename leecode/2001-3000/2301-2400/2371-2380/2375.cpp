/*
* 
给你下标从 0 开始、长度为 n 的字符串 pattern ，它包含两种字符，'I' 表示 上升 ，'D' 表示 下降 。

你需要构造一个下标从 0 开始长度为 n + 1 的字符串，且它要满足以下条件：

num 包含数字 '1' 到 '9' ，其中每个数字 至多 使用一次。
如果 pattern[i] == 'I' ，那么 num[i] < num[i + 1] 。
如果 pattern[i] == 'D' ，那么 num[i] > num[i + 1] 。
请你返回满足上述条件字典序 最小 的字符串 num。

 

示例 1：
输入：pattern = "IIIDIDDD"
输出："123549876"
解释：
下标 0 ，1 ，2 和 4 处，我们需要使 num[i] < num[i+1] 。
下标 3 ，5 ，6 和 7 处，我们需要使 num[i] > num[i+1] 。
一些可能的 num 的值为 "245639871" ，"135749862" 和 "123849765" 。
"123549876" 是满足条件最小的数字。
注意，"123414321" 不是可行解因为数字 '1' 使用次数超过 1 次。
示例 2：

输入：pattern = "DDD"
输出："4321"
解释：
一些可能的 num 的值为 "9876" ，"7321" 和 "8742" 。
"4321" 是满足条件最小的数字。
 

提示：

1 <= pattern.length <= 8
pattern 只包含字符 'I' 和 'D' 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/construct-smallest-number-from-di-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <map>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char> res_set;
        res_set.push('9'); res_set.push('8'); res_set.push('7'); res_set.push('6'); res_set.push('5');
        res_set.push('4'); res_set.push('3'); res_set.push('2'); res_set.push('1');
		stack<char> temp_set;
		map<char, int > c = {
            {'I', 1},
            { 'D',-1 }
        };
		string res = "";
		for (int i = 0; i < pattern.size(); i++) {
			temp_set.push(res_set.top());
			res_set.pop();
			if (c[pattern[i]] > 0 ) {
				
				while (!temp_set.empty())
				{
					res += temp_set.top();
					temp_set.pop();
				}
			}
			if (i + 1 == pattern.size()) {
				temp_set.push(res_set.top());
				res_set.pop();
				while (!temp_set.empty())
				{
					res += temp_set.top();
					temp_set.pop();
				}
			}
        }
        return res;
    }
};
//int main() {
//    Solution s;
//    string str = "IIIDIDDD";
//    cout<<s.smallestNumber(str);
//}