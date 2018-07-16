//
//  441_Arranging_Coins.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/16.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * You have a total of n coins that you want to form in a staircase shape,
 * where every k-th row must have exactly k coins.
 *
 * Given n, find the total number of full staircase rows that can be formed.
 *
 * n is a non-negative integer and fits within the range of a 32-bit signed integer.
 */

class Solution {
    func arrangeCoins(_ n: Int) -> Int {
        if n == 0 {
            return 0
        }
        var res = 1, sum = n
        while (sum - res > res) {
            sum -= res
            res += 1
        }
        return res
    }
}
