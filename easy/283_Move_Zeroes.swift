//
//  283_Move_Zeroes.swift
//  LeetCode
//
//  Created by wangzhe on 2018/8/31.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * Given an array nums, write a function to move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements.
 */

class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var i = 0
        for j in 0..<nums.count {
            if nums[j] != 0 {
                (nums[i], nums[j]) = (nums[j], nums[i])
                i += 1
            }
        }
    }
}
