https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1


































Solution 1-:
Code-:
vector <int> countDistinct (int A[], int n, int k)
{
        vector<int>v;
        for(int i=0;i<=n-k;i++)
        {
            unordered_set<int>s;
            for(int j=i;j<k+i;j++)
            {
                s.insert(A[j]);
            }
            v.push_back(s.size());
        }
        return v;
}


Solution 2-:
C++

Code-:
vector <int> countDistinct (int A[], int n, int k)
{
        vector<int>v;
        unordered_map<int,int>m;
        for(int i=0;i<k;i++)
        {
            m[A[i]]++;
        }
        v.push_back(m.size());
        
        int j=0;
        for(int i=k;i<n;i++,j++)
        {
            m[A[j]]--;
            if(m[A[j]]==0)
            m.erase(A[j]);
            
            m[A[i]]++;
            v.push_back(m.size());
        }
        return v;
}



Java -:
ArrayList<Integer> countDistinct(int A[], int n, int k)
{
        ArrayList<Integer>list=new ArrayList<>();
        HashMap<Integer,Integer>m=new HashMap<>();
        for(int i=0;i<k;i++)
        {
            m.put(A[i],m.getOrDefault(A[i],0)+1);
        }
        
        list.add(m.size());
        
        int j=0;
        for(int i=k;i<n;i++,j++)
        {
            m.put(A[j],m.get(A[j])-1);
            if(m.get(A[j])==0)
            m.remove(A[j]);
            
            m.put(A[i],m.getOrDefault(A[i],0)+1);
            list.add(m.size());
        }
        return list;
}