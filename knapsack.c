#include<stdio.h>
#include<stdlib.h>
int size1 =2;
int size2 = 7;
void knap(float pw[size1][size2],int size){

float totalWeight = 15;
float totalprofit = 0;
float temp[size1][size2];
    for (int i = 0 ; i <size ;i++){

        temp[0][i] = pw[0][i];
        temp[1][i] = pw[1][i];
    }
 for (int i = 0;i<size;i++){
        
        for(int j = 0 ; j<size;j++){
            if (temp[0][i] > temp[0][j]){
                float hereTemp = temp[0][i];
                float hereTemp2 = temp[1][i];
                temp[0][i] = temp[0][j];
                temp[1][i] = temp[1][j];
                temp[0][j] = hereTemp;
                temp[1][j] = hereTemp2;



            }
            }
        }
    for (int i = 0 ; i <size ;i++){
        
        printf(" pw : %f => weight %f\n",temp[0][i],temp[1][i]);
    }
    int n = 0;
    int i = 0;
    while (n !=1 ) {
        
        if (totalWeight <=0){
            n = 1;
            break;
        }else{
            if (totalWeight - temp[1][i] < 0){
                printf("items or weight to add %f of item %f with profit rate %f\n",(totalWeight / temp[1][i]),temp[1][i], ( totalWeight  /  temp[1][i]) * (temp[0][i]*temp[1][i]));
                totalprofit = totalprofit +  ( totalWeight  /  temp[1][i]) * (temp[0][i]*temp[1][i]);
                totalWeight = totalWeight - temp[1][i] *(totalWeight / temp[1][i]);
                
                break;
            }ß
            else{
            totalWeight = totalWeight - temp[1][i];
            totalprofit = totalprofit + temp[0][i] * temp[1][i];
            printf("items or weight to add %f with profit rate %f\n",temp[1][i], temp[0][i] * temp[1][i]);
            i++;
            }

        }

    }
    printf("\ntotal weigh %f and totalProfit %f",totalWeight,totalprofit);



}




    


int main(){
    

    int profit[] = {10,5,15,7,6,18,3};
    int weight[] = {2,3,5,7,1,4,1};
    int size = sizeof(profit)/sizeof(profit[0]);
    float pw[size][size];
    for (int i = 0 ; i <size ;i++){
        
        pw[0][i] = (float)profit[i] / (float) weight[i];
        pw[1][i] = weight[i];

    }
   
    knap(pw,size);

    // for (int i = 0 ; i <size ;i++){

    //     printf("%f\n",pw[i]);
    // }
    // knapScak(weight,pw,size);

    
    return 0;
}