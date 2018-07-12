//
//  215_Kth_Largest_Element_in_an_Array.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/12.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO. 215
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 */

class Solution {
    func findKthLargest(_ nums: [Int], _ k: Int) -> Int {
        var arr = nums, low = 0, high = nums.count - 1, result = nums[0]
        if low < high {
            var index = partition(&arr, low, high)
            while index != k - 1 {
                if index < k - 1 {
                    index = partition(&arr, index + 1, high)
                } else {
                    index = partition(&arr, low, index - 1)
                }
            }
            result = arr[index]
        }
        return result
    }
    
    func partition(_ nums: inout [Int], _ low: Int, _ high: Int) -> Int {
        let mid = nums[high]
        var l = low, h = high
        while l < h {
            while nums[l] >= mid && l < h {
                l += 1
            }
            nums[h] = nums[l]
            while nums[h] < mid && l < h {
                h -= 1
            }
            nums[l] = nums[h]
        }
        nums[l] = mid
        return l
    }
}
