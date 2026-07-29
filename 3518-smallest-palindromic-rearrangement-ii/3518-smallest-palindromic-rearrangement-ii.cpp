class Solution {
public:
    const long long LIMIT = 1000000;

    long long combCap(int n, int r, long long cap) {
        r = min(r, n - r);
        long long res = 1;

        for (int i = 1; i <= r; i++) {
            long long a = n - r + i;
            long long b = i;

            long long g = gcd(a, b);
            a /= g;
            b /= g;

            g = gcd(res, b);
            res /= g;
            b /= g;

            res *= a;
            if (res >= cap) return cap;

            res /= b;
        }
        return res;
    }

    long long countWays(vector<int> &cnt, long long cap) {
        long long res = 1;
        int used = 0;

        for (int x : cnt) {
            if (x == 0) continue;

            long long cur = combCap(used + x, x, cap);
            res *= cur;
            if (res >= cap) return cap;

            used += x;
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid.push_back(char('a' + i));
        }

        if (countWays(half, LIMIT) < k)
            return "";

        int len = s.size() / 2;
        string first = "";

        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;

                long long ways = countWays(half, LIMIT);

                if (ways >= k) {
                    first.push_back(char('a' + c));
                    break;
                } else {
                    k -= ways;
                    half[c]++;
                }
            }
        }

        string second = first;
        reverse(second.begin(), second.end());

        return first + mid + second;
    }
};