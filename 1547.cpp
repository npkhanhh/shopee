#include <iostream>
#include <vector>
#include <experimental/iterator>
#include <map>
using namespace std;

void print(std::vector<int> const &input)
{
    copy(input.begin(),
            input.end(),
            experimental::make_ostream_joiner(cout, " "));
    cout<< endl;
}

class Solution
{
private:
    map<vector<int>, int> m;
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

    int rMinCost(vector<int> &c)
    {
        if (m.count(c) == 1) {
            return m[c];
        }
        if (c.size() == 2)
        {
            return 0;
        }
        int result = 9999999;
        for (int i = 1; i < c.size() - 1; ++i)
        {
            vector<int> left = slice(c, 0, i + 1);
            vector<int> right = slice(c, i, c.size());

            int min_left = rMinCost(left);
            int min_right = rMinCost(right);
            result = min(result,min_left + min_right + (c[c.size() - 1] - c[0]));
        }
        m[c] = result;
        return result;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return rMinCost(cuts);
    }
};

int main()
{
    Solution s;
    vector<int> test1 = {134,133,38,20,49,111,375,223,258,310,281,332,88,5,188,295,106,363,156,229,345,34,331,249,374,233,35,387,236,162,302,73,87,377,265,360,53,214,318,152,147,113,290,193,136,333,308,306,55,224,322,381,139,135,84,207,167,217,230,312,50,176,268,325,128,288,367,282,289,82,246,72,253,98,218,6,54,266,148,228,320,291,79,355,314,36,130,60,28,205,114,4};
    cout << s.minCost(30, test1) << endl;
    // vector<int> test2 = {3, 5, 1, 4};
    // cout << s.minCost(7, test2) << endl;
    return 0;
}