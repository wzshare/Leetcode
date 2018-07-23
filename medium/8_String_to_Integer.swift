//
//  8_String_to_Integer.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/23.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

class Solution {
    func myAtoi(_ str: String) -> Int {
        var flag = 0, result = 0;
        let nums: [Character] = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];
        let int_max = 2147483647
        let int_min = -2147483648
        for ch in str {
            var temp = result
            if ch == " " && flag == 0 {
                continue
            } else if ch == "-" && flag == 0 {
                flag = -1;
            } else if ch == "+" && flag == 0 {
                flag = 1;
            } else if !nums.contains(ch) {
                return result
            } else {
                flag = flag == 0 ? 1 : flag;
                temp = temp * 10 + nums.index(of: ch)! * flag;
            }
            if temp <= int_max && temp >= int_min {
                result = temp
            } else {
                return flag == 1 ? int_max : int_min
            }
        }
        return result
    }
}
