//
//  153_Find_Minimum_in_Rotated_Sorted_Array.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/5.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.153
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 *
 * Example 1:
 *
 * Input: [3,4,5,1,2]
 * Output: 1
 *
 */

class Solution {
    func findMin(_ nums: [Int]) -> Int {
        var low = 0, high = nums.count - 1
        while nums[low] > nums[high] {
            if high - low == 1 {
                return nums[high]
            }
            let mid = (low + high) / 2
            if nums[mid] > nums[low] {
                low = mid
            } else {
                high = mid
            }
        }
        return nums[low]
    }
    
    func findMin1(_ nums: [Int]) -> Int {
        let low = 0, high = nums.count - 1
        if nums[low] < nums[high] || low == high || high - low == 1 {
            return min(nums[low], nums[high])
        }
        let mid = (low + high) / 2
        if nums[low] < nums[mid] {
            return findMin(Array(nums[mid...high]))
        } else {
            return findMin(Array(nums[low...mid]))
        }
    }
}
