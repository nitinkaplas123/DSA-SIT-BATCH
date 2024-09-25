Solution 1-:
Steps-:
1)Constructing the Height-Balanced BST:
1.1 We can construct a height-balanced BST from a sorted array by choosing the middle element as the root node
and recursively constructing the left and right subtrees from the left and right halves of the array, respectively.
1.2 This ensures that the depth of the left subtree and the right subtree of every node never differs by more than 1.

2)Preorder Traversal:
After constructing the height-balanced BST, we can perform a preorder traversal to obtain the preorder sequence 
of the tree.
3)Finding the Lexicographically Smallest Preorder:
3.1 If there are multiple height-balanced BSTs possible from the same sorted array, we need to find the one with the
lexicographically smallest preorder.
3.2 To achieve this, we can ensure that we always choose the left subtree first whenever we have multiple choices 
for constructing the tree. This guarantees that the preorder traversal will be lexicographically smallest.


Two steps-:
1. To solve the problem height balanced -> we find the middle element and split the left and right with equal 
                                           number of elements.

2. To solve the problem of lexicographically smallest -> we print it into preorder fashion.
  
Code-:
void helper(vector<int>& nums,int start,int end,vector<int>&v)
{
        if(start>end) return ;
        int mid=(start+end)/2;
        
        v.push_back(nums[mid]);
        
        helper(nums,start,mid-1,v);
        helper(nums,mid+1,end,v);
}
vector<int> sortedArrayToBST(vector<int>& nums) {
       vector<int>v;
       int n=nums.size();
       int start=0;
       
       int end=n-1;
       helper(nums,start,end,v);
       return v;
}


Java -:
void helper(int []nums,int start,int end,ArrayList<Integer>list)
    {
        if(start>end) return;
        int mid=(start+end)/2;
        list.add(nums[mid]);
        
        helper(nums,start,mid-1,list);
        helper(nums,mid+1,end,list);
    }
    public int[] sortedArrayToBST(int[] nums)
    {
       ArrayList<Integer>list=new ArrayList<>();
       int n=nums.length;
       int []ans=new int[n];
       int start=0;
       int end=n-1;
       helper(nums,start,end,list);
       for(int i=0;i<list.size();i++)
       {
           ans[i]=list.get(i);
       }
       return ans;
    }