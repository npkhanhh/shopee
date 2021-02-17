#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        int numberOfDistintEle = 0;
        vector<int> eleToOccurence(100001, 0);
        vector<int> occurenceToNumberOfEle(100001, 0);
        int maxOccurence = 0;
        int res = 0;
        for(int i = 0;i<n;++i) { 

            if(eleToOccurence[nums[i]] == 0) {
                numberOfDistintEle += 1;
            }
            occurenceToNumberOfEle[eleToOccurence[nums[i]]] -= 1;
            eleToOccurence[nums[i]] += 1;
            occurenceToNumberOfEle[eleToOccurence[nums[i]]] += 1;
            if (eleToOccurence[nums[i]] > maxOccurence) {
                maxOccurence = eleToOccurence[nums[i]];
            }

            if (numberOfDistintEle == 1 || maxOccurence == 1) {
                res = i + 1;
                continue;
            }
            
            // Bỏ đi 1 distinct element
            if (i % (numberOfDistintEle - 1) == 0) { //số bị xoá xuất hiện 1 lần
                int shouldAppear = i / (numberOfDistintEle - 1);
                // x == shouldAppear là số lần nên xuất hiện của 1 element sau khi bỏ  
                if (occurenceToNumberOfEle[shouldAppear] == numberOfDistintEle - 1) {
                    res = i + 1;
                }
                
            }
            // Số distinct element giữ nguyên
            if (i % numberOfDistintEle == 0) {//số bị xoá xuất hiện nhiều hơn các số còn lại 1 lần
                int shouldAppear = i  / numberOfDistintEle;
                if (occurenceToNumberOfEle[shouldAppear+1] == 1 && occurenceToNumberOfEle[shouldAppear] == numberOfDistintEle - 1) {
                    res  = i + 1;
                }
            }



        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v{1, 1};
    cout << s.maxEqualFreq(v) << endl;
    
};































