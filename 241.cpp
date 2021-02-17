#include<iostream>
#include<vector>
#include<string>
#include<experimental/iterator>
#include<map>
using namespace std;

void print(vector<int> const &input)
{
    cout << "[";
    copy(input.begin(),
            input.end(),
            experimental::make_ostream_joiner(cout, " "));
    cout << "]" << endl;
}

class Solution {
private:
    map<string, vector<int>> m;
public:
    
    vector<int> diffWaysToCompute(string input) {    
        vector<int> result;
        // if (input.find('+') == -1 && input.find('-') == -1 && input.find('*') == -1) {
        //     result.push_back(stoi(input));
        //     return result;
        // }
        if (m.count(input)==1) {
            return m[input];
        } 

        for (int i=1; i<input.length()-1;i++){
            if (input[i]=='+' || input[i]=='-' || input[i]=='*'){
                vector<int> left = diffWaysToCompute(input.substr(0 ,i));

                vector<int> right = diffWaysToCompute(input.substr(i+1, input.length()-i-1));
                for (int ll=0;ll<left.size();ll++){
                    for (int rr=0;rr<right.size();rr++){
                        
                        switch(input[i]){
                            case '+':
                                result.push_back(left[ll]+right[rr]);
                                break;
                            case '-':
                                result.push_back(left[ll]-right[rr]);
                                break;
                            case '*':
                                result.push_back(left[ll]*right[rr]);
                                break;
                        }
                    }
                }
            }
            
        }
        if (result.size()==0) {
            result.push_back(stoi(input));
        }
        m[input] = result;    
        return result;
    }
};


 
int main() {
    Solution s;
    print(s.diffWaysToCompute("2-1-1"));
    print(s.diffWaysToCompute("2*3-4*5"));
    return 0;
}