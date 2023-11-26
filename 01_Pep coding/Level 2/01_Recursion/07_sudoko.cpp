#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<int>> sudoko, int r, int c, int data){
    //Row check
    for(int i = 0; i < 9; i++){
        if(sudoko[i][c] == data)
            return false;
    }
    //Col check
    for(int i = 0; i < 9; i++){
        if(sudoko[r][i] == data)
            return false;
    }
    //Box check
    int sr = r - r%3;
    int sc = c - c%3;
    for(int i = sr; i < sr+3; i++){
        for(int j = sc; j < sc+3; j++){
            if(sudoko[i][j] == data)
                return false;
        }
    }
    return true;
}

void display(vector<vector<int>> sudoko){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << sudoko[i][j] <<" ";
        }
        cout << endl;
    }
}
void sudokoSolver(vector<vector<int>> sudoko, int i, int j){
    if(i == 9){
        display(sudoko);
        return;
    }
    int ni{}, nj{};
    if(j == 8){
        ni = i+1;
        nj = 0;
    }
    else{
        ni = i;
        nj = j+1;
    }
    if(sudoko[i][j] != 0)
            sudokoSolver(sudoko, ni, nj);
    else{
        for(int po = 1; po <= 9; po++){ //Possible options
            if(isValid(sudoko, i, j, po)){
                sudoko[i][j] = po;
                sudokoSolver(sudoko, ni, nj);
                sudoko[i][j] = 0;
            }
        }
    }
}

int main(){
    vector<vector<int>> sudoko(9, vector<int>(9));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            cin >> sudoko[i][j];
    }
    sudokoSolver(sudoko, 0, 0);
}