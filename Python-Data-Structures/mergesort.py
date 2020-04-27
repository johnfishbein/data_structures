def mergesort(aList, first, last):
    print('mergesort(', first, ',', last, ')')
    if first < last:
        mid = (first+last) // 2
        mergesort(aList, first, mid)
        mergesort(aList, mid + 1, last)
        print( '  merging...')
        merge(aList, first, mid, last)
        print('List: ', aList)
    return

def merge(aList, first, mid, last):
    merged = []
    idx1 = first
    idx2 = mid + 1
    while True:
        if aList[idx1] < aList[idx2]:
            merged.append(aList[idx1])
            idx1 = idx1 + 1
        else:
            merged.append(aList[idx2])
            idx2 = idx2 + 1
        if idx1 > mid or idx2 > last:
            break
    while idx1 <= mid:
        merged.append(aList[idx1])  # clean-up loops
        idx1 = idx1 + 1
    while idx2 <= last:
        merged.append(aList[idx2])
        idx2 = idx2 + 1
    aList[first:last + 1] = merged


def run_mergesort():
    # list1 = eval(input('Enter the list: '))
    list1 = [ 8, 3, 2, 9, 7, 1, 5, 4]
    print(list1)
    mergesort(list1, 0, len(list1)-1)
    print(list1)
    return
    # testing for merge (ran this first)
    # list1 = [ 1, 5, 6, 2, 3, 9 ]
    # merge(list1, 0, 2, 5)
    # print(list1)

run_mergesort()