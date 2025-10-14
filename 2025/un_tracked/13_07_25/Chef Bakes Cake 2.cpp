#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin>>T;
    
    while(T--){
        int n;
        cin>>n;
        int ans=0;
        vector<int> A(n), B(n); 
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=0;i<n;i++){
            cin>>B[i];
            if(A[i]>B[i]){
                ans += A[i]-B[i];
            }
        }
        
        cout<<ans<<endl;
    }
}
