#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    int n,x,y;
	    cin>>n>>x>>y;
	    
	    int arr[n];
	    int even=0;
	    int odd=0;
	    for(int i = 0;i<n;i++){
            int val;
            cin >> val;
            if (val % 2 == 0)
                even++;
            else
                odd++;
	    }
	    if(odd == 0){
	        cout<<"No"<<endl;
	    }
	    else if( n % 2 == 0 && odd == n){
	        cout<<"No"<<endl;
	    }
	    else{
	        cout<<"Yes"<<endl;
	    }
	}
return 0;
}
