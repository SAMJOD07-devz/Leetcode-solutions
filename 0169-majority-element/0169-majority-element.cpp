class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(),nums.end());
        int i = 0;
        for(i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    count++;
                    if(count>=nums.size()/2){
                        return nums[i];
                    }
                }
                else{
                    count = 0;
                }
            }
        }
        return nums[0];
    }
};