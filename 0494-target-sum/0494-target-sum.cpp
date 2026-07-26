class Solution {
public:

    int solve(int index, int sum, vector<int>& nums, int target)
    {
        if(index == nums.size())
        {
            return (sum == target);
        }

        int plus = solve(index + 1, sum + nums[index], nums, target);

        int minus = solve(index + 1, sum - nums[index], nums, target);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        return solve(0, 0, nums, target);
    }
};