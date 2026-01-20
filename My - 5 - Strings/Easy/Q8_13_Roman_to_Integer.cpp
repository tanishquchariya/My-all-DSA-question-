// Roman to Integer 

#include <iostream>
#include <unordered_map>
using namespace std;


// approach - 1 : Using Switch Case
// Time Complexity : O(N) where N is the length of the string
// Space Complexity : O(1)
// class Solution
// {
// public:
//     int num(char ch){
//         if(ch == 'I') return 1;
//         else if(ch == 'V') return 5;
//         else if(ch == 'X') return 10;
//         else if(ch == 'L') return 50;
//         else if(ch == 'C') return 100;
//         else if(ch == 'D') return 500;
//         else if(ch == 'M') return 1000;
//     }
//     int romanToInt(string s)
//     {
//         int total = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (i + 1 < s.size() && num(s[i]) < num(s[i + 1]))
//             {
//                 total -= num(s[i]);
//             }
//             else
//             {
//                 total += num(s[i]);
//             }
//         }
//         return total;
//     }
// };

// Approach - 2 : Using Hash Map
// Time Complexity : O(N) where N is the length of the string
// Space Complexity : O(1) as the size of the map will be at most

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int>mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

// or we can also use map<char, int>mp;
// mp['I'] = 1;
// mp['V'] = 5;
// mp['X'] = 10;
// mp['L'] = 50;
// mp['C'] = 100;
// mp['D'] = 500;
// mp['M'] = 1000;

        int total = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] < mp[s[i + 1]])
            {
                total -= mp[s[i]];
            }
            else
            {
                total += mp[s[i]];
            }
        }
        return total;
    }
};



// Example Usage
int main()
{
    Solution sol;
    string romanNumeral = "MCMXCIV";
    int integerValue = sol.romanToInt(romanNumeral);
    cout << "The integer value of the Roman numeral " << romanNumeral << " is: " << integerValue << endl;
    return 0;
}