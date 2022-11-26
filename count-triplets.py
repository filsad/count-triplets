#!/usr/bin/python3

def countTriplets(arr, r):
    count1 = dict()
    count2 = dict()
    count3 = dict()
    for elem in arr:
        count1[elem] = count1.setdefault(elem, 0) + 1
        if elem % r == 0:
            prev = elem // r
            count2[elem] = count2.setdefault(elem, 0) + count1.setdefault(prev, 0)
            count3[elem] = count3.setdefault(elem, 0) + count2.setdefault(prev, 0)
    return sum(count3.values())

if __name__ == '__main__':
    nr = input().rstrip().split()
    n = int(nr[0])
    r = int(nr[1])
    arr = list(map(int, input().rstrip().split()))
    ans = countTriplets(arr, r)
    print(ans)
