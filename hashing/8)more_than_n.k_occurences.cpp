https://www.geeksforgeeks.org/problems/count-element-occurences/1

Java -:
Code-:
public int countOccurence(int[] arr, int n, int k) 
    {
        HashMap<Integer,Integer>m=new HashMap<>();
        for(int i=0;i<n;i++)
        {
            m.put(arr[i],m.getOrDefault(arr[i],0)+1);
        }
        
        int count=0;
        for(var x:m.entrySet())
        {
            if(x.getValue()>n/k)
            count++;
        }
        return count;
    }

C++ -:
Code-:
int countOccurence(int arr[], int n, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        
        int count=0;
        for(auto x:m)
        {
            if(x.second>n/k)
            count++;
        }
        return count;
    }
