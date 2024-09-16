// 1. Find Peak Element( find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.)

#include<bits/stdc++.h>
using namespace std;

int Peak(int arr[], int n)
{
    if(n==1)
    {
        return 0;
    }
    if(arr[0]>=arr[1])
    {
        return 0;
    }
    if(arr[n-1]>=arr[n-2])
    {
        return n-1;
    }
    
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1])
        {
            return i;
        }
    }
}

int main()
{
    int arr[]={1, 2, 1, 3, 1, 4, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"index of peak "<<Peak(arr,n);
    return 0;
    
}