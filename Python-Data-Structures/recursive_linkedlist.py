#singly linked list written recursively

import random


# ------------------------------------
class Node:
    def __init__(self, initdata):
        self.data = initdata
        self.next = None

    def getData(self):
        return self.data

    def getNext(self):
        return self.next

    def setData(self, newdata):
        self.data = newdata

    def setNext(self, newnext):
        self.next = newnext

    def __str__(self):
        return "<" + str(self.data) + ">"


# ------------------------------------
class LinkedList1:
    def __init__(self):
        self.head = None  # always points to first node in list
        self.num_nodes = 0  # counter keeps track of number of nodes in list

    # original non-recursive search
    def search(self, item):
        current = self.head
        found = False
        while current != None and not found:
            if current.getData() == item:
                found = True
            else:
                current = current.getNext()
        return found

    # ---------
    def searchRec(self, target):  # return bool if target is in the list
        return self.searchOnNode(self.head, target)

    def searchOnNode(self, node, target):  # recursive helper function
        if node is None:
            return False
        if node.getData() == target:
            return True
        return self.searchOnNode(node.next, target)

    # ---------

    def sumRec(self):
        return self.sumOnNode(self.head)

    def sumOnNode(self, node):
        if node is None:
            return 0
        else:
            return node.getData() + self.sumOnNode(node.next)

    # ---------



    def isEmpty(self):
        return self.head == None

    def add(self, item):
        temp = Node(item)
        temp.setNext(self.head)
        self.head = temp
        self.num_nodes += 1

    def load(self, data):
        """convenience function to bulk-add items from a Python iterable like a list or range result"""
        for i in data:
            self.add(i)

    def size(self):
        return self.num_nodes
        # STUDENTS: The original version is given below.  We replaced it with the code above this.
        # current = self.head
        # count = 0
        # while current != None:
        #     count = count + 1
        #     current = current.getNext()
        # return count

    def append(self, item):
        temp = Node(item)
        # STUDENTS: The original version is given below.  We replaced it with the code below that,
        #    but the version here may not reflect all the changes/fixes we talked about in class.
        current = self.head
        previous = None
        while current != None:
            previous = current
            current = current.getNext()
        previous.setNext(temp)

    def get(self, index):
        if index < 0 or index >= self.num_nodes:
            raise IndexError('IndexError in get()')
        current = self.head
        for i in range(index):
            current = current.next
        return current

    def index(self, item):
        current = self.head
        found = False
        posn = 0
        while current != None and not found:
            if current.getData() == item:
                found = True
            else:
                posn += 1
                current = current.getNext()
        if not found:
            raise ValueError('ValueError in index() because item not found')
        return posn

    def __str__(self):
        res = "["
        current = self.head
        while current != None:
            res += str(current) + ","
            current = current.getNext()
        return res + "]"




    def clip(self, max):
        return self.clipRec(self.head, max)

    def clipRec(self, node, max):
        if node is None:
            return 0
        elif node.data > max:
            node.data = max
            return 1 + self.clipRec(node.next, max)
        else:
            return 0 + self.clipRec(node.next, max)









# ------------------------------------

def test_search():
    list1 = LinkedList1()
    list1.load([20, 18, 12, 16, 14, 10])

    assert list1.searchRec(12), "Error searching for 12 in " + str(list1)
    assert list1.searchRec(20), "Error searching for 20 in " + str(list1)
    assert list1.searchRec(10), "Error searching for 10 in " + str(list1)
    assert not list1.searchRec(99), "Error searching for 99 in " + str(list1)

    # code below needed for searching nested lists in the list

    # list1.add( [1, 2, 3] )  # 1st item is a Python list object
    # print('list1 is now:', list1)
    # print('type() of 1st value in list1', type(list1.head.getData()))
    # print('Is type() of 1st value in list1 a list?', type([]) == type(list1.head.getData()))

    # list2 = LinkedList1()
    # list2.load([7, 8])
    # list1.add(list2)  # 1st item is a LinkedList1 object
    # print('list1 is now:', list1)
    # print('type() of 1st value in list1', type(list1.head.getData()))
    # print('Is type() of 1st value in list1 a LinkedList1?', type(list1) == type(list1.head.getData()))


# ------------------------------------
def test_sum():
    list1 = LinkedList1()
    list1.load([20, 18, 12, 16, 14, 10])
    list2 = LinkedList1()
    assert list2.sumRec() == 0, "wsdf"
    list2.load([1, 2, 3])
    assert list2.sumRec() == 6, "hello"
    assert list1.sumRec() == 20 + 18 + 12 + 16 + 14 + 10,  "wrong"


def test_clip():
    list1 = LinkedList1()
    list1.load([20, 18, 12, 16, 14, 10])
    assert list1.clip(18) == 1
    #print(list1)



# ------------------------------------
if __name__ == "__main__":
    test_search()
    test_sum()
    test_clip()