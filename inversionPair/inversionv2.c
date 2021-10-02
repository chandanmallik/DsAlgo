#include<stdlib.h>
#include<stdio.h>
int ar[] = {7,9,1,2,4,8};
int inversionx = 0 ;
int size =  sizeof(ar)/sizeof(ar[0]);


void merge(int l,int r, int m){
    
    
    int n1 = m-l+1;
    int n2 = r-m;
    int left[n1];
    int right[n2];
    int newl[n1];
    int newr[n2];

    for ( int i = 0 ; i<n1;i++){

        left[i] = ar[i+l]; 
    }
    for( int j  = 0; j<n2;j++){
        right[j] = ar[m+j+1];

    }
   
  

    int i = 0;
    int j =0;
    
    int k  = l;
    int newindex=0;
    int newindex2=0;
    while(i < n1 && j < n2){
        if (left[i]<right[j]){
            ar[k] = left[i];
            newl[newindex] = left[i];
            newindex++;
            
            i++;
        }else{
            ar[k] = right[j];
            newr[newindex2] = right[j];
            newindex2++;
           
            j++;
        }
    k++;
    }
    while (i <n1)
    {
       
        newl[newindex] = left[i];
        ar[k] = left[i];
        newindex++;
        i++;
        k++;
    }
    while (j<n2)
    {
        ar[k] = right[j];
        newr[newindex2] = right[j];
        newindex2++;
        j++;
        k++;
        
        
    }
printf("\n...start....\n");
    for ( int i = 0 ; i<n1;i++){

       printf("%d",newl[i]);
    }
printf("....");
    for( int j  = 0; j<n2;j++){
       printf("%d",newr[j]);

    }
printf("\n...ends....\n");


    
    
    int newi = 0;
    int newj = 0;
    int n = 0;
     while( newi < n1 ){
        
        printf("running");
        if ( newl[newi] < newr[newj]){
            newi++;
            newj = 0;
            
            
        }else{
            printf("\n the inversion pair %d %d \n",newl[newi] , newr[newj]);
            newj++;
            
            inversionx ++;
            if (newj>= n2){
                newj = 0;
                newi++;
            }
            
        }
        

}


 
 
    


}

void mergeSort(int i, int j){
    int inversion = 0;

    if (i<j){
        int mid = i + (j - i) / 2;
        mergeSort(i,mid);
        mergeSort(mid+1,j);
        merge(i,j,mid) ;

    }
    
}

int main(){

   mergeSort(0,size-1);
    for(int i = 0; i < size;i++){
        printf("%d",ar[i]);
    }
   
    printf("\ninversionx %d",inversionx);
    return 0;
}