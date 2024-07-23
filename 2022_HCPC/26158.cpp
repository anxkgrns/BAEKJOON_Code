#include<stdio.h>
#include<iostream>
#include<list>
#include<vector>

using namespace std;


int p_solve(list<int> &p_list, int K){
    int searched_p = 0;
    int sloved_p = 0;
    int last_p = 0;
    for(auto p = p_list.begin(); p != p_list.end(); p++){
        if(*p > last_p){
            sloved_p ++;
            last_p = *p;
            // cout << *p << endl;
            p = p_list.erase(p);
            p--;
        }
        else{
            searched_p++;
            if(searched_p >= K){
                break;
            }
        }
        
    }
    return sloved_p;
}

int main()
{
    int N,K;
    cin >> N >> K;
    list<int> p_list;
    // vector <int> p_list; 
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        p_list.push_back(temp);
    }
    int day = 0, sloved_p = 0;
    while(sloved_p < N){
        // cout<< "!!!" << endl;
        day++;
        sloved_p = sloved_p + p_solve(p_list,K);
    }
    cout << day << endl;


}