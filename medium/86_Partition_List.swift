//
//  86_Partition_List.swift
//  LeetCode
//
//  Created by wangzhe on 2018/9/21.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/**
 * NO.86
 * Given a linked list and a value x, partition it such that all nodes less than x come
 * before nodes greater than or equal to x.
 *
 * Example:
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 */

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    func partition(_ head: ListNode?, _ x: Int) -> ListNode? {
        guard head != nil else {
            return nil
        }
        let left = ListNode(0), right = ListNode(0)
        var p = left, q = right, node = head
        while node != nil {
            if node!.val < x {
                p.next = node
                p = node!
            } else {
                q.next = node
                q = node!
            }
            node = node!.next
        }
        q.next = nil
        p.next = right.next
        return left.next
    }
}
