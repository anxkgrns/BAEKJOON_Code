#include<iostream>
#include <cstring>

using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    int save = 0;
    for(int i =0;i<N;i++){
        char sign[10];
        int num;
        scanf("%s %d",sign,&num);
        num = num-1;
        if(strcmp(sign,"add")==0){
            save = save | (1<<num);
        }if(strcmp(sign,"remove")==0){
            save = save & ~(1<<num);
        }if(strcmp(sign,"check")==0){
            //printf("check\n");
            int check = save & (1<<num);
            if(check) printf("1\n");
            else printf("0\n");
        }if(strcmp(sign,"toggle")==0){
            save = save ^ (1<<num);
        }if(strcmp(sign,"all")==0){
            save = (2<<21) - 1;
        }if(strcmp(sign,"empty")==0){
            save = 0;
        }
    }
    
}