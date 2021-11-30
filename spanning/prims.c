#include<stdlib.h>
#include<stdio.h>
#define v 7
int cost = 0;
int graph[v][v] = {     {0,28,0,0,0,10,0},
                        {28,0,16,0,0,0,14},
                        {0,16,0,12,0,0,0},
                        {0,0,12,0,22,0,18},
                        {0,0,0,22,0,25,27},
                        {10,0,0,0,25,0,0},
                        {0,14,0,18,27,0,0},
                    } ;

int prims(int g[v][v],int array[v],int index, int select){
    int next;
    int m = 0;
    int flag = 0;
    int min  = 100;
    for(m = 0 ; m<7;m++){
        for(int i = 0 ; i<index;i++){
        if ( m == array[i]){
            flag = 1;
            break;
        }else{
            flag = 0;
        }
    }
    if (flag == 0){
        printf("here %d",m);
        if (g[select][m] < min && g[select][m] !=0 ){
            min = g[select][m];
            next = m;
            

        }
    }
    flag = 0;
        
    }
    cost = min + cost;
    printf("\nmin : %d",min);
    printf("\nNext cell id : %d",next);
    // adding to array
    array[index] = next;
    

    for (int i = 0; i< 7;i++){
    printf("\n..%d..\n",array[i]);
}

    
    return next;

}




int main(){
int array[7] = {0,-1,-1,-1,-1,-1,-1};



// selection 
int selection = 0;

for(int i = 0; i<6;i++){
selection = prims(graph,array,i+1,selection);



}
printf("The cost is %d ", cost);
// for (int i = 0; i< 7;i++){
//     printf("\n..%d..",array[i]);
// }


 return 0;   
}