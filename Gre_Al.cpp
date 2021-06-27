#include<iostream>
#include<stdio.h>
#define size 1000

using namespace std;
 
typedef struct {
    int worker, work , time;
}Depart;

typedef struct {
    int time, nstatus;
}Data;

void openFile(Data gArray[][size], int *n);
void outputData(Data gArray[size][size] , int n);
void update_mark(Data gArray[][size], int n, int j);
int min_el(Data gArray[][size], int n, int i, int *j);
void Gre_Al(Data gArray[][size], int n, Depart De[]);
void outputRes(Depart De[], int n);




int main(){

    Data gArray[size][size];
    int n;
    openFile(gArray, &n);
    Depart De[n];
    outputData(gArray, n);
    Gre_Al(gArray, n, De);
    outputRes(De, n);

    return 0;

}

void openFile(Data gArray[][size], int *n){
    
    FILE *o;
    o  = fopen("data.txt","r");

    if (o==NULL){
        cout<<"Error when open data.txt";
        return;
    }
    fscanf(o, "%d", n);
  
    for (int i = 0; i < *n; i++ ){

        for (int j = 0; j < *n; j++){

            fscanf(o, "%d", &gArray[i][j].time);
            gArray[i][j].nstatus = 0;

        }
    }

    fclose(o);

}
void outputData(Data gArray[size][size] , int n){
    cout<<"Matrix of time : \n";

    for (int i =0; i <n;i++){
        for(int j = 0; j < n; j++){

            cout<<gArray[i][j].time<<"\t";
           
        }
         cout<<"\n";

    }
}
void update_mark(Data gArray[][size], int n, int j){
    for (int i = 0; i < n; i++){
        gArray[i][j].nstatus = 1;
    }
}

int min_el(Data gArray[][size], int n, int i, int *j){

    int time_min_el = 1000000000;
    for (int h = 0; h < n; h++){
        if (gArray[i][h].nstatus == 0 && gArray[i][h].time < time_min_el){
            time_min_el = gArray[i][h].time;
            *j = h;
        }

    }
    return time_min_el;
}
void Gre_Al(Data gArray[][size], int n, Depart De[]){
    int j;
    for (int i = 0; i < n; i++){

        De[i].worker= i+1;
        De[i].time = min_el(gArray, n, i, &j);
        De[i].work=j+1;
        update_mark(gArray, n, j);

    }
}
void outputRes(Depart De[], int n){
    int sot = 0; 
    cout<<"Greedy Algorithm : \n";
    cout<<"Worker \tWork \tTime \n";
    for (int i = 0; i < n; i++){
        cout<<De[i].worker<<"\t"<<De[i].work<<"\t"<<De[i].time<<"\n";
        sot += De[i].time;
    }
    cout<<"Sum of time : "<<sot;
}





