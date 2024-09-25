https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-149/problems






























Code-:
int minJumps(int n, vector<int> &arr) {
        unordered_map<int,int>m;
        
        int ans=n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(m.find(arr[i])!=m.end())
            ans=min(ans,n-(m[arr[i]]-i));
            else
            m[arr[i]]=i;
        }
        return ans;
}


In Java -:
public static int minJumps(int n, int[] arr) {
        HashMap<Integer,Integer>m=new HashMap<>();
        int ans=n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(m.containsKey(arr[i]))
            ans=Math.min(ans,(n-((m.get(arr[i]))-i)));
            else
            m.put(arr[i],i);
        }
        return ans;
}