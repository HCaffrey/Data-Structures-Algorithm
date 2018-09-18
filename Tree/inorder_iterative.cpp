vector<int> inorder_iterative(BinaryTreeNode* root) {
   /*every time cur node is either:
    * - root of an unchecked left side tree
    * - nullptr
    */
    if(!root) return{};
    vector<int> result;
    BinaryTreeNode* prev = root;
    BinaryTreeNode* cur = root;
    stack<BinaryTreeNode*> s;
    while(!s.empty() || cur!=nullptr){
        while(cur){
            s.push(cur);
            cur = cur->left;
        }
        result.push_back(s.top()->data);
        cur = s.top()->right;
        s.pop();
    }

    return result;
}