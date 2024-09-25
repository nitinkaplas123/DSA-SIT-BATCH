https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-149/problems


Solution 1-:
Code-:

vector<int> canTrade(int n, vector<int>& beautifulness, int q,
                         vector<vector<int>>& queries) {
        vector<int>v;
        
        for(int i=0;i<q;i++)
        {
            int start=queries[i][0]-1;
            int end=queries[i][1]-1;
            unordered_set<int>s;
            for(int j=start;j<=end;j++)
            {
                s.insert(beautifulness[j]);
            }
            if(s.size()==1)
            v.push_back(1);
            else
            v.push_back(0);
        }
        return v;
}


Java -:
public static int[] canTrade(int n, int[] beautifulness, int q, int[][] queries) 
{
        int []ans=new int[q];
        
        for(int i=0;i<q;i++)
        {
            HashSet<Integer>s=new HashSet<>();
            int low=queries[i][0]-1;
            int high=queries[i][1]-1;
            
            for(int j=low;j<=high;j++)
            {
                s.add(beautifulness[j]);
            }
            if(s.size()==1)
            ans[i]=1;
            else
            ans[i]=0;
        }
        return ans;
}

Solution 2-:
Steps-:

Code-:
vector<int> canTrade(int n, vector<int>& beautifulness, int q,
                         vector<vector<int>>& queries) {
        vector<int>v;
        
        int prev=beautifulness[0];
        beautifulness[0]=0;
        
        for(int i=1;i<n;i++)
        {
            int curr=beautifulness[i];
            if(curr==prev)
            beautifulness[i]=beautifulness[i-1];
            else
            beautifulness[i]=i;
            prev=curr;
        }
        
        for(int i=0;i<q;i++)
        {
            int start=queries[i][0]-1;
            int end=queries[i][1]-1;
            
            if(beautifulness[start]==beautifulness[end])
            v.push_back(1);
            else
            v.push_back(0);
        }
        return v;
}



Java -:
public static int[] canTrade(int n, int[] beautifulness, int q, int[][] queries)
{
        int []ans=new int[q];
        
        int prev=beautifulness[0];
        beautifulness[0]=0;
        
        for(int i=1;i<n;i++)
        {
            int curr=beautifulness[i];
            if(curr==prev)
            beautifulness[i]=beautifulness[i-1];
            else
            beautifulness[i]=i;
            prev=curr;
        }
        
        for(int i=0;i<q;i++)
        {
            int low=queries[i][0]-1;
            int high=queries[i][1]-1;
            
            if(beautifulness[low]==beautifulness[high])
            ans[i]=1;
            else
            ans[i]=0;
        }
        return ans;
}