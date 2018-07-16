//
//  557_Reverse_Words_in_a_String_III.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/16.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 *
 * Example 1:
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 */

class Solution {
    func reverseWords(_ s: String) -> String {
        guard s.count > 0 else {
            return ""
        }
        var res = s.split(separator: " ").map{ $0.reversed() }.reduce(""){ $0 + " " + $1}
        res.remove(at: res.startIndex)
        return res
    }
}
