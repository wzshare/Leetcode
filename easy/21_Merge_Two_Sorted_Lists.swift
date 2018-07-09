//
//  21_Merge_Two_Sorted_Lists.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/9.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if l1 == nil {
            return l2
        } else if l2 == nil{
            return l1
        }
        var head: ListNode?
        if (l1?.val)! < (l2?.val)! {
            head = l1
            head?.next = mergeTwoLists(l1?.next, l2)
        } else {
            head = l2
            head?.next = mergeTwoLists(l1, l2?.next)
        }
        return head
    }
}
