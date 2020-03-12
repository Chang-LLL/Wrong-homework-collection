/*
 * 一个直观的递归思路，喜闻乐见的超时了。
*/

class Solution {
public:
    bool canWinNim(int n) {
        if(n <= 0) return true;
        if(n == 1 || n == 2 || n == 3)
            return true;
        else if(n == 4)
            return false;
        else{
            bool choose_one = canWinNim(n - 1);
            bool choose_two = canWinNim(n - 2);
            bool choose_three = canWinNim(n - 3);
            if(choose_one && choose_two && choose_three)   // I will lose
                return false;
            else return true;
        }
    }