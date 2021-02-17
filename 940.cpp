#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1000000007;
        long long prev = 0;
        map<char, long long> m;
        long long current;
        for (int i = 0; i<s.length(); ++i) {
            current = (2*prev)%mod+1;
            if (m.count(s[i]) == 1) {
                current -= m[s[i]] + 1;
            }
            if (current < 0) {
                current += mod;
            }
            m[s[i]] = prev;
            current = current % mod;
            prev = current; 
        }
        return current;
    }
};
int main(){
    Solution s;
    cout << s.distinctSubseqII("zchmliaqdgvwncfatcfivphddpzjkgyygueikthqzyeeiebczqbqhdytkoawkehkbizdmcnilcjjlpoeoqqoqpswtqdpvszfaksn");    
}