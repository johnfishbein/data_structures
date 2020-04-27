# doubly linked list
#jhf5my homework

class Node2:
    def __init__(self, initdata):
        self.data = initdata
        self.next = None
        self.prev = None

    def getData(self):
        return self.data

    def getNext(self):
        return self.next

    def setData(self, newdata):
        self.data = newdata

    def setNext(self, newnext):
        self.next = newnext

    def getPrev(self):
        return self.prev

    def setPrev(self, newprev):
        self.prev = newprev

    def __str__(self):
        return "<"+ str(self.data) + ">"


# ------------------------------------


class LinkedList2:

    def __init__(self):
        self.head = None        # always points to first node in list
        self.num_nodes = 0      # counter keeps track of number of nodes in list
        self.last = None        # always points to last node in list

    def isEmpty(self):
        return self.head is None

    #modify xx
    def add(self, item):
        # adds item to beginning of list --constant time
        temp = Node2(item)
        if self.isEmpty():
            self.last = temp
        else:
            self.head.prev = temp  ## only change required

        temp.next = self.head
        self.head = temp
        self.num_nodes += 1  # modification due to storing size in list object



    def load(self, data):
        """convenience function to bulk-add items from a Python iterable like a list or range result"""
        for i in data:
            self.add(i)

    def size(self):
        return self.num_nodes
        # old version below
        # current = self.head
        # count = 0
        # while current is not None:
        #     count = count + 1
        #     current = current.getNext()
        # return count

    def search(self, item):
        current = self.head
        found = False
        while current is not None and not found:
            if current.getData() == item:
                found = True
            else:
                current = current.getNext()
        return found

    # modify xx
    def append(self, item):
        # adds to end of list
        # new version O(1)
        temp = Node2(item)
        if self.isEmpty():
            self.head = temp
        else:
            self.last.next = temp
            temp.prev = self.last
        self.last = temp
        self.num_nodes += 1


    def __str__(self):
        res = "["
        current = self.head
        while current is not None:
            res += str(current)
            current = current.getNext()
            if current is not None: # avoid comma after last item (it was bugging me)
                res += ","
        return res + "]"

    # modify xx
    def pop(self):
        # constant time --> old version O(n)
        if self.isEmpty():
            return None

        ret = self.last.data
        if self.num_nodes == 1:
            self.head = None
            self.last = None
        else:
            self.last = self.last.prev
            self.last.next = None

        self.num_nodes -= 1
        return ret

    def get(self, index):
        if index >= self.num_nodes or index < 0 or self.num_nodes == 0:
            raise IndexError('index out of range')
        else:
            i = 0
            current = self.head
            while i < index:
                current = current.getNext()
                i += 1
            return current

    def index(self, item):
        current = self.head
        found = False
        i = 0
        while current is not None and not found:
            if current.getData() == item:
                return i
            else:
                current = current.getNext()
                i += 1
        if not found:
            raise ValueError("item not in linkedlist")

    # modify
    def insert(self, index, item):
        if index < 0:
            raise IndexError('index out of range')
        if index == 0:  # uses add method to put item at beginning
            self.add(item)
        elif index >= self.num_nodes:  # uses append to put item at end
            self.append(item)
        else:
            temp = Node2(item)
            i = 0
            current = self.head
            previous = None
            while i < index:
                previous = current
                current = current.getNext()
                i += 1
            previous.next = temp ##changes
            temp.prev = previous
            temp.next = current
            current.prev = temp
            self.num_nodes += 1

    # modify
    def remove_at(self, index): # special case for index = 0
        if index >= self.num_nodes or index < 0:  # takes care of indicies out of range
            raise IndexError('index out of range')
        elif self.num_nodes == 0:
            raise IndexError("can't remove from empty list")

        if index == 0:
            ret = self.head.data
            self.head = self.head.next
            self.head.prev = None # change
            if self.num_nodes == 1:
                self.last = None
            self.num_nodes -= 1
            return ret

        # if get to this point then linkedlist not empty and index != 0 and index not out of range
        i = 0
        current = self.head
        previous = None

        while i < index:
            previous = current
            current = current.next
            i += 1
        ret = current.data
        previous.next = current.next
        if index == self.num_nodes - 1:
            self.last = previous
        else:
            current.next.prev = previous
        self.num_nodes -= 1
        return ret

    def swap(self, target):
        current = self.head
        if self.num_nodes == 0 or self.num_nodes == 1:
            return

        previous = None
        found = False
        while current is not None and not found:
            if current.data == target:
                found = True
            else:
                previous = current
                current = current.next

        if found:
            previous.next = current.next
            current.next.prev = previous
            holder = previous.prev
            previous.prev = current
            current.next = previous
            current.prev = holder
            holder.next = current
            return True
        else:
            return False


# ------------------------------------


def test_add():
    list1 = LinkedList2()
    list1.add(7)
    assert list1.head.data == 7, 'after add(7), head has data value ' + str(list1.head.data) + ' not 7'
    assert list1.size() == 1, 'size() fails after adding item to empty list'

    list1.add(3)
    assert list1.head.data == 3, 'after add(3), head has data value ' + str(list1.head.data) + ' not 3'
    assert list1.size() == 2, 'size() fails after adding 2nd item to empty list'


# ------------------------------------


def test_size():
    list1 = LinkedList2()
    assert list1.size() == 0, 'size() fails on an empty list'
    list1.add(7)
    assert list1.size() == 1, 'size() fails after adding item to empty list'

    list2 = LinkedList2()
    list2.load([3, 1, 4, 2])
    assert list2.size() == 4, 'size() fails after using load() to put 4 items into empty list'


def test_append():
    l = LinkedList2()
    l.append(5)
    assert l.get(0).getData() == 5, 'first item in the list is not 5'
    l.append(8)
    assert l.size() == 2, 'size doesnt work'
    l.append(3)
    assert l.last.getData() == 3, 'last item in the list should be 3'


def test_pop():
    l = LinkedList2()
    #l.pop()  # raises error
    l.append(5)
    assert l.pop() == 5, 'pop not working'
    l.load([4, 3, 2, 7])  # 7,2,3,4
    assert l.pop() == 4, 'pop not working'
    assert l.size() == 3, 'size not right'


def test_get():
    l = LinkedList2()
    # l.get(0)  # rasies error
    l.load([3, 5, 8, 4]) # 4,8,5,3
    assert l.get(0).getData() == 4, 'get not working'
    assert l.get(3).getData() == 3, 'get not working'
    assert l.get(1).getData() == 8, 'get not working'


def test_index():
    l = LinkedList2()
    l.load([3, 4, 5, 8, 4, 1]) # 1,4,8,5,4,3
    assert l.index(3) == 5, 'index of last item fails'
    assert l.index(1) == 0, 'index of first item fails'
    assert l.index(4) == 1, 'fails when two items of the same value in the list'
    # l.index(9) # raises Value Error


def test_insert():
    l = LinkedList2()
    l.insert(0, 1)
    assert l.get(0).getData() == 1, 'inserting to empty list fals'
    l.load([5, 6, 3]) # 3,6,5,1
    l.insert(0, 4)  # 4,3,6,5,1
    assert l.get(0).getData() == 4, 'inserting at beginning fails'
    l.insert(5, 9)  # 4,3,6,5,1,9
    assert l.get(5).getData() == 9, 'inserting by giving index = size of list fails'
    l.insert(20, 8) # 4,3,6,5,1,9,8
    assert l.get(6).getData() == 8, ' inserting at end giving it a large number fails'
    l.insert(2, 2) # 4,3,2,6,5,1,9,8
    assert l.get(2).getData() == 2, 'inserting in middle fails'
    assert l.size() == 8


def test_remove_at():
    l = LinkedList2()
    # l.remove_at(0) # throws error
    l.load([3, 1, 2, 5, 8])  # 8, 5, 2, 1, 3
    assert l.remove_at(4) == 3, 'removing last item fails' # 8, 5, 2, 1
    assert l.size() == 4, 'size fails'
    assert l.remove_at(0) == 8, 'removing first item fails' # 5, 2, 1
    assert l.remove_at(1) == 2, 'middle fails'
    assert l.remove_at(0) == 5, ' removing beginning fails'
    assert l.size() == 1, 'size fails'
    l = LinkedList2()
    l.load([5, 4, 3, 2, 1])  # 1 2 3 4 5
    assert l.remove_at(4) == 5, 'fails at 5'
    assert l.remove_at(1) == 2, 'fails at 2' # 1 3 4
    assert l.remove_at(1) == 3, 'fails at 3' # 1 4
    assert l.remove_at(1) == 4, 'fails at 4' # 1
    # l.remove_at(10) # raises exception


def test_swap():
    list1 = LinkedList2()
    list1.load([20, 18, 12, 16, 14, 10])
    #print(list1)
    assert list1.swap(18) == True
    #print(list1)




if __name__ == "__main__":

    test_add()
    test_size()
    test_append()
    test_get()
    test_index()
    test_insert()
    test_remove_at()
    test_pop()
    test_swap()