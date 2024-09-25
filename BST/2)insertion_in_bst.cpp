C++
Node* insert(Node* node, int data)
{
          if(node==NULL)
          return new Node(data);
          if(node->data==data)
          return root;
          if(root->data<data)
          node->right=insert(node->right,data);
          else
          node->left=insert(node->left,data);
          return node;
}


Java-:
Node insert(Node root, int Key) {
        if(root==null) return new Node(Key);
        if(root.data==Key) return root;
        if(root.data<Key)
        root.right=insert(root.right,Key);
        else
        root.left=insert(root.left,Key);
        return root;
}

