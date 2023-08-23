import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class L107 {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Queue<TreeNode> q=new LinkedList<TreeNode>();
        q.offer(root);
        List<List<Integer>> re=new LinkedList<>();
        while(!q.isEmpty())
        {
            int len=q.size();
            List<Integer> l_data=new ArrayList<Integer>();
            for(int i=0;i<len;i++)
            {
                TreeNode now=q.poll();
                l_data.add(now.val);
                if(now.left!=null)
                q.offer(now.left);
                if(now.right!=null)
                q.offer(now.right);
            }
            re.add(l_data);
        }
        Collections.reverse(re);
        return re;
    }

        public static void main(String[] args) {
            // 创建一个二叉树进行测试
            TreeNode root = new TreeNode(3);
            root.left = new TreeNode(9);
            root.right = new TreeNode(20);
            root.right.left = new TreeNode(15);
            root.right.right = new TreeNode(7);
    
            // 创建Solution对象
            L107 solution = new L107();
    
            // 调用levelOrderBottom方法进行层序遍历
            List<List<Integer>> result = solution.levelOrderBottom(root);
    
            // 输出结果
            for (List<Integer> list : result) {
                System.out.println(list);
            }
        }
}
