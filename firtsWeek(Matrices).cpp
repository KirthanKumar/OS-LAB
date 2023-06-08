#include <iostream>
using namespace std;

int * addition( int arr1[][], int arr2[][]){
    int res[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            res[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    
    return res;
}

int * multiplication(int arr1[][], int arr2[][]){
    int res[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            res[i][j] = 0;
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                res[i][j] += arr1[i][k] * arr2[k][j]
            }
        }
    }
    return res;
        
}

bool isSymmetricMatrix(int arr1[][]){
    int res[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            res[i][j] = arr1[j][i];
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(res[i][j] == arr1[i][j]){
                return true;
            }
            else{
                return false;
            }
        }
    }
}

int * transpose( int arr1[][]){
    int res[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            res[i][j] = arr1[j][i];
        }
    }
    return res;
}

void sumofRC(int arr1[][]){
    for(int i=0; i<3; i++){
        int sumOfRow = 0;
        for(int j=0; j<3; j++){
            sumOfRow += arr1[i][j];
            cout<<"The "<<i<<"row sum is: "<<sumOfRow;
        }
    }
    for(int i=0; i<3; i++){
        int sumOfCol = 0;
        for(int j=0; j<3; j++){
            sumOfRow += arr1[j][i];
            cout<<"The "<<i<<"column sum is: "<<sumOfCol;
        }
    }
}

void sumOfDiagonal(int arr1[][]){
    int prinSum = 0;
    for(int i=0; i<3; i++){
        int nonPrinSum = 0;
        for(int j=0; j<3; j++){
            if(i == j){
                prinSum += arr1[i][j
                cout<<"Principle Diagonal Sum is: "<<prinSum;
            }
            else if(j == i+1){
                nonPrinSum += arr1[i][j];
                cout<<"Non Principle Diagonal Sum is: "<<nonPrinSum;
            }
            else if(j == i+2){
                nonPrinSum += arr1[i][j];
                cout<<"Non Principle Diagonal Sum is: "<<nonPrinSum;
            }
            else if(i == j+1){
                nonPrinSum += arr1[i][j];
                cout<<"Non Principle Diagonal Sum is: "<<nonPrinSum;
            }
            else if(i == j+2){
                nonPrinSum += arr1[i][j];
                cout<<"Non Principle Diagonal Sum is: "<<nonPrinSum;
            }
        }
    }
}

int main()
{
   
    return 0;
}
