//
//  344_Reverse_String.swift
//  testSwift
//
//  Created by wangzhe on 2018/6/15.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * No.344
 * Write a function that takes a string as input and returns the string reversed.
 *
 * Example:
 * Given s = "hello", return "olleh".
 */

class Solution {
    func reverseString(_ s: String) -> String {
        var res: String = ""
        for ch in s {
            res = String(ch) + res
        }
        return res
    }
    
    func reverseString1(_ s: String) -> String {
        return s.reduce("", { x, y in
            String(y) + x
        })
    }
}


