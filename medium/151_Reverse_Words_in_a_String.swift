//
//  151_Reverse_Words_in_a_String.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/16.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.151
 * Given an input string, reverse the string word by word.
 *
 * Example:
 * Input: "the sky is blue",
 * Output: "blue is sky the".
 */

class Solution {
    func reverseWords(_ s: String) -> String {
        var res = _reverse(s)
        let slipts = res.split(separator: " ")
        let reverses = slipts.map({ _reverse(String($0)) + " " })
        res = reverses.reduce("", +)
        return String(res[res.startIndex ..< res.index(before: res.endIndex)])
    }
    
    func reverseWords1(_ s: String) -> String {
        return s.split(separator: " ").reduce("", {(x, y) in
            return y + " " + x })
    }
    
    private func _reverse(_ s: String) -> String {
        return s.reduce("", {x, y in String(y) + x})
    }
};
