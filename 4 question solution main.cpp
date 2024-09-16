// 4. Sort Colors 

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    
    void sortCol(vector<int>&nums)
    {
        vector<int>fre(3,0);
        for(auto i:nums)
        {
            fre[i]++;
        }
        
        int j=0;
        for(int k=0;k<3;k++)
        {
            while(fre[k]>0)
            {
                nums[j]=k;
                j++;
                fre[k]--;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortCol(nums);
    
    for(int num:nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}