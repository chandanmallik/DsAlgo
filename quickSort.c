#include<stdlib.h>
#include<stdio.h>

int a[] = {3,6,4,2,0,5,75,23,90,55,21};
int size = sizeof(a)/sizeof(a[0]);
void printer();
int selectionSort(int l,int r){

    int pivort = a[r];
    int i = l;
    int j = r;
    while(i<j){
       if(a[i]<pivort){
           i++;
       }
       else{
           if (a[j]<pivort){
               int temp = a[i];
               a[i] = a[j];
               a[j] = temp;
               i++;
           }else{
               j--;
           }
       }

    }
     int tempx = a[j];
     printf("\n.. temp %d \n",a[j]);
     a[j] = pivort;
     a[r] = tempx;

    printf("\nthe pivort index is j %d\n",j);
    printer();
    printf("\n....end....\n");

    return j;

}
void printer(){
    printf("\n");
    for (int i  = 0 ;i<size; i++){
        printf("%d ",a[i]);
    }

}

void select(int i , int j){  
    int newIndex = selectionSort(i,j);
    if (i<j){
        
        select(i,newIndex-1);
        select(newIndex+1,j);
    }
}

int main(){
    
    select(0,size-1);
    printer();



    return 0;
}