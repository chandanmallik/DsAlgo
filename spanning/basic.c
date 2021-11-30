#include<stdlib.h>
#include<stdio.h>

int main(){

    int flag = 1;
    int s[] = {0,5,-1,-1,-1,-1};
    int mx[] = {0,1,2,3,4,5};
    for(int m = 0; m <6;m++){
    for(int i = 0 ; i<3;i++){
        if (mx[m] == s[i]){
            flag = 1;
            break;
        }else{
            flag = 0;
        }
    }
    if (flag == 0){
        printf("%d",mx[m]);
    }
    flag = 0;
    
    }



    return 0;
}