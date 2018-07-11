//
//  113_Path_Sum_II.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/10.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.113
 * Given a binary tree and a sum, find all root-to-leaf paths where
 * each path's sum equals the given sum.
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
    func pathSum(_ root: TreeNode?, _ sum: Int) -> [[Int]] {
        var result = [[Int]](), path = [Int]()
        dfs(root, sum, &path, &result)
        return result
    }
    
    func dfs(_ root: TreeNode?, _ sum: Int, _ path: inout [Int], _ result: inout [[Int]]) {
        guard let root = root else {
            return
        }
        path.append(root.val)
        if root.val == sum && root.left == nil && root.right == nil {
            result.append(path)
        }
        dfs(root.left, sum - root.val, &path, &result)
        dfs(root.right, sum - root.val, &path, &result)
        path.removeLast()
    }
}
