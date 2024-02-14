#include <iostream>
#include <math.h>
using namespace std;

int main(void){
    int T;
    cin >> T;
    int map[2][100000];
    int answer[3][100000];
    for (int test = 0; test < T; test++) {
        int n;
        cin >> n;
        // 데이터 입력
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }
        // DP
        answer[0][0] = map[0][0];
        answer[1][0] = map[1][0];
        answer[2][0] = 0;   // 선택 X

       

        for (int i = 1; i < n; i++) {
            answer[0][i] = max(answer[1][i - 1] + map[0][i], answer[2][i - 1] + map[0][i]);
            answer[1][i] = max(answer[0][i - 1] + map[1][i], answer[2][i - 1] + map[1][i]);
            answer[2][i] = max(answer[0][i - 1] , answer[1][i - 1]);
        }
       
       int temp = max(answer[0][n-1], answer[1][n-1]);
       temp = max(answer[2][n-1], temp);
        cout<<temp<<"\n";
    }
    return 0;
}

