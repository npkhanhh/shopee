#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
 
class Solution {
public:

    void backtrack(vector< vector<int> > &final_result, vector<int> current_result, vector<int> nums, bool* added) {
        if (current_result.size() == nums.size()) {
            final_result.push_back(current_result);
            return;
        }
        for (int i = 0; i<nums.size(); ++i) {
            if (!added[i]) {
                added[i] = true;
                current_result.push_back(nums[i]);
                backtrack(final_result, current_result, nums, added);
                current_result.pop_back();
                added[i] = false;
            }
        }
    }

    vector< vector<int> > permute(vector<int> nums) {
        vector< vector<int> > result;
        vector<int> current;
        bool *a = new bool[nums.size()];
        for (int i = 0;i<nums.size();++i) {
            a[i] = false;
        }
        backtrack(result, current, nums, a);
        return result;
    }
    

};

int main()
{
    Solution s;
    vector<int> v; 
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    vector< vector<int> > result = s.permute(v);

    for (int i=0; i< result.size(); i++){
        for (int j=0; j<result[i].size(); j++){
            cout << result[i][j] <<  " ";
        }
        cout<< endl;
    }
    return 0;

}