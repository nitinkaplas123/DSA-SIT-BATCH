Solution 1-:
Steps-:
1)Make a temp array by making all value 1 bcz min there will be size 1 of increasing subsequence.
2)Now traverse from i=1  to n and at each point i we have to go to left side till reach 0.
3)If we find the min element to the left side from current element i then update the temp[i] to the possible
  max length.


Code-: Time->O(n2) Space->O(n)
int longestSubsequence(int n, int a[])
{
        int temp[n];
        for(int i=0;i<n;i++)
        {
            temp[i]=1;
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[j]>a[i])
                temp[j]=max(temp[j],1+temp[i]);
                ans=max(ans,temp[j]);
            }
        }
        return ans;
}

Solution 2-:
Steps-:
1)Here we make a vector v where we push all elements in it.
2) if v[i]>v[i-1]  then means current element is greater than the last element of vector so we push into vector.
3)else we add that value in vector just greater or equal than current element.


Code-: Time->O(nlog(n))  Space->O(n)
void helper(vector<int>&v,int val)
    {
        int n=v.size();
        int low=0;
        int high=n-1;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(v[mid]>=val)
            high=mid;
            else
            low=mid+1;
        }
        v[low]=val;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        v.push_back(nums[0]);

        for(int i=1;i<n;i++)
        {
            if(nums[i]>v.back())
            v.push_back(nums[i]);
            else
            helper(v,nums[i]);
        }
        return v.size();
}
