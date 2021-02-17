#include<iostream>
#include<vector>
#include <fstream>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int> arr, int x, float y) {
        int l = 0, r=arr.size()-1;
        while (l <= r) {
            int m = l + (r-l) / 2;
            if (l==r || l+1 == r) {
                if (y > x) {
                   if (arr[r]== x) {
                       return r;
                   }
                   if (arr[l] == x) {
                       return l;
                   } else if (arr[l-1]==x){
                       return l-1;
                   }
                } else {
                    if (arr[l] == x) {
                        return l;
                    } else if (arr[r]==x) {
                        return r;
                    } else {
                        return r+1;
                    }
                }
            } else if (y>arr[m]) {
                l = m + 1;
            } else if (y < arr[m]) {
                r = m - 1;
            } 
        }
        return -1;
    }
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int idx25 = n / 4;
        int idx50 = n / 2;
        int idx75 = idx25 * 3;
        float percent25 = float(n) / 4;
        cout << "25: " <<  idx25 << " " << arr[idx25] << endl;

        cout << "50: " <<  idx50 << " " << arr[idx50] << endl;

        cout << "75: " <<  idx75 << " " << arr[idx75] << endl;
        int start25 = binarySearch(arr, arr[idx25], float(arr[idx25])-0.5);
        int end25 = binarySearch(arr, arr[idx25], float(arr[idx25])+0.5);
        int d25 = end25-start25+1;
        if (d25>percent25) {
            return arr[start25];
        }
        int start50 = binarySearch(arr, arr[idx50], float(arr[idx50])-0.5);
        int end50 = binarySearch(arr, arr[idx50], float(arr[idx50])+0.5);
        int d50 = end50-start50+1;
        if (d50>percent25) {
            return arr[start50];
        }
        int start75 = binarySearch(arr, arr[idx75], float(arr[idx75])-0.5);
        int end75 = binarySearch(arr, arr[idx75], float(arr[idx75])+0.5);
        int d75 = end75-start75+1;
        if (d75>percent25) {
            return arr[start50];
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<int> v;
    for (int i=0;i<24;++i) {
        v.push_back(1);
    }
    for (int i=0;i<25;++i) {
        v.push_back(2);
    }
    for (int i=0;i<25;++i) {
        v.push_back(3);
    }
    for (int i=0;i<26;++i) {
        v.push_back(4);
    }
    // cout << s.findSpecialInteger(v);
    ifstream inFile;
    
    inFile.open("fuck_easy.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    int x;
    vector<int> v2;
    while (inFile >> x) {
        v2.push_back(x);
    }
    inFile.close();
    cout << s.findSpecialInteger(v2) << endl;
    return 0;
}
