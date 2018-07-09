//
//  112_Path_Sum.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/9.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.112
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf
 * path such that adding up all the values along the path equals the given sum.
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
    func hasPathSum(_ root: TreeNode?, _ sum: Int) -> Bool {
        let val = root?.val
        if root?.left == nil && root?.right == nil {
            return sum == val
        }
        return hasPathSum(root?.left, sum - val!) ||
            hasPathSum(root?.right, sum - val!)
    }
}
