#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool checkPallindrome(string s)
{
    string s1;
    s1 = s;
    reverse(s1.begin(),s1.end());
    if(s==s1)
    return true;
    else
    return false;
}
string highestValuePalindrome(string &s, long int n, long int k) {
    if(s.size()==1) return "9";
    if(k==n){
       string s1(k,'9');
       return s1;
    }
    long int mid = n/2;
    bool isPallindrome = checkPallindrome(s);
    if(isPallindrome){
        if(k%2==1){
        if(s[mid]!='9')
        s[mid] = '9';
        k--;
        }
        if(k==0){
            if(checkPallindrome(s))
            return s;
            else
            return "-1";
        } 
        long int l = 0,r = n-1;
        while(k>0){
            if((s[l]==s[r])&&(s[l]!='9'&&s[r]!='9')){
                s[l] = '9';
                s[r] = '9';
                k = k -2;
            }
            l++;
            r--;
        }
        if(k==0){
            if(checkPallindrome(s))
            return s;
            else
            return "-1";
        }
    }

    long int left = 0, right = n-1;
    while(k>1 && (left<right)){
         if(s[left]==s[right]){
             if(s[left]!='9' && s[right]!='9' && k!=1){
                 s[left] ='9';
                 s[right] = '9';
                 k = k-2;
             }
            left++;
            right--;
        }else{
                if(s[left]!='9'){
                s[left]='9';
                k--;
            }
            if(s[right!='9']){
                s[right]='9';
                 k--;
            }
            left++;
            right--;
        }
    }

    if(k==0 && checkPallindrome(s))
    return s;

    if(k==1){
        
        if(n%2==1)
        {
            s[mid] ='9';
            if(checkPallindrome(s))
            return s;
            else
            return "-1";
        }
        if(n%2==0 && left==right){
            if(s[mid-1]>s[mid])
            {
                s[mid] = s[mid-1];
            }else{
                s[mid-1] = s[mid];
            }
            if(checkPallindrome(s))
            return s;
            else
            return "-1";
        }
        if(n%2==0 && left!=right){
            while(left<right && k>0){
                if(s[left]!=s[right]){
                    if(s[left]>s[right]){
                        s[right] = s[left];
                    }else if(s[right]>s[left])
                    s[left] = s[right];
                    k--;
                }
                    left++;
                    right--;
            }
            if(checkPallindrome(s))
            return s;
            else return "-1";
        }
    }

}


 int main(){
    long int n,k;
    cin>>n;
    cin>>k;
    string s;
    s = (char *)malloc(10000000 * sizeof(char));
    cin>>s;
    string result = highestValuePalindrome(s,n,k);
    cout<<result<<endl;
}
