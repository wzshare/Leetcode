//
//  46_Permutations.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/11.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/**
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 * Input: [1,2,3]
 * Output:
 * [
 *    [1,2,3],
 *    [1,3,2],
 *    [2,1,3],
 *    [2,3,1],
 *    [3,1,2],
 *    [3,2,1]
 * ]
*/

class Solution {
    func permute(_ nums: [Int]) -> [[Int]] {
        var result = [[Int]](), next = nums
        if nums.count == 0 {
            return result
        }
        dfs(nums, &next, 0, &result)
        return result
    }
    
    func dfs(_ nums: [Int], _ next: inout [Int], _ begin: Int, _ result: inout [[Int]]) {
        if begin == nums.count {
            result.append(nums)
        } else {
            for i in begin..<nums.count {
                next.swapAt(i, begin)
                dfs(next, &next, begin + 1, &result)
                next.swapAt(i, begin)
            }
        }
    }
}
