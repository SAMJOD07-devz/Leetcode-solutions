#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // last[j] stores the largest index in word1 from which 
        // the suffix word2[j...m-1] can be matched as a subsequence.
        vector<int> last(m + 1, -1);
        last[m] = n;
        
        int ptr = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            if (ptr >= 0) {
                last[j] = ptr;
                ptr--; // move to previous index for next character match
            } else {
                break;
            }
        }
        
        vector<int> result;
        bool changed = false;
        int i = 0;
        
        for (int j = 0; j < m; ++j) {
            while (i < n) {
                // Scenario 1: Exact match
                if (word1[i] == word2[j]) {
                    result.push_back(i);
                    i++;
                    break;
                }
                // Scenario 2: Mismatch, but we haven't used our single change yet
                else if (!changed && last[j + 1] > i) {
                    changed = true;
                    result.push_back(i);
                    i++;
                    break;
                }
                // Scenario 3: Mismatch and we cannot change word1[i], so skip word1[i]
                i++;
            }
        }
        
        if (result.size() == m) {
            return result;
        }
        return {};
    }
};