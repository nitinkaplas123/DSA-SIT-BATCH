https://www.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1


Solution -:
Idea-:
1)Make all 0 to -1 in array 
2)Now make use of hashmap and using presum we can calculate the max length.

int maxLen(int arr[], int N)
{
        unordered_map<int,int>m;
        for(int i=0;i<N;i++)
        {
            if(arr[i]==0)
            arr[i]=-1;
        }
        
        int pre_sum=0;
        int ans=0;
        m.insert({0,-1});
        for(int i=0;i<N;i++)
        {
            pre_sum+=arr[i];
            if(m.find(pre_sum)!=m.end())
            ans=max(ans,i-m[pre_sum]);
            else
            m.insert({pre_sum,i});
        }
        return ans;
}


Java -:
 int maxLen(int[] arr, int N)
    {
       HashMap<Integer,Integer>m=new HashMap<>();
       int ans=0;
       for(int i=0;i<N;i++)
       {
           if(arr[i]==0)
           arr[i]=-1;
       }
       
       m.put(0,-1);
       int pre_sum=0;
       
       for(int i=0;i<N;i++)
       {
           pre_sum+=arr[i];
          
           if(m.containsKey(pre_sum))
           ans=Math.max(ans,i-m.get(pre_sum));
           else
           m.put(pre_sum,i);
       }
       return ans;
    }