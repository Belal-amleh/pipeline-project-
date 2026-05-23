#include<iostream> 

using namespace std;
int main(){
   

   int arr[5][5];
   int row = 0 ;
    int col = 0 ;
   for(int i = 0; i < 5 ;++i)
    {
        for(int j = 0 ; j < 5 ; ++j){
            cin >> arr[i][j];
            if(arr[i][j] == 1)
            {
                row = i ;
                col = j ;
            }
        }
    }       

    int ver = 2 - row ;
    int hor = 2- col ;

    if(ver < 0 )
        ver*=-1;
    if(hor < 0 )
        hor*= -1;

   cout << ver + hor << endl;

    return 0 ;
}