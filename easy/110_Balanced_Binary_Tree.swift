//
//  110_Balanced_Binary_Tree.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/16.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * Given a binary tree, determine if it is height-balanced.
 */

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
    func isBalanced(_ root: TreeNode?) -> Bool {
        return helper(root) != -1
    }
    
    func helper(_ root: TreeNode?) -> Int {
        guard let root = root else {
            return 0
        }
        let left = helper(root.left), right = helper(root.right)
        if left == -1 || right == -1 {
            return -1
        }
        if abs(left - right) > 1 {
            return -1
        }
        return max(left, right) + 1
    }
}
