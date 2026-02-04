class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for (int l = n / 2; l >= 1; l--) {
            string pattern = "";
            if (n % l == 0) {
                int time = n / l;
                while (time--) {
                    pattern += s.substr(0, l);
                }

                if (s == pattern) {
                    return true;
                }
            }
        }
        return false;
    }
};
