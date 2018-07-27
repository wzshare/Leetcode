//
//  203_Remove_Linked_List_Elements.swift
//  LeetCode
//
//  Created by wangzhe on 2018/7/27.
//  Copyright © 2018年 wangzhe. All rights reserved.
//

import Foundation

/*
 * NO.203
 * Remove all elements from a linked list of integers that have value val.
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
    func removeElements(_ head: ListNode?, _ val: Int) -> ListNode? {
        let dummy = ListNode(0)
        dummy.next = head
        var node = dummy
        
        while node.next != nil {
            if node.next!.val == val {
                node.next = node.next!.next
            } else {
                node = node.next!
            }
        }
        
        return dummy.next
    }
}
