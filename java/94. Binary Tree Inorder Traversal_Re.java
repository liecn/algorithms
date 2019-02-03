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
        List<Integer> res=new ArrayList<Integer>();
        travIn_R(root,res);
        return res;
    }
    
    public void travIn_R(TreeNode root, List <Integer> res) {
        if (Objects.isNull(root)) return;
        travIn_R(root.left, res);
        res.add(root.val);
        travIn_R(root.right, res);
    }
}
