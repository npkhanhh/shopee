#include <iostream>
#include <vector>
#include <experimental/iterator>

using namespace std;

class Solution
{
public:
    void print(std::vector<int> const &input)
    {
        copy(input.begin(),
             input.end(),
             experimental::make_ostream_joiner(cout, " "));
        cout << endl;
    }

    int numDecodings(string s)
    {
        int n = s.length();
        int mod = 1000000007;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            int cur_char = s[i] - '0';
            int previous_char = s[i - 1] - '0';
            if (s[i] != '*')
            {
                if ((previous_char == 1 || previous_char == 2 && (0 <= cur_char && cur_char <= 6)))
                {
                    if (cur_char == 0)
                    {
                        dp[i] = dp[i - 1];
                    }
                    else if (i > 1)
                    {
                        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
                    }
                    else if (i == 1)
                    {
                        dp[i] = 2;
                    }
                }
                else
                {
                    dp[i] = dp[i - 1];
                }
            }
            else
            {
                
            }
        }
        print(dp);
        return dp[n - 1];
    }
};

// 11 -> 1/1 11
// 112 -> 1/1/2 11/2 1/12
// 1121 -> 1/1/2/1  11/2/1 1/12/1 11/21 1/1/21
// 1129 -> 1/1/2/9  11/2/9 1/12/9


// 1** -> 177

// 1** -> 1/*/* => 81 Axy 3 characters
//       -> 1/** => 16      Az 2 characters 
//       -> 1*/* => 81    */*
            1/1/1 11/1 1/11
1** ->              162 + 16 = 178
// ***  -> */*/* => 9*9*9 = 729
           1** + 2** + 3..9** = 999

           1*     2*    3..9*
           18      15       63
//      -> */** => 9*96 = 864
//      -> **/* => 96*9 = 864 
// dp[i] là số cách dịch string tinh tới ith

// dp[i] = 9*(dp[i-1] + dp[i-2]) if a[i-1] == 1 && a[i] == *
// dp[i] = 9*dp[i-1] + 6*dp[i-2] if  a[i-1] == 2 && a[i] == *

// dp[i] = dp[i-1] + dp[i-2] if (a[i-1]=1 and a[i]=0..9 ) || a[i-1]=2 and a[i]=0..6)
// dp[i] = dp[i-1] else

// 1151 -> 1/1/5/1 11/5/1 1/15/1
int main()
{
    Solution s;
    cout << s.numDecodings("101") << endl;
    return 0;
}