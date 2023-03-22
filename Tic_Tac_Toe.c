
#include <stdio.h>
#include <stdbool.h>
int moves=0,player=1;
char arr[9];
void Clean(){
    arr[0] = '1';
    arr[1] = '2';
    arr[2] = '3';
    arr[3] = '4';
    arr[4] = '5';
    arr[5] = '6';
    arr[6] = '7';
    arr[7] = '8';
    arr[8] = '9';
}
int main() {
    
    Clean();
    while(Check() && CheckWin() == 0){
        gameMechanic();
    }
    DisplayTable();
    printf("Game Over");

    return 0;
}
void DisplayTable(){
    printf("_%c_|",(arr[0]));
    printf("_%c_|",(arr[1]));
    printf("_%c_\n",(arr[2]));
    printf("_%c_|",(arr[3]));
    printf("_%c_|",(arr[4]));
    printf("_%c_\n",(arr[5]));
    printf("_%c_|",(arr[6]));
    printf("_%c_|",(arr[7]));
    printf("_%c_\n",(arr[8]));
}
int Check(){
    if(moves>=9){
        return 0;
    }
    else{
        return 1;
    }
}
void gameMechanic(){
    int move,pos;
    if(Check()){
        DisplayTable();
        printf("Enter your move Player %d : ",player);
        scanf("%d",&move);
        if(player == 1){
            arr[move-1] = 'X';
            player = 2;
        }
        else{
            arr[move-1] = 'O';
            player = 1;
        }
        moves++;
    }
    else{
        printf("Game Over");
    }
}

int CheckWin(){
    if(arr[0]==arr[2] && arr[0]==arr[1]){
        return 1;
    }
    else if(arr[3]==arr[5] && arr[3]==arr[4]){
        return 1;
    }
    else if(arr[6]==arr[8] && arr[6]==arr[7]){
        return 1;
    }
    else if(arr[0]==arr[3] && arr[0]==arr[6]){
        return 1;
    }
    else if(arr[1]==arr[4] && arr[1]==arr[7]){
        return 1;
    }
    else if(arr[2]==arr[5] && arr[2]==arr[8]){
        return 1;
    }
    else if(arr[0]==arr[4] && arr[0]==arr[8]){
        return 1;
    }
    else if(arr[2]==arr[4] && arr[2]==arr[6]){
        return 1;
    }
    else {
        return 0;
    }
}
