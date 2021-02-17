#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    int pos_b_in_cycle;
    if (k % n == 0) {
        pos_b_in_cycle = n;
    } else {
        pos_b_in_cycle = k%n;
    }
    if (n%2 == 0) {
        cout << pos_b_in_cycle << endl;
    } else {
        int cycle_number = k / n;
        if (k % n == 0) {
            cycle_number -= 1;
        }

        cycle_number = cycle_number % (n / 2);
        int mid_point = (n / 2) + 1;  
        int a_pos = n + 1 - pos_b_in_cycle;
        

        int shifted = cycle_number*2;  
        if (pos_b_in_cycle >= n - cycle_number) {
            shifted += 2;
        } else if (pos_b_in_cycle >= mid_point - cycle_number) {
            shifted += 1;
        }
        pos_b_in_cycle += shifted;
        if (pos_b_in_cycle > n) {
            pos_b_in_cycle -= n;
        }

        
        cout << pos_b_in_cycle << endl;
    
    }
}



int main() {
    int t;
    cin >> t;
    while(t-->0){
        solve();        
    }
}