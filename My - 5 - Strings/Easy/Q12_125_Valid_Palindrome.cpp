// Valid Palindrome : Given a string s, return true if it is a palindrome, or false otherwise.

#include <iostream>
using namespace std;

// Approach - 1 : Using two pointers
// Time Complexity : O(N) where N is the length of the string
// Space Complexity : O(1)
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            // isalnum() checks if a character is alphanumeric if it is alphabet or digit then it returns true otherwise false
            
            // Move left pointer to the next alphanumeric character
            if (!isalnum(s[left]))
            {
                left++;
            }
            // Move right pointer to the previous alphanumeric character
            else if (!isalnum(s[right]))
            {
                right--;
            }
            // tolower() converts a character to lowercase
            else if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};

// Example usage

int main()
{
    Solution solution;
    string
        s = "A man, a plan, a canal: Panama";
    bool result = solution.isPalindrome(s);
    if (result)
    {
        cout << "The given string is a palindrome" << endl;
    }
    else
    {
        cout << "The given string is not a palindrome" << endl;
    }
    return 0;
}