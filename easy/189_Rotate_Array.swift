//
//  189_Rotate_Array.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/16.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
 */
class Solution {
    func rotate(_ nums: inout [Int], _ k: Int) {
        let slice = nums.count - k % nums.count
        let first: Array = nums[0..<slice].reversed()
        let second: Array = nums[slice..<nums.count].reversed()
        nums = first + second
        nums = Array(nums.reversed())
    }
}
