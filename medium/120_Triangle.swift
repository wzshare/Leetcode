//
//  120_Triangle.swift
//  LeetCode
//
//  Created by wangzhe on 2018/8/10.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 * To do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */

class Solution {
    // from bottom to top
    func minimumTotal1(_ triangle: [[Int]]) -> Int {
        guard triangle.count > 0 else {
            return 0
        }
        var dp = triangle.last!
        for i in stride(from: triangle.count - 2, through: 0, by: -1) {
            for j in 0...i {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j]
            }
        }
        return dp[0]
    }
    
/*
    // from top to bottom
    func minimumTotal1(_ triangle: [[Int]]) -> Int {
        var result = Array(repeating: 0, count: triangle.count)
        for row in triangle {
            for index in stride(from: row.count - 1, through: 0, by: -1) {
                if index == 0 {
                    result[0] += row[0]
                } else if index == row.count - 1 {
                    result[index] = result[index - 1] + row[index]
                } else {
                    result[index] = min(result[index], result[index - 1]) + row[index]
                }
            }
        }
        return result.min()!
    }
*/
}
