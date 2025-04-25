import math

arr = [22, 1, 23, 12, 68]

def isEven(num):
    if (num % 2 == 0):
        return True
    else:
        return False

def countEvens(arr):
    evenCount = 0

    for num in arr:
        if isEven(num):
            evenCount += 1

    return evenCount

evenCount = countEvens(arr)
oddCount = len(arr) - evenCount

evenSums1 = math.comb(evenCount, 2)
evenSums2 = math.comb(oddCount, 2)

print(evenSums1 + evenSums2)
