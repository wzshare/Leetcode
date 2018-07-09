//
//  226_Invert_Binary_Tree.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/9.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}

class Solution {
    // recursive
    func invertTree(_ root: TreeNode?) -> TreeNode? {
        guard let root = root else {
            return nil
        }
        (root.left, root.right) = (root.right, root.left)
        invertTree(root.left)
        invertTree(root.right)
        return root
    }
    // iterative
    func invertTree1(_ root: TreeNode?) -> TreeNode? {
        guard let root = root else {
            return nil
        }
        var queue = [TreeNode]()
        queue.append(root)
        while !queue.isEmpty {
            let node = queue.removeFirst()
            (node.left, node.right) = (node.right, node.left)
            if let left = node.left {
                queue.append(left)
            }
            if let right = node.right {
                queue.append(right)
            }
        }
        return root
    }
}
