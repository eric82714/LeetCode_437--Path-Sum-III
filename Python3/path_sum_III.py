# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        counts = [0]
        
        def helper(root, sums):
            if not root: return
            sums = [s + root.val for s in sums] + [root.val]
            counts[0] += sums.count(sum)
            helper(root.left, sums)
            helper(root.right, sums)
        
        helper(root, [])
        
        return counts[0]
