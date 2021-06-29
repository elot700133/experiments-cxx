// in order traversal - recursion
class SolutionInOrderRecur {
public:
    void recur(TreeNode* n, vector<int>& v) {
        if(!n) return;
        v.push_back(n->val);
        recur(n->left,v);
        recur(n->right,v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        recur(root,v);
        return v;
    }
};

// in order traversal - iterative
class SolutionInOrderIter {
public:   
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            if(cur) {
                v.push_back(cur->val);
                s.push(cur->right);
                s.push(cur->left);
            }
        }
        return v;
    }
};
