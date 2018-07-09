//
//  572_Subtree_of_Another_Tree.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/9.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.572
 * Given two non-empty binary trees s and t, check whether tree t has
 * exactly the same structure and node values with a subtree of s. A
 * subtree of s is a tree consists of a node in s and all of this node's
 * descendants. The tree s could also be considered as a subtree of itself.
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
    func isSubtree(_ s: TreeNode?, _ t: TreeNode?) -> Bool {
        var result = false
        if s != nil && t != nil {
            if s?.val == t?.val {
                result = helper(s, t)
            }
            if result == false {
                result = isSubtree(s?.left, t)
            }
            if result == false {
                result = isSubtree(s?.right, t)
            }
        }
        return result
    }
    func helper(_ s: TreeNode?, _ t: TreeNode?) -> Bool {
        if t == nil && s == nil {
            return true
        }
        if t == nil && s != nil {
            return false
        }
        if t != nil && t == nil {
            return false
        }
        if s?.val != t?.val {
            return false
        }
        return helper(s?.left, t?.left) && helper(s?.right, t?.right)
    }
}
