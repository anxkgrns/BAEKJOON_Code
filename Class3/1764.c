#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    vector<string> v1,v2;
    for(int i = 0;i<N;i++){
        string temp;
        cin >> temp;
        v1.push_back(temp);
    }
    
    for(int i = 0;i<M;i++){
        string temp;
        cin >> temp;
        v2.push_back(temp);
    }


    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    vector<string> buff(v1.size() + v2.size());
    auto iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), buff.begin());
    buff.erase(iter, buff.end());
    sort(buff.begin(),buff.end());
    printf("%ld\n",buff.size());
    for(string &it : buff){
        printf("%s\n",it.c_str() );
    }
}

