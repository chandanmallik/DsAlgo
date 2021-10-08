#include<stdio.h>
#include<stdlib.h>


int a[] = {5,4,6,2,7}; 
char word[] = {'a','b','c','d'};
int pos[] = {};
int globPos = 0;


int matrixTable [5][5];

int matrixTableForbracket[5][5];

void change(int i , int j ,int v){

    matrixTable[i][j] = v;
    printf("\nmatrix : %d , i : %d, j : %d\n",matrixTable[i][j],i,j);
}
void changex(int i , int j ,int v){

    matrixTableForbracket[i][j] = v;
    printf("\nmatrix sec : %d , i : %d, j : %d\n",matrixTableForbracket[i][j],i,j);
}
void minVal(int i , int j){
    int min = matrixTable[i][i] + matrixTable[i+1][j] + a[i-1]*a[i]*a[j];
    int position = 1;
    for( int ix = i ; ix<j;ix++){
        printf("matrixTable[%d][%d] + matrixTable[%d][%d] + a[%d]*a[%d]*a[%d]\n",i,ix,ix+1,j,i-1,ix,j);
        int hereMin = matrixTable[i][ix] + matrixTable[ix+1][j] + a[i-1]*a[ix]*a[j];
        if (hereMin <= min){
            min = hereMin;
            position = ix;
        }
        
    }
    printf("\n the position %d \n", position);
    changex(i,j,position);
    change(i,j,min);


}

void fillTable(){
    
    
    int index = 2;
    int m = 3;
    int mx = 1;
    for(int i =1 ;i<4;i++){
        int mx  =  a[i-1]*a[i]*a[i+1]; 
        change(i,index,mx);
        changex(i,index,mx);
        mx++;
        
        index++;
        

    }
    
    for (int i  = 1 ; i<3; i++){
        minVal(i,m);
        m++;
    }
    minVal(1,4);



    
}
// void printer(int pos)
// {
    
//     for (int i  = sizeof(word)/sizeof(word[0])  ; i >=pos;i-- ){
//         word[i] = word[i-1];
//     }
//     word[pos] = ")(";
   

// }
void bracket(int i , int j){
    printf("\n i : %d , j : %d \n",i,j);
    if( i == j || i>j){
        return ; 
    }
    if(i<j){
    int thepostionOfBracket = matrixTableForbracket[i][j];
    // printer(thepostionOfBracket);
    printf("\nput the %c)(%c in position %d\n",word[thepostionOfBracket-1],word[thepostionOfBracket], thepostionOfBracket);
    bracket(i,thepostionOfBracket);
    
    
    if(thepostionOfBracket+1 > j ){
        bracket(thepostionOfBracket+1,j);
    }
    
    }

}


// void printerTheWord(){

//     printf("\n");
//     printf("(");
//     for ( int i  = 0 ;i < sizeof(word)/sizeof(word[0]); i++){
//         printf("%c",word[i]);
//     }
//      printf(")");
// }

int main(){
matrixTable[1][4] = 0;
matrixTable[2][3] = 0;
matrixTable[3][2] = 0;
matrixTable[4][1] = 0;
for ( int i = 1; i < 5;i++){
    matrixTableForbracket[i][i] = 0;
}

fillTable();
bracket(1,4);
// printerTheWord();
    return 0;
}