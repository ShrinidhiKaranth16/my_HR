#include<bits/stdc++.h>
using namespace std;

int lilysHomework(vector<int> arr) {
    vector<int> arr2 = arr;
    int i,j;
    int count = 0;
    for(i=0;i<arr.size();i++)
    {
        int min = arr[i];
         int r = 0, l;
        for(j=i+1;j<arr.size();j++)
        {
            if (arr[j]< min)
            {
                r++;
                l = j;
                min = arr[j];
            }
        }
        if(r>0)
            {
                count++;
                iter_swap(arr.begin()+i , arr.begin()+l);
            }
    }
    int count1 = 0;
     for(i=0;i<arr2.size();i++)
    {
        int max = arr2[i];
         int r = 0, l;
        for(j=i+1;j<arr2.size();j++)
        {
            if (arr2[j] > max)
            {
                r++;
                l = j;
                max = arr2[j];
            }
        }
        if(r>0)
            {
                 count1++;
                 iter_swap(arr2.begin()+i , arr2.begin()+l);
            }
    }
    if(count<count1)
    return count;
    else
    return count1;
}

 int main()
{
    int n;
    int i;
    cin>>n;
    vector<int> numbers;
    for(i=0;i<n;i++)
    {
        int num;
        cin>>num;
        numbers.push_back(num);
    }
      int result = lilysHomework(numbers);
      cout<<result<<endl;
}