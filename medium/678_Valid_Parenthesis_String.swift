//
//  678_Valid_Parenthesis_String.swift
//  LeetCode
//
//  Created by wangzhe on 2018/8/1.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.678
 * Given a string containing only three types of characters: '(', ')' and '*', write a function to
 * check whether this string is valid. We define the validity of a string by these rules:
 *
 * 1. Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * 2. Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * 3. Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * 4. '*' could be treated as a single right parenthesis ')' or a single left parenthesis
 *    '(' or an empty string.
 * 5. An empty string is also valid.
 */

class Solution {
    func checkValidString(_ s: String) -> Bool {
        var a = 0, b = 0
        for c in s {
            if c == "(" {
                a += 1
                b += 1
            } else if c == ")" {
                a -= 1
                b -= 1
            } else {
                a -= 1
                b += 1
            }
            a = max(0, a)
            if b < 0 {
                return false
            }
        }
        return a == 0
    }
}
