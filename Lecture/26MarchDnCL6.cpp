#include<bits/stdc++.h>
#include<limits.h>

using namespace std;


   bool isSafe(int value,int board[][9],int curr_row,int curr_col){

      for(int i=0;i<9;i++){
 //row check
           if(board[curr_row][i]==value){
               return false;
           } 
//col check
           if(board[i][curr_col]==value){
               return false;
           }
        
//3*3 box check
        if(board[3*(curr_row/3)+(i/3)][3*(curr_col/3)+(i%3)]==value){
            return false;
        }
        }
        
         return true;


   }


   bool solve(int board[9][9],int n){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0){
                for(int value=1;value<=9;value++){
                    if(isSafe(value,board,i,j)){
                        //insert
                        board[i][j]=value;

                        bool aageKaSolution=solve(board,n);

                        if(aageKaSolution==true){
                            return true;
                            //backtracking
                            board[i][j]=0;
                        }
                    }
                     return false;
                }
            }
        }
    }
    return true; 
   
   }



int main(){

    int arr[9][9]={
        {4,5,0,0,0,0,0,0,0},
        {0,0,2,0,7,0,6,3,0},
        {0,0,0,0,0,0,0,2,8},
        {0,0,0,9,5,0,0,0,0},
        {0,8,6,0,0,0,2,0,0},
        {0,2,0,6,0,0,7,5,0},
        {0,0,0,0,0,0,4,7,6},
        {0,7,0,0,4,5,0,0,0},
        {0,0,8,0,0,9,0,0,0}
};

     int n=9;
     bool ans=solve(arr,n);

     for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
     }
     return 0;
}