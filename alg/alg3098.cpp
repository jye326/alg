#include<iostream>
#include<vector>
#include<set>   // 중복 조회

using namespace std;

int main(){
    // N명의 인간이 각각 친구리스트를 가짐.
    // 모든 인간의 친구목록이 N-1이 될때까지 각자 친구리스트의 친구들을 조회하며 없으면 추가함
    // 인간이 50명 밖에 안되니까 일일히 조회해도 될듯함
    int N, M;
    cin>>N>>M;
    vector<set<int>> list(N+1);  //N
    for(int i = 0;i<M;i++){ //친구관계 수 M번 반복
        int x,y;
        cin>>x>>y;
        list[x].insert(y);
        list[y].insert(x);
    }
    // 친구목록 출력
    for(int i=1;i<list.size();i++){
        cout<<i<<"의 친구목록 : ";
        for(set<int>::iterator iter = list[i].begin();iter!=list[i].end();iter++){
            cout<<*iter<<" ";
        }cout<<"\n";
    }
    bool flag = 1;
    int countDays = 0;
    int countFriends = 0;
    int days[50];

    while(flag==1){
        countFriends=0;
        countDays++;   //날짜
        //cout<<countDays<<"일차"<<endl;
        flag = 0;
        for(int i = 1;i<N+1;i++){   //
            vector<int> temp;
            for(set<int>::iterator iter = list[i].begin();iter!=list[i].end();iter++){  // 내 친구목록
                //cout<<*iter<<endl;
                for(set<int>::iterator it = list[*iter].begin();it!=list[*iter].end();it++){    // 내 친구의 친구목록
                    if(list[i].find(*it) != list[i].end()){  // 내 친구의 친구가 이미 내 친구
                        //cout<<*it<<" ";
                    }else{  // 첨보는 친구
                        if(*it!=i){
                            flag = 1;
                            //list[i].insert(*it);
                            temp.push_back(*it);
                            cout<<i<<"의 새친구"<<*it<<endl;
                        }
                    }
                }
            }
            for(int j=0;j<temp.size();j++){
                list[i].insert(temp[j]);
                list[temp[j]].insert(i);
                countFriends++;
            }
        }
        cout<<countDays<<"countDays"<<endl;
        days[countDays-1] = countFriends;
    }   

    // 친구목록 출력
    for(int i=1;i<list.size();i++){
        cout<<i<<"의 친구목록 : ";
        for(set<int>::iterator iter = list[i].begin();iter!=list[i].end();iter++){
            cout<<*iter<<" ";
        }cout<<"\n";
    }
    cout<<countDays-1<<endl;
    for(int i=0;i<countDays-1;i++){
        cout<<days[i]<<endl;
    }
  

    system("pause");
    return 0;
}