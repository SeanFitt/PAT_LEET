from collections import deque
from typing import List, Optional
from TreeNode import TreeNode

class L107:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        q=deque()
        q.append(root)
        res=[]
        if not root:
            return res
        while q:
            size=len(q)
            l_data=[]
            for _ in range(size):
                now=q.pop()
                l_data.append(now.val)
                if now.left:
                    q.append(now.left)
                if now.right:
                    q.append(now.right)
            res.append(l_data)
        res.reverse()
        return res
    
def main():
    # 创建一个二叉树进行测试
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    # 创建 Solution 对象
    solution = L107()

    # 调用 levelOrderBottom 方法进行层序遍历
    result = solution.levelOrderBottom(root)

    # 输出结果
    for level in result:
        print(level)

if __name__ == '__main__':
    main()