#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    string add(string num1, string num2) {
        
        if (num2.length()>num1.length()) {
            string temp;
            num1 = temp;
            num1 = num2;
            num2 = temp;
            
        }
        int n1 = num1.length();
        int n2 = num2.length();
        for (int i = 0;i<(n1-n2);++i) {
            num2 = "0"+num2;
        }
        string res = "";
        int carry = 0;
        for (int i=n1-1; i>-1; i--){
            int cur = num1[i] - '0';
            cur += num2[i] - '0';
            cur += carry;
            carry = 0;
            if (cur >= 10 && i > 0) {
                carry = 1;
                cur = cur % 10;
            }
            res = to_string(cur)+res;
        }
        return res;
    }

    string sum_string(vector<string> v) {
        string res = "0";
        for(auto ele : v) {
            res = add(ele, res);
        }
        return res;
    }
    string simplified(string s){
        int i=0;
        for (; i<s.length()-1; i++){
            if (s[i]!='0'){
                break;
            }
        }
        return s.substr(i);
    }
    
    string multiply(string num1, string num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        vector<string> result;

        for (int i=n1-1; i>-1; i--){
            int tt = n1-1 - i;
            string tem(tt, '0');
            int remainder = 0;
            
            for (int j=n2-1; j>-1; j--){
                int t = (num2[j] - '0') * (num1[i] - '0') + remainder;

                if (j>0){
                    tem = to_string(t% 10) + tem;
                }else{
                    tem = to_string(t) + tem;
                }
                remainder = t/10;

            }
            result.push_back(tem);
            cout<<tem<<endl;
        }
        string r = sum_string(result);
        return simplified(r);
    }

    string multiply2(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');
    
    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
            cout << sum << "i " << i << "j " << j << endl;
        }
        sum[i] += carry;
    }
    
    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";

    }
};

int main() {
    Solution s;
    cout << s.multiply("1", "1") << endl;
    return 0;

}

