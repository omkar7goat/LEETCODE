class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int marker = s.size(); // Marks where the '9's should start

        // Traverse right to left
        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i - 1] > s[i]) {
                s[i - 1]--;
                marker = i; // Everything from index i onwards must become '9'
            }
        }

        // Fill trailing positions with '9'
        for (int i = marker; i < s.size(); i++) {
            s[i] = '9';
        }

        return stoi(s);
    }
};