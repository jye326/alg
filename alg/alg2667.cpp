#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
/*
1. 아이디어 : 맵을 순회하다가 미방문 1을 발견시 BFS를 사용하며
BFS를 돌린 횟수로 단지수를 찾고, vector에 단지에 연결된 집 수를 저장
2. 자료구조 : 2차원 동적배열 -> map이랑 check용, vector(집수체크), queue(BFS), 좌표는 pair<int, int>
3. 시간복잡도 : 방문한 곳을 다시 방문할 일은 없으니까, O(N^2) -> (지도크기) 일듯
4. 공간복잡도 : 625 * 4(int)
*/
int N;
int **map;
bool **check;
int countVillage;
int countHouse;
vector<int> list;

void bfs(int x, int y){
    countHouse = 0; // 이 단지의 집 수
    queue<pair<int, int>> q;    //좌표담을 큐
    int X[4] = {1, 0, -1, 0};
    int Y[4] = {0, 1, 0, -1};
    // 우, 하, 좌, 상
    pair<int,int> now = make_pair(x, y);   
    q.push(now);    // 현재좌표 queue에 담기
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        countHouse++;
        for(int i=0;i<4;i++){
            int nx = xx+X[i];
            int ny = yy+Y[i];
            //다음 좌표 범위 체크
            if(nx>=0 && nx<N && ny >= 0 && ny <N){  //유효범위
                if(check[nx][ny] == false){ // 미방문일 경우
                    check[nx][ny] = true;   // 방문표시
                    if(map[nx][ny] == 1){ // 집일 경우
                        q.push(make_pair(nx, ny));  // queue에 담기
                    }
                }
            }
        }
    }//연결된 모든 집 탐색 종료
    list.push_back(countHouse);
}

int main (){
    cin>>N;
    map = new int*[N];
    check = new bool*[N];
    for(int i=0;i<N;i++){
        map[i] = new int[N];
        check[i] = new bool[N];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            check[i][j] = false;
        }
    }
    //입력
    //string으로 주어지니 받아서 파싱해서 int로 바꿔서 넣자.
    for(int i=0;i<N;i++){
        string line;
        cin>>line;
        for(int j=0;j<N;j++){
            map[i][j] = (line[j]-'0');
        }
    }
    // //출력
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<map[i][j]<<" ";
    //     }cout<<"\n";
    // }
    countVillage = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(check[i][j] == false){   //미방문 구역
                check[i][j] = true;    // 방문표시
                if(map[i][j] == 1){ //집이다.
                    countVillage++;
                    bfs(i, j);  //집 좌표 넘기기 BFS
                }
            }
        }
    }
    cout<<countVillage<<'\n';
    sort(list.begin(), list.end());
    for(int i=0;i<list.size();i++){
        cout<<list[i]<<"\n";
    }


    for(int i=0;i<N;i++){
        delete[] map[i];
    }
    delete[] map;

    //system("pause");
    return 0;
}


