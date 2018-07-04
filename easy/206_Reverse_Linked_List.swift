//
//  206_Reverse_Linked_List.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/4.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.206
 * Reverse a singly linked list.
 *
 * Example:
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 */

class Solution {
    func reverseList(_ head: ListNode?) -> ListNode? {
        var node = head
        if head != nil && head?.next != nil {
            node = reverseList(head?.next)
            head?.next?.next = head
            head?.next = nil
        }
        return node
    }
    func reverseList1(_ head: ListNode?) -> ListNode? {
        var pre: ListNode? = nil, node = head
        while node != nil {
            let next = node?.next
            node?.next = pre
            pre = node!
            node = next
        }
        return pre
    }
}

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}
