#include<iostream>
#include<vector>

#define INF 987654321

using namespace std;

bool bellman_ford(vector< pair<int, int> > dist[], int N, int start)
{
    vector<int> d(N+1,INF);
    d[start] = 0;
    for(int i = 1; i <= N; i++) // N개의 노드 수만큼 반복했을때 마지막 iteration 실행했을 때 값이 줄어든다면, 음의 사이클이 있는 것이라고 판별할 수 있다.
    {
        for(int j = 1; j <= N; j++)
        {
            for(int k = 0; k < dist[j].size(); k++)
            {
                int next = dist[j][k].first;
                int nextDist = dist[j][k].second;
                if(d[next] > d[j] + nextDist)
                {
                    d[next] = d[j] + nextDist;
                    if(i == N) //값이 달라졌는데 N번째 iteration이라면 음의 사이클이 있는 것이다.
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        //cout << "Case #" << i+1 << endl;
        int N,M,W; // N: 지점(node) 수, M: 도로(edge) 수, W: 웜홀 수
        cin >> N >> M >> W;
        vector< pair<int, int> > dist[N+1];
        for(int j = 0; j < M; j++)
        {
            int S,E,T; // S: 시작점, E: 도착점, T: 소요시간
            cin >> S >> E >> T;
            dist[S].push_back(make_pair(E,T));
            dist[E].push_back(make_pair(S,T));
        }
        for(int j = 0; j < W; j++)
        {
            int S,E,T; // S: 시작점, E: 도착점, T: 줄어드는 시간
            cin >> S >> E >> T;
            dist[S].push_back(make_pair(E,-T));
        }
        bool yesNo = bellman_ford(dist,N,1);
        if(yesNo)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        


    }
}
/*
2
3 3 1
1 2 2
1 3 4
2 3 1
3 1 3
3 2 1
1 2 3
2 3 4
3 1 8
*/