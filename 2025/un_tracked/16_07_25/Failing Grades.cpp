#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    int ans = 0;
	    bool lost = false;
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    for(int i = 0;i<n;i++){
	        ans += arr[i];
	        if(ans/(i+1) < 40){
	            lost = true;
	        }
	    }
	    
	    if(lost){
	        cout<<"No"<<endl;
	    }
	    else{
	        cout<<"Yes"<<endl;
	    }
	}
	return 0;

}
