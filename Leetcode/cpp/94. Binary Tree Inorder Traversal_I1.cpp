/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List <Integer> res = new ArrayList <>();
        Stack <TreeNode> stack = new Stack <>();
        TreeNode curr = root;
        while (true) {
            if(Objects.nonNull(root)){
                stack.push(root);
                root=root.left;
            }
            else if(!stack.isEmpty()){
                root=stack.pop();
                res.add(root.val);
                root=root.right;
            }else break;
        }
        
        return res;
    }
}
