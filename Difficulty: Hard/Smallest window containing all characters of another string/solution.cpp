//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  //fundtion which checks if teh current substring we are processinng have all char in same ferquem=ncy as s2
    bool containS2(unordered_map<char,int> & mp){
        for(auto it:mp){
            if(it.second > 0){
                return false;
            }
        }
        
        return true;
    }
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s1, string &s2) {
        // Your code here
        int ansLen = INT_MAX;
        string ans = "";
        
        unordered_map<char,int> mp;
        
        for(char ch:s2){
            mp[ch]++;
        }
        
        int left = 0, right = 0;
        
        while(right < s1.size()){
            mp[s1[right]]--;
            
            while(containS2(mp)){
                if(right-left+1 < ansLen){
                    ansLen = right-left+1;
                    ans = s1.substr(left, ansLen);
                }
                
                mp[s1[left]]++;
                left++;
            }
            
            right++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        string str = obj.smallestWindow(s1, s2);
        if (str.size() == 0) {
            cout << "\"\"" << endl;
        } else {
            cout << str << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
