#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0;i<n;++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 1;i<n;++i) {
        if (a[i] > a[i-1]) {
            cout << n - i << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
    int t;
    cin >> t;
    while(t-->0){
        solve();        
    }
}