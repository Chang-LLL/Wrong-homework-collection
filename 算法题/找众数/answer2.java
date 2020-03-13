/*
 * 投票算法：找众数的经典算法
 * 只需要一个“候选数”和一个计数器，每次读入一个数时，进行如下判断：
 * 若计数器的值为0，那么把候选数设为这个数；
 * 若候选数不为当前读入的数，那么计数器减一，否则计数器加一；
 * 算法的局限在于只能找到众多众数（如果存在）的一个。
 * 时间复杂度 O(n),空间复杂度O(1)
*/

class Solution {
    public int majorityElement(int[] nums) {
        int candidate = -1;
        int count = 0;
        for(int i = 0; i < nums.length; ++ i){
            if(count == 0) candidate = nums[i];
            if(candidate == nums[i]) count ++;
            else count --;
        }
        return candidate;
    }
}