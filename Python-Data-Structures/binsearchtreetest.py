from binary_search_tree import BinaryTree, BTNode


def create_subtree_STAFF(root, left_list, right_list, parent):
    temp = BTNode(root)
    temp.parent = parent
    if len(left_list) == 0:
        temp.left = None
    else:
        temp.left = create_subtree_STAFF(left_list[0], left_list[1], left_list[2], temp)
    if len(right_list) == 0:
        temp.right = None
    else:
        temp.right = create_subtree_STAFF(right_list[0], right_list[1], right_list[2], temp)
    return temp

# reads from nested list representation of trees (see Section 6.4 in book)
def list_to_tree_STAFF(tlist):
    tree = BinaryTree()
    tree.root = create_subtree_STAFF(tlist[0], tlist[1], tlist[2], None)
    return tree


tests = [
    "Test 1: given empty tree, don't cause exception",
    "Test 2: given tree with one node, return True",
    "Test 3: given 1st tree in PDF doc, return True",
    "Test 4: given 2nd tree in PDF doc, return False",
    "Test 5: given 3rd tree in PDF doc, return False",
    "Test 6: given 4th tree in PDF doc, return False",
    "Test 7: given 5th tree in PDF doc, return False",
    "Test 8: given totally tree with only left-children, strings from big (root) to small (leaf), return True",

]

passed = 0

#############
# "Test 1: given empty tree, don't cause exception",

test_num = 1
try:
    empty = BinaryTree()
    result = empty.validate_bst()
    if result is True:
        print("PASSED:", tests[test_num-1])
        passed += 1
    else:
        print("PASSED:", tests[test_num-1])
        passed += 1

except Exception as exception_instance:
    print("FAILED:", tests[test_num-1])
    print("Program has crashed because of the following exception:\n" +
            str(exception_instance))

#############
#     "Test 2: given tree with one node, return True",

test_num = 2
try:
    tree1 = BinaryTree()
    tree1.root = BTNode(27)
    result = tree1.validate_bst()
    if result:
        print("PASSED:", tests[test_num-1])
        passed += 1
    else:
        print("FAILED:", tests[test_num-1])
        print("  observed value: ", result)

except Exception as exception_instance:
    print("FAILED:", tests[test_num-1])
    print("Program has crashed because of the following exception:\n" +
          str(exception_instance))

#############
#  "Test 3: given 1st tree in PDF doc, return True",

test_num = 3
try:
    tree1 = list_to_tree_STAFF([10, [5, [3, [], []], [8, [], []]], [15, [12, [], []], []]])
    result = tree1.validate_bst()
    if result:
        print("PASSED:", tests[test_num-1])
        passed += 1
    else:
        print("FAILED:", tests[test_num-1])
        print("  observed value: ", result)

except Exception as exception_instance:
    print("FAILED:", tests[test_num-1])
    print("Program has crashed because of the following exception:\n" +
          str(exception_instance))

#############
#  "Test 4: given 2nd tree in PDF doc, return False",

test_num = 4
try:
    tree1 = list_to_tree_STAFF([10, [25, [3, [], []], [8, [], []]], [15, [12, [], []], []]])
    result = tree1.validate_bst()
    if not result:
        print("PASSED:", tests[test_num-1])
        passed += 1
    else:
        print("FAILED:", tests[test_num-1])
        print("  observed value: ", result)

except Exception as exception_instance:
    print("FAILED:", tests[test_num-1])
    print("Program has crashed because of the following exception:\n" +
          str(exception_instance))

#############
# "Test 5: given 3rd tree in PDF doc, return False",

test_num = 5
try:
    tree1 = list_to_tree_STAFF([10, [5, [3, [], []], [8, [], []]], [15, [22, [], []], []]])
    result = tree1.validate_bst()
    if not result:
        print("PASSED:", tests[test_num-1])
        passed += 1
    else:
        print("FAILED:", tests[test_num-1])
        print("  observed value: ", result)

except Exception as exception_instance:
    print("FAILED:", tests[test_num-1])
    print("Program has crashed because of the following exception:\n" +
          str(exception_instance))

#############
# "Test 6: given 4th tree in PDF doc, return False",

test_num = 6
try:
    tree1 = list_to_tree_STAFF([10, [5, [3, [], []], [11, [], []]], [15, [12, [], []], []]])
    result = tree1.validate_bst()
    if not result:
        print("PASSED:", tests[test_num-1])
        passed += 1
    else:
        print("FAILED:", tests[test_num-1])
        print("  observed value: ", result)

except Exception as exception_instance:
    print("FAILED:", tests[test_num-1])
    print("Program has crashed because of the following exception:\n" +
          str(exception_instance))

#############
# "Test 7: given 5th tree in PDF doc, return False",

test_num = 7
try:
    tree1 = list_to_tree_STAFF([10, [5, [3, [], []], [8, [], []]], [15, [9, [], []], []]])
    result = tree1.validate_bst()
    if not result:
        print("PASSED:", tests[test_num - 1])
        passed += 1
    else:
        print("FAILED:", tests[test_num - 1])
        print("  observed value: ", result)

except Exception as exception_instance:
    print("FAILED:", tests[test_num - 1])
    print("Program has crashed because of the following exception:\n" +
          str(exception_instance))


#############
# "Test 8: given totally tree with only left-children, strings from big (root) to small (leaf), return True",

test_num = 8
try:
    tree1 = list_to_tree_STAFF(
        ['G', ['F', ['E', ['D', ['C', [], []], []], []], []], []])
    result = tree1.validate_bst()
    if result:
        print("PASSED:", tests[test_num - 1])
        passed += 1
    else:
        print("FAILED:", tests[test_num - 1])
        print("  observed value: ", result)

except Exception as exception_instance:
    print("FAILED:", tests[test_num - 1])
    print("Program has crashed because of the following exception:\n" +
          str(exception_instance))

print("TOTAL: passed ", passed, "out of 8 tests.")