//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void fn(vector<int>arr,int sum,vector<int>&res,int i){
     int n=arr.size();
     if(i==n){
          res.push_back(sum);
         return;
     }
     fn(arr,sum+arr[i],res,i+1);
     
     fn(arr,sum,res,i+1);
     return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>res;
        if(N==1){
            res.push_back(0);
            res.push_back(arr[0]);
            return res;
        }
        
        int sum=0;
        int i=0;
        fn(arr,sum,res,i);
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends