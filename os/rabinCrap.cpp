#include<iostream>
#include<string>
#include<math.h>
using namespace std;


// creating a hash function
int hasing(char a , char b){

    int var1 =  int(a);
    int var2 = int(b);
   

    return int(pow(var1,2)+pow(var2,2));
}


int main(){


    string str1 = "abdcancaacccacanjj";
    string str2 = "ca";
    cout<<"String : "<<str1<<endl;
    cout<<"To find a match "<<str2<<endl;
    
//    find the hash value of matching string i.e str2
    const int baseValue =  hasing(str2[0], str2[1]);

    cout<<"The base hasing value : "<<baseValue<<endl;

// window size is the size of str2;

    const int winSize = str2.size();
// we have to pass the each 2 charset upto in for loop (size.str1 - size.str2 + 1) 

    for (int i = 0; i< ( str1.size() - str2.size() + 1) ; i++){
        // printing the send string value
        cout<<"Sending These char : "<<str1[i]<<","<<str1[i+1]<<endl;

        if (hasing(str1[i],str1[i+1]) == baseValue){
            cout<<"hasing matchs"<<endl;
            // m for the index value of str2 dont forget to make it zero again
            int m = 0;
           
            // checking the each value of str1 with the str2 as a hasing value found
            
            for(int j = i ; j<winSize+i; j++){
                if (str1[j] != str2[m]){
                    break;
                }else{
                    // if match increment the m ++ as comp str 2 value
                    m++;
                }
                
            }
            // if the compare take place till end of the str2 with out break , the m should be size of str2
            if (m == (str2.size())){
                cout<<"we found a match on index : "<<i<<","<<i+1<<endl;
            }
            

        }


    }
    

   



    return 0 ;
}