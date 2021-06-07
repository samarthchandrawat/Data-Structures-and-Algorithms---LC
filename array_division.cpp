//https://codeforces.com/contest/808/problem/D
//two maps (parts of array) are used for comparing if one element can be taken from another to make them both have an equal sum.


#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iterator>   

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A(n+5,0);
	long long sum = 0;
	
	for (int i=0; i<n; i++){
	    cin>> A[i];
	    sum += A[i];
	}
	
	if(sum & 1){
	    cout << "NO";
	    return 0;
	}
	
	unordered_map<long long ,int> first, second;
	
	first[A[0]] = 1;
	
	for(int i=1; i<n; i++) 
	    second[A[i]]++;
	    
	long long sdash = 0;
	    
	 for(int i=0; i<n ; i++) {
	     sdash += A[i];
	     if(sdash == sum/2) {
	         cout << "YES";
	         return 0;
	     }
	     if(sdash < sum/2) {
	         long long x = sum/2 - sdash;
	         if(second[x] > 0) {
	             cout << "YES";
	             return 0;
	         }
	     }
	     else {
	         long long y = sdash - sum/2;
	         if(first[y] > 0) {
	             cout << "YES";
	             return 0;
	         }
	     }
	     first[A[i+1]]++;
	     second[A[i+1]]--;
	 }
	 
	cout<<"NO"
	return 0;
}
