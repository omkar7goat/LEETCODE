class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        char a = pattern[0];
        char b = pattern[1];
        
        long long countA = 0;
        long long countB = 0;
        long long base_matches = 0;
        
        for (char c : text) {
            // If current character is 'b', it pairs with all preceding 'a's
            if (c == b) {
                base_matches += countA;
                countB++;
            }
            // If current character is 'a', increment countA
            // (done after checking 'b' to handle the case where a == b correctly)
            if (c == a) {
                countA++;
            }
        }
        
        // Add either 'a' at index 0 (+countB) or 'b' at the end (+countA)
        return base_matches + std::max(countA, countB);
    }
};