/* 用递归的思想进行简单的计算即可得到如下结论 ：
 * 先手想要输，当且仅当石子的初始数量为4的倍数。
 * 顺便，模运算比较慢，而 a mod 4 == 0 <==> a & 3 == 0，位运算显然更快。
*/

class Solution {
public:
    bool canWinNim(int n) {
        return (n & 3) != 0;
    }
};