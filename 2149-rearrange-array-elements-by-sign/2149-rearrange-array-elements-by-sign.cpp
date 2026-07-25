class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> nums1(nums.size()/2);
        vector<int> nums2(nums.size()/2);

        int j = 0, k = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                nums1[j] = nums[i];
                j++;
            }
            else{
                nums2[k] = nums[i];
                k++;
            }
        }

        vector<int> ans(nums.size());

        int a = 0, b = 0, c = 0;

        while(a < nums.size()){
            ans[a] = nums1[b];
            ans[a + 1] = nums2[c];

            a += 2;
            b++;
            c++;
        }

        return ans;
    }
};