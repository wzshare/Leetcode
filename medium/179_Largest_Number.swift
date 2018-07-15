//
//  179_Largest_Number.swift
//  LeetCode
//
//  Created by 王哲 on 2018/7/15.
//  Copyright © 2018年 WangZhe. All rights reserved.
//

import Foundation

/*
 * NO.179
 * Given a list of non negative integers, arrange them such that they form the largest number.
 */

class Solution {
    func largestNumber(_ nums: [Int]) -> String {
        guard nums.count > 0 else {
            return ""
        }
        guard nums.filter({$0 > 0}).count > 0 else {
            return "0"
        }
        var strNums = nums.map { value in
            String(value)
        }
        strNums.sort { (str1, str2) -> Bool in
            let combine1 = str1 + str2
            let combine2 = str2 + str1
            return combine1 > combine2
        }
        return strNums.reduce("", +)
    }
}
