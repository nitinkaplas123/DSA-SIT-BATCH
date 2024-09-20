Question link-:
https://practice.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1

Solution -:
Steps-:
1)Here we are using hashset to store unique key.
2)here we use concept of top view root->0 
3)if we go to left side curr-1 
4)if we go to right side curr+1
5)using this we can store no. of vertical width size in hashset.


Code-: Time->O(N) Space ->O(N)
void helper(Node* root,unordered_set<int>&s,int h)
{
        if(root==NULL) return ;
        s.insert(h);
        helper(root->left,s,h-1);
        helper(root->right,s,h+1);
}
int verticalWidth(Node* root)
{
   unordered_set<int>s;
   helper(root,s,0);
   return s.size();
}


Solution 2-:
Steps-:
1)Here we use same approach but with hashset.
2)We make two variables maxi,mini which stores the minimum index and maximum will store maxi index
3)here index means like we start with 0 and go left side so -1,-2,-3,-4
4)same for max 0,1,2,3,4
5)At last we add both  =>(maxi+mini)+1 here +1 is for root node with 0 index



Code-: Time->O(N) Space ->O(1) 
void helper(Node* root,int &maxi,int &mini,int curr)
{
    if(root==NULL)
    return ;
    if(curr<mini)mini=curr;
    if(curr>maxi)maxi=curr;
    helper(root->left,maxi,mini,curr-1);
    helper(root->right,maxi,mini,curr+1);
}
int verticalWidth(Node* root)
{
   if(root==NULL) return 0;
   int maxi=0;
   int mini=0;
   int curr=0;
   helper(root,maxi,mini,curr);
   return (maxi+abs(mini))+1;
}