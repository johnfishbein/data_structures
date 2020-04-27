# Modification of binary tree to code to for lecture on binary search trees.
#   Includes the size() and count_nodes() methods, as well as code for remove()


class BTNode:
    def __init__(self, data):
        self.data = data
        self.parent = None
        self.left = None
        self.right = None

    def __str__(self):
        return "<" + str(self.data) + ">"

    def is_leaf(self):
        return self.left is None and self.right is None

    def is_root(self):
        return self.parent is None


class BinaryTree:
    def __init__(self, root_node=None):
        self.root = root_node

    def size(self):
        if self.root is None:
            return 0
        return self.count_nodes(self.root)

    def count_nodes(self, node):
        if node is None:
            return 0
        return 1 + self.count_nodes(node.left) + self.count_nodes(node.right)

    def search(self, target):
        if self.root is None:
            return False
        return self.search_at_node(self.root, target)

    def __contains__(self, item):
        return self.search(item)

    def search_at_node(self, node, target):
        if node is None:
            return False
        # print('* searching for', target, 'looking at', node.data)
        if node.data == target:
            return True
        if target < node.data and not node.left is None:  # must be in left subtree
            return self.search_at_node(node.left, target)
        elif not node.right is None:  # must be in right subtree
            return self.search_at_node(node.right, target)

    def find_at_node(self, node, target):  # like search_at_node but returns node (not boolean)
        if node is None:
            return None
        if node.data == target:
            return node  # here's where different than search_at_node
        if target < node.data and not node.left is None:  # must be in left subtree
            return self.find_at_node(node.left, target)
        elif not node.right is None:  # must be in right subtree
            return self.find_at_node(node.right, target)

    def find_min(self, node):
        assert node is not None, "can't call find_min(node) when node is None"
        min_node = node
        current = node.left
        while current is not None:  # go left, young man! :-)
            min_node = current
            current = current.left
        return min_node

    def remove(self, data_value):
        if self.root is None:
            return False
        curr = self.find_at_node(self.root, data_value)
        if curr is None:
            return False

        # Case 1:  node is a leaf
        if curr.is_leaf():
            if curr.parent is None:
                self.root = None
            elif curr == curr.parent.left:
                curr.parent.left = None
            else:
                curr.parent.right = None

        # Case 3:  node has two children
        elif not curr.left is None and not curr.right is None:
            next_largest_node = self.find_min(curr.right)
            val = next_largest_node.data
            self.remove(val)
            curr.data = val

        # Case 2a:  node has right child
        elif not curr.right is None:
            # Hmm, does this work if curr is the root? What do you think?
            if curr == curr.parent.left:
                curr.parent.left = curr.right
            else:
                curr.parent.right = curr.right
            curr.right.parent = curr.parent

        # Case 2b:  node has left child
        else:
            # Hmm, does this work if curr is the root? What do you think?
            if curr == curr.parent.left:
                curr.parent.left = curr.left
            else:
                curr.parent.right = curr.left
            curr.left.parent = curr.parent

        return True

    def __str__(self):
        return "How should we print a tree? Hmmm..."

    def height(self):
        if self.root is None:
            return None
        else:
            return self.max_dist_to_leaf(self.root)

    def max_dist_to_leaf(self, node):
        if node.is_leaf():
            return 0

        if node.left is not None:
            left = 1 + self.max_dist_to_leaf(node.left)
        else:
            left = 0

        if node.right is not None:
            right = 1 + self.max_dist_to_leaf(node.right)
        else:
            right = 0

        return max([left, right])

    def insert(self, data):
        if self.root is None:
            self.root = BTNode(data)
            return True
        else:
            return self.insert_at_node(self.root, data)

    def insert_at_node(self, node, data):
        if node.data == data:
            return False
        elif node.data > data:  # data value is less than current node
            if node.left is None:
                new = BTNode(data)
                new.parent = node
                node.left = new
                return True
            else:
                return self.insert_at_node(node.left, data)
        else:  # data value is greater than current node
            if node.right is None:
                new = BTNode(data)
                new.parent = node
                node.right = new
                return True
            else:
                return self.insert_at_node(node.right, data)

    def validate_bst(self):
        if self.root is None:
            return True
        else:
            return self.validate_on_node(self.root)

    def min_in_subtree(self, node):
        minimum_left = node.data
        minimum_right = node.data

        if node.is_leaf():
            return node.data
        if node.left is not None:
            minimum_left = min([node.data, self.min_in_subtree(node.left)])
        if node.right is not None:
            minimum_right = min([node.data, self.min_in_subtree(node.right)])
        return min([minimum_left, minimum_right])

    def max_in_subtree(self, node):
        maximum_left = node.data
        maximum_right = node.data
        if node.is_leaf():
            return node.data
        if node.left is not None:
            maximum_left = max([node.data, self.max_in_subtree(node.left)])
        if node.right is not None:
            maximum_right = max([node.data, self.max_in_subtree(node.right)])
        return max([maximum_left, maximum_right])

    def validate_on_node(self, node):
        if node.is_leaf():
            return True

        if node.left is not None:
            if node.data < self.max_in_subtree(node.left):
                return False
            else:
                left = self.validate_on_node(node.left)
        else:
            left = True

        if node.right is not None:
            if node.data > self.min_in_subtree(node.right):
                return False
            else:
                right = self.validate_on_node(node.right)
        else:
            right = True

        return right and left


def create_subtree(root, left_list, right_list, parent):
    temp = BTNode(root)
    temp.parent = parent
    if len(left_list) == 0:
        temp.left = None
    else:
        temp.left = create_subtree(left_list[0], left_list[1], left_list[2], temp)
    if len(right_list) == 0:
        temp.right = None
    else:
        temp.right = create_subtree(right_list[0], right_list[1], right_list[2], temp)
    return temp


# reads from nested list representation of trees (see Section 6.4 in book)
def list_to_tree(tlist):
    tree = BinaryTree()
    tree.root = create_subtree(tlist[0], tlist[1], tlist[2], None)
    return tree


def print_node_info(subtree, level):
    if subtree is None:
        return
    print('Node:', subtree.data, 'Level:', level, 'Parent:', subtree.parent)
    print_node_info(subtree.left, level + 1)
    print_node_info(subtree.right, level + 1)


def test_insert():
    bst1 = list_to_tree([30,
                         [20,
                          [10, [], []], [25,
                                         [23, [], []], [27, [], []]]],
                         [40, [], []]])

    assert bst1.insert(26)
    assert bst1.insert(39)
    assert bst1.insert(41)
    # print('bst1: ')
    # print_node_info(bst1.root, 0)
    # print('\n')
    assert bst1.validate_bst()

    bst2 = BinaryTree()
    assert bst2.insert(30)
    assert bst2.insert(40)
    assert not bst2.insert(40)
    assert bst2.insert(25)
    assert bst2.insert(27)
    assert bst2.insert(26)
    assert bst2.insert(47)
    # print('bst2: ')
    # print_node_info(bst2.root, 0)
    # print('\n')
    assert bst2.validate_bst()


def test_height():
    t1 = BinaryTree()
    assert t1.height() is None

    t2 = list_to_tree([30, [], []])
    assert t2.height() == 0

    t3 = list_to_tree([30, [5, [], []], []])
    assert t3.height() == 1

    t4 = list_to_tree([30, [], [31, [], []]])
    assert t4.height() == 1

    t5 = list_to_tree([30,
                       [20,
                        [10, [], []], [25,
                                       [23, [], []], [27, [], []]]],
                       [40, [], []]])

    assert t5.height() == 3

    t6 = list_to_tree([30,
                       [20,
                        [10, [], []], [25,
                                       [23, [], []], [27, [], []]]],
                       [40, [], [41, [], [42, [], [43, [], []]]]]])

    assert t6.height() == 4


def test_validate_bst():
    invalid_bst = list_to_tree([40,
                                [45, [], []], [46, [], []]])
    assert not invalid_bst.validate_bst()
    # print('invalidBST: ')
    # print_node_info(invalid_bst.root, 0)
    # print('\n')

    empty_bst = BinaryTree()
    assert empty_bst.validate_bst()

    single_bst = list_to_tree([30, [], []])
    assert single_bst.validate_bst()

    one_child = list_to_tree([30, [22, [], []], []])
    assert one_child.validate_bst()

    one_child_invalid1 = list_to_tree([30, [35, [], []], []])
    assert not one_child_invalid1.validate_bst()

    one_child_invalid2 = list_to_tree([30, [], [29, [], []]])
    assert not one_child_invalid2.validate_bst()

    my_tree = list_to_tree([10, [5, [3, [], []], [8, [], []]], [15, [1, [], []], []]])

    assert not my_tree.validate_bst()
    assert 10 in my_tree


test_insert()
test_validate_bst()

'''
test_insert()
first test tree: bst1
0            30
1        20      40
2    10      25
3          23  27 

insert(26)
0            30
1        20      40
2    10      25
3          23  27 
4             26

insert(39)
0               30
1        20         40
2    10      25    39
3          23  27 
4             26

insert(41)
0               30
1        20           40
2    10      25     39  41
3          23  27 
4             26

This tree was then printed and validated

second test tree: bst2 ->built from an empty tree
insert(30)
insert(40)
insert(40) -- should fail
insert(25) 
insert(27)
insert(26)
insert(47)

0               30
1        25           40
2            27          47
3          26       
This tree was then printed and validated





test_validate()
6 test trees were created and tested
3 trees were invalid

0       40
1   45      46

and

0       30
1   35      

and

0       30
1           29

all successfully returned false when the validate_bst() function was called on them

3 trees were valid

an empty tree

and

a tree with only a root

and

0       30
1   22

all successfully returned true when the validate_bst() function was called on them
'''