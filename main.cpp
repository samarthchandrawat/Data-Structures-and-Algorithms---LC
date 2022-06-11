/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

#include<bits/stdc++.h>
using namespace std;

bool rec(vector<string> &arr, int i, int j, int n, int m) {
    
    arr[i][j] = '1';
    
    if( i==n-1 && j==m-1 ) {
        return true;
    }
    
    // can move down
    
    if( i+1<n && arr[i+1][j] != 'X') {
        
        if(rec(arr, i+1, j, n, m)) {
            return true;
        }
    }
    
    // can move right
    
    if( j+1<m && arr[i][j+1] !='X' ) {
        
        if(rec(arr, i, j+1, n, m)) {
            return true;
        }
    }
    
    
    // can move up
    
    if( i-1>=0 && arr[i-1][j] !='X' ) {
        
        if(rec(arr, i-1, j, n, m)) {
            return true;
        }
    }
    
    
    // can move left
    
    if( j-1>=0 && arr[i][j-1] !='X' ) {
        
        if(rec(arr, i, j-1, n, m)) {
            return true;
        }
    }
    
    // cant move anywhere from here
    
    arr[i][j] = 'O';
    
    return false;
    
}


vector<vector<int>> ratAndMice(vector<string> arr) {
    
    int n = arr.size();
    int m = arr[0].length();
    
    rec(arr, 0, 0, n, m);
    
    vector<vector<int>> res(n, vector<int>(m, 0));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m;j ++) {
            if(arr[i][j] == '1') {
                res[i][j] = 1;
            }
        }
    }
    
    return res;
}

int main()
{
    vector<string> argm = {"OXOO", "OOOX", "XOXO", "XOOX", "XXOO"};

    vector<vector<int>> ans = ratAndMice(argm);
    
    for(int i=0; i<5; i++) {
        for(int j=0; j<4;j ++) {
            cout<< ans[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}
