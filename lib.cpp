#include <iostream>
#include <experimental/iterator>
#include <vector>
using namespace std;

void print(std::vector<int> const &input)
{
    copy(input.begin(),
         input.end(),
         experimental::make_ostream_joiner(cout, " "));
    cout << endl;
}

vector<int> slice(vector<int> v, int start, int end)
{
    if (end > v.size())
    {
        end = v.size();
    }
    vector<int>::const_iterator first = v.begin() + start;
    vector<int>::const_iterator last = v.begin() + end;
    vector<int> result(first, last);
    return result;
}

int max(vector<int> v){
    int res = v[0];
    for (int i = 1;i<v.size();++i) {
        if (v[i] > res) {
            res = v[i];
        }
    }  
    return res;
}

int min(vector<int> v){
    int res = v[0];
    for (int i = 1;i<v.size();++i) {
        if (v[i] < res) {
            res = v[i];
        }
    }  
    return res;
}


vector<string> split(const std::string& s, const char delim)
{
    vector<string> res;
    std::string::size_type beg = 0;
    for (auto end = 0; (end = s.find(delim, end)) != std::string::npos; ++end)
    {
        res.push_back(s.substr(beg, end - beg));
        beg = end + 1;
    }
 
    res.push_back(s.substr(beg));
    return res;
}

int binarySearch(vector<int> arr, int x) {
        int l = 0, r=arr.size()-1;
        while (l <= r) {
            int m = (l+r) / 2;
            if (x>arr[m]) {
                l = m + 1;
            } else if (x < arr[m]) {
                r = m - 1;
            } else {
                return m;
            }
        }
        return -1;
    }