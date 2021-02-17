// x: số trận có kết quả hoà
// y: số trận thắng thua

// x + y = n(n-1)/2 => (2x+2y)/n = n-1 => 2x+2y % n == 0
// (2x + 3y) % n == 0 
// y max 
//  y / n 
// khi các đội khác điểm => có ít nhất 1 trường hợp là số trận thắng thua ko chia hết cho n => example: toàn bộ hoà, và chỉ có trận tháng thua
// điểm các đội bằng nhau =>{ y % n == 0, số trận thắng == số trận thua của mỗi đội}
//                      
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void solve(vector<int> a) {
    int n;
    cin >> n;
    int point_per_team = a[n];
    vector<vector<int>> result(n, vector<int>(n, -2));
    for(int i = 0;i<n;++i) {
        int win = point_per_team / 3;
        int draw = point_per_team % 3;
        for (int j=0;j<n;++j) {
            if (i==j) {
                continue;
            }
            if (result[i][j] == -2) {
                if (win>0) {
                    result[i][j] = 1;
                    result[j][i] = -1;
                    win -= 1;
                } else if (draw> 0) {
                    result[i][j] = 0;
                    result[j][i] = 0;
                    draw -= 1;
                } else {
                    result[i][j] = -1;
                    result[j][i] = 1;
                }
            } else if (result[i][j] == 1) {
                win -= 1;
            } else if (result[i][j] == 0) {
                draw -= 1;
            }
        }
    }
    for (int i = 0;i<n-1;++i) {
        for(int j = i + 1;j<n;++j) {
            cout << result[i][j] << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> a(101, 0);
    for(int n = 100;n>=2;--n) {
        int matches = (n * (n-1)) / 2;
        for (int y= matches; y>= 0; --y ) {
            int x = matches - y;
            if ((2*x + 3*y)%n ==0) {
                a[n] = (2*x + 3*y) / n;
                break;
            }
        }
    }
    int t;
    cin >> t;
    while (t-->0) {
        solve(a);
    }
}