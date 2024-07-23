#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    pair <int,int> n = make_pair(N,0);
    queue<pair<int,int>> q;
    int visit[100005] ={0,};
    visit[N] = 1;
    q.push(n);
    int ans = 0;
    while(true){
        ans = q.front().second;
        int temp = q.front().first;
        if(temp == K){
            break;
        }
        int num[3] = {-1,1,temp};
        q.pop();
        for(int i = 0;i<3;i++){
            int j = num[i];
            if(0 <= (temp+j) && (temp+j) <=100000 && visit[temp+j] != 1){
                q.push(make_pair(temp+j,ans+1));
                visit[temp+j] = 1;
            }
        }
        
    }
    cout << ans;
}