class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> dp1(MAXX, false);
        vector<bool> dp2(MAXX, false);
        vector<bool> dp3(MAXX, false);

        for (int v : nums) {
            dp1[v] = true;

            vector<bool> next2 = dp2;
            for (int x = 0; x < MAXX; x++) {
                if (dp1[x])
                    next2[x ^ v] = true;
            }
            dp2 = next2;

            vector<bool> next3 = dp3;
            for (int x = 0; x < MAXX; x++) {
                if (dp2[x])
                    next3[x ^ v] = true;
            }
            dp3 = next3;
        }

        int ans = 0;
        for (bool b : dp3)
            if (b) ans++;

        return ans;
    }
};