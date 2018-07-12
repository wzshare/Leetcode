//
//  53_Maximum_Subarray.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/12.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.53
 * Given an integer array nums, find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 */

class Solution {
    func maxSubArray(_ nums: [Int]) -> Int {
        guard nums.count > 0 else {
            return -1
        }
        var cur = 0, res = nums[0]
        for num in nums {
            if cur <= 0 {
                cur = num
            } else {
                cur += num
            }
            if cur > res {
                res = cur
            }
        }
        return res
    }
}
