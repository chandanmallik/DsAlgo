#include<iostream>
#include<algorithm>


using namespace std;

class Edge{


    public:
        int source ;
        int desti;
        int weight;

};


bool compareWeight(Edge e1 , Edge e2){

    return e1.weight < e2.weight;
        
}


// creating a function to find the parent


int parent(int e1, int *paraentArray){
    // here if the index of the the elemnt doest match with the index of the array then it have different parent so

    if  (paraentArray[e1] == e1){
    return e1;
    
    }
    
     return parent(paraentArray[e1],paraentArray);
    

    
}

void kruskal(Edge *input, int n,int m){



    // sorting the edges on basis of weight

    sort(input, n+input ,compareWeight);
    
    // we need to creat a parent array that will tell the the parent of the node
     int *parentArray = new int[m];

     for (int i  = 0; i < m; i++){
         parentArray[i] = i;
     }

    // we have go through the each  edge -1

    int count = 0;
    // for the outer array of class
    int i = 0;

    // creating a outer class with the n-1 value as we need n-1 node
    Edge *outer = new Edge[m-1];
    while( count!=m-1){
        cout<<"..working.."<<endl;
            Edge current = input[i];
            // sorce and destination finder and check if they form cycle

            int destination = parent(current.desti,parentArray);
            int source = parent(current.source, parentArray );

            // checking

            if( source != destination){
                parentArray[source] = destination; 
                // add it to the outer class;
                outer[count] = current;
                count++;   //we use this count as it is the number of vertex added to the answer so max n-1 vertix sp
            }
            i++;

            


    }
    for (int  i = 0; i < m-1; i++){
        if (outer[i].source < outer[i].desti){
            cout<<outer[i].source<<"\t"<<outer[i].desti<<"\t"<<outer[i].weight<<endl;
        }else{
             cout<<outer[i].desti<<"\t"<<outer[i].source<<"\t"<<outer[i].weight<<endl;
        }
    }
    

    

}




int main(){
    
    int n,m;
    cout<<"Enter the number of edges"<<endl;
    cin>>n;
    cout<<"Enter no of vertex";
    cin>>m;
    Edge *input = new Edge[n];
    int s,d,w;
    for(int i = 0 ; i< n;i++){
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].desti = d;
        input[i].weight = w;
        
    }

    kruskal(input, n,m);
    




    

    return 0;
}