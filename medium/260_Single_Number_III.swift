//
//  260_Single_Number_III.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/16.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

class Solution {
    func singleNumber(_ nums: [Int]) -> [Int] {
        var temp = nums.reduce(0, ^)
        var last = 0
        while temp & 1 == 0 {
            last += 1
            temp >>= 1
        }
        let first = nums.filter { val -> Bool in
            (val >> last) & 1 == 1
        }
        let second = nums.filter { val -> Bool in
            (val >> last) & 1 == 0
        }
        return [first.reduce(0, ^), second.reduce(0, ^)]
    }
}
