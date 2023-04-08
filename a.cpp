//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
#include<iostream>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string text1, string text2, int m, int n)
    {
        //code here
      vector<int>prev(text2.length()+1 , 0) , curr(text2.length()+1 , 0);
        // return helper(text1 , text2 , dp , 0 , 0);
        for(int i = 0 ; i < text2.length() ; i++){
            prev[i] = 0;
        }
        for(int i =text1.length()-1 ; i >= 0 ; i--){
            for(int j = text2.length()-1 ; j >= 0 ; j--){
                    int notpick = 0 , pick = 0;
        if(text1[i] != text2[j]){
            int ans1 = prev[j]; 
            int ans2 = curr[j+1];
            notpick = max(ans1 , ans2);
        }
        else
        pick = 1 + prev[j+1];
         curr[j] = max(pick , notpick);
            }
            prev = curr;
        }
        int lcs = prev[0];
        return text1.length() + text2.length() - lcs;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    cin>>t;
    //taking total testcases
    while(t--){
    string X, Y;
    //taking String X and Y
	cin>>X>>Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}
// } Driver Code Ends