# selection sort O(n^2)

import random


def find_max_idx(the_list, start, end):
    max = the_list[0]
    idx = 0
    for i in range(start, end + 1):
        if the_list[i] > max:
            max = the_list[i]
            idx = i
    return idx


def swap(the_list, i, j):
    # (a, b) = (b, a) alternative way to do it
    k = the_list[i]
    the_list[i] = the_list[j]
    the_list[j] = k


# non-decreasing order -> biggest item at the end
def selection_sort(the_list):
    end = len(the_list) - 1
    for i in range(len(the_list)):
        swap(the_list, find_max_idx(the_list, 1, end-i), end-i)
    return the_list  ##return statement un needed because list is modified in the fiunction


if __name__ == "__main__":
    lst = [1,3,2,7,4,43,8,5,9,4,5,7,8,3,2,1,11]
    print("before: ", lst)
    selection_sort(lst)
    print("after: ", lst)

    #    n = 5
    #    test_data = [ random.randint(-100,100) for i in range(0,n)]
    test_data = [3, 1, 7, 12, 6, 15]
    print("Initial list:", test_data)

    idx = find_max_idx(test_data, 0, 4)
    print("max posn:", idx, "max value:", test_data[idx])

    i = 1
    j = 3
    swap(test_data, i, j)
    print("After swap:", test_data[0:j + 1])

    selection_sort(test_data)
    print(test_data)


# After writing selection_sort(), move the two functions defintions at the end
#   to above the if-statement, and then uncomment these next lines.

#    test_mysort()
#
#    sort_random(10, True)


def test_mysort():
    list1 = [3, 2, 1]
    selection_sort(list1)
    assert list1 == [1, 2, 3], "Case 1 failed: 3 items in reverse order"

    list2 = [3, 4, 2, 7]
    selection_sort(list2)
    assert list2 == [2, 3, 4, 7], "Case 2 failed: 4 items jumbled order"

    list2 = [3]
    selection_sort(list2)
    assert list2 == [3], "Case 3 failed: 1 item"

    list2 = []
    selection_sort(list2)
    assert list2 == [], "Case 4 failed: empty list"

    list2 = [3, 2, 4, 3, 2, 7]
    selection_sort(list2)
    assert list2 == [2, 2, 3, 3, 4, 7], "Case 5 failed: 6 items, jumbled with duplicates"

    str_list = ["i", "like", "green", "eggs", "and", "ham"]
    selection_sort(str_list)
    assert str_list == ["and", "eggs", "green", "ham", "i", "like"], "Case 5 failed: works with strings"


def sort_random(n, echo=False):
    data = [random.randint(-999, 999) for i in range(n)]
    if echo:
        print("before: ", data)
    selection_sort(data)
    if echo:
        print("after:  ", data)