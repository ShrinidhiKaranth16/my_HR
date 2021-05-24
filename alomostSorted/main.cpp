#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int n,i,j,a,b,c,d,count=0,x,original=0;
    bool changed = false,reverse1= false,numberCount = false,final = false;
    cin>>n;
    long int arr[n],temp[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        temp[i] = arr[i];
    }
    sort(arr,arr+n);
     for(i=0;i<n;i++)
     {
         if((arr[i]==temp[i]))
         {
           original++;
         }
     }
     if(original==n)
     {
         cout<<"yes"<<endl;
         exit(0);
     }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(temp[j]<temp[i])
            {
                if(!changed)
                {
                 a = i+1;
                }
                b= j+1;
                changed = true;
            }
        }
    }
    if(changed)
    {
                x= temp[a-1];
                temp[a-1] = temp[b-1];
                temp[b-1] = x;
    }
     for(i=0;i<n;i++)
     {
         if(!(arr[i]==temp[i]))
         {
             reverse1 = true;
              x = temp[a-1];
              temp[a-1] = temp[b-1];
              temp[b-1] = x;
             if(reverse1)
             break;
         }
         if(reverse1)
         break;
     }
     if(reverse1)
    {
     for(i=0;i<n-1;i++)
     {
         if(temp[i]>temp[i+1])
            {
                c=i+1;
                for(j=i+1;j<n;j++)
                {
                    if(temp[j]<temp[i])
                    count++;
                    else
                    numberCount = true;
                    if(numberCount)
                    break;
                }
                if(!numberCount)
                numberCount = true;
            }
            if(numberCount)
            break;
     }
     d = count+c;
     reverse(temp+c-1,temp+d);
      for(i=0;i<n;i++)
     {
         if(!(arr[i]==temp[i]))
         {
             cout<<"no"<<endl;
             final = true;
             break;
         }

     }
     if(!final)
     {
         cout<<"yes"<<endl;
         cout<<"reverse "<<c<< " "<<d<<endl;
     }
    }
     else
     {
        cout<<"yes"<<endl;
        cout<<"swap "<<a<<" "<<b;
     }
    return 0;
}