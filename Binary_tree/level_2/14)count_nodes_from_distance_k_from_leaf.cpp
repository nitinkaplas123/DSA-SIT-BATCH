Solution 1-:
Steps-:
1) here using helper function we check every node.
2) here using solve function we check the current node having leaf node at distance k or not.
   if(at distance k there is leaf node)
   count++;
3) return count;


Code-:Time->O(N*K) 
here helper function go to every node ->O(N)
here solve function go to the depth of tree -> O(k)
Time ->O(N*K)

int count=0;
    bool solve(Node* root,int k)
    {
        if(root==NULL) return false;
        
        if(k==0)
        {
            if(root->left==NULL and root->right==NULL)
            return true;
        }
        int left=solve(root->left,k-1);
        int right=solve(root->right,k-1);
        
        return (left || right);
     }
    void helper(Node* root,int k)
    {
        if(root==NULL) return ;
        
        if(solve(root,k))
        count++;
        
        helper(root->left,k);
        helper(root->right,k);
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
    	 helper(root,k);
    	 return count;
    }


Solution 2-:
Steps-:
1)Here we make array[height];
2)Here we add all the values from root to leaf nodes into array.
3)If count is the index number where we add the value of node.
4)if we reach to leaf node then 
  check-: if count>=k 
          [1,2,4]   k=2 and 4 is leaf and we started from 1 so here 1 node is  our root node to store.
          set.insert(arr[count-k]); which is 1.
5)as for all.


Code-: Time->O(N) Space->O(N)
unordered_set<Node*>s;
int height(Node* root)
{
        if(root==NULL) return 0;
        int left=height(root->left);
        int right=height(root->right);
        return 1+max(left,right);
}

void helper(Node* root,Node* arr[],int count,int k)
    {
        if(root==NULL) return ;
        arr[count]=root;
        
        if(root->left==NULL and root->right==NULL)
        {
            if(count>=k)
            s.insert(arr[count-k]);
            return ;
        }
        
        helper(root->left,arr,count+1,k);
        helper(root->right,arr,count+1,k);
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
    	int maxx=height(root);
    	Node* arr[maxx];
    	int count=0;
    	helper(root,arr,count,k);
    	return s.size();
 }