#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
	    int X,Y;
	    cin>>X;
	    cin>>Y;
	    if(X<=8&&X*Y<=500){
	        cout<<"yes\n";
	    }
	    else{
	        cout<<"no\n";
	    }
	}
	return 0;
}
