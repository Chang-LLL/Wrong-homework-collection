/*
 * 用java自带的字典解题，遍历一遍数组，统计每个数出现的次数
 * 时间复杂度 O(n)， 空间复杂度O(n)
*/

class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> num_map = new HashMap<Integer, Integer>();
        int max = -1;
        int max_value = -1;
        for(int i = 0; i < nums.length; ++ i){
            if(num_map.get(Integer.valueOf(nums[i])) == null){
                num_map.put(Integer.valueOf(nums[i]), Integer.valueOf(1));
                if(max < 0) {
                    max = 1;
                    max_value = nums[i];
                }
            }
            else{
                int count = num_map.get(Integer.valueOf(nums[i])).intValue();
                // System.out.println("num is " + nums[i] + "count is " + count);
                if(count + 1 > max){
                    max = count + 1;
                    max_value = nums[i];
                }
                num_map.put(Integer.valueOf(nums[i]),Integer.valueOf(count + 1));
            }
        }
        // System.out.println("max is " + max);
        return max_value;
    }
}