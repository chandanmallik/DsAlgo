#include<stdio.h>
#include<stdlib.h>





void sjf(int t[], int b[], int s){
    int size = s;
   // sorting the time 

    for (int i = 0 ; i<s-1;i++){
        for(int j = i+1; j<s;j++){
            if (t[i]>t[j]){
                // changing the time
                int temp =  t[i];
                t[i] = t[j];
                t[j] = temp;
                // chaing the brust time also
                int temp2 = b[i];
                b[i] = b[j];
                b[j] = temp2;
              }
        }

    }

          for (int i = 1 ; i<s-1;i++){
                for(int j = i+1; j<s;j++){
                    if (b[i]>b[j]){
                        // changing the time
                        int temp =  b[i];
                        b[i] = b[j];
                        b[j] = temp;
                        // chaing the brust time also
                        int temp2 = t[i];
                        t[i] = t[j];
                        t[j] = temp2;
                    }
                }

            } 
            for (int i = 0 ; i<s;i++){
                 printf("%d",t[i]);

            }
            printf("\n");
            for (int i = 0 ; i<s;i++){
                 printf("%d",b[i]);

            }
    printf("\n.....\n");
   
    
int time = b[0];
int temp[] = {0};
int index = 1;
int totalBrust = b[0];
int avgbrust = 0;
int totalwaiting = 0;
int waiting = 0;
float sum = 0;
float sum2 = 0;

for ( int  j = 1; j<s ; j++){
   

    for(int i = 1; i<s;i++){

        if (time>= t[i]){


            totalBrust = totalBrust + b[i];
            avgbrust = totalBrust - t[i];
            totalwaiting = avgbrust - b[i];
            sum = sum+ avgbrust;
            sum2 = sum2 + totalwaiting;
            
            printf("\nbrust %d ",totalBrust);
             printf("\ntime %d ",totalwaiting);
            
            // remove 6 from b[i]
            int m;
            for(m = i; m<s-1;m++){
                b[m] = b[m+1];
                t[m] = t[m+1];
            }
            t[m] = -1;
            
            // for (int i = 0; i <s; i++)
            // {
            //    printf("\n the new t[%d]",t[i]);
            // }
            
            time = time+b[i];   
            break;
        }
        


    }
   



}

printf("\navg brust %.2f", (sum+b[0]-t[0])/size);
printf("\n2abg waiting %.2f", sum2/size);
       
}


   



    



int main(){

    int time[] = {1,3,0,4,4};
    int brust[] = {6,2,2,5,8};
    int size = sizeof(time)/sizeof(time[0]);
    sjf(time,brust,size);
    
    
    return 0;
}