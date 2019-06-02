#  3. Максимальное K-произведение
#  Дана последовательность N целых чисел (1 ≤ N ≤ 105, |Ai| ≤ 2 ⋅ 109) и число K (1 ≤ K ≤ N). Найти K чисел последовательности, произведение которых максимально.

def lab3(N, K, nums):
    nums.sort(reverse=True, key=lambda x: abs(x))
    #print(nums)
    ar = nums[:K]
    if K == N:
           return nums
    size = len(list(filter(lambda x: x<0, ar)))
    if size%2 == 0:
        return ar
    if all([x <= 0 for x in nums]):
        return nums[N-K:N]
    
    minp, minm = -1, -1
    maxp, maxm = -1, -1
    for i in range(K-1, -1, -1):
        if ar[i] < 0:
             minm = i
             break
    for i in range(K-1, -1, -1):
        if ar[i] > 0:
             minp = i
             break
    ar2 = nums[K::]
    for i in range(N-K):
        if ar2[i] < 0:
             maxm = i
             break
    for i in range(N-K):
        if ar2[i] > 0:
             maxp = i
             break
    #print(ar, ar2)
    #print(minm, minp, '=', ar[minm], ar[minp])
    #print(maxm, maxp, '=', ar2[maxm], ar2[maxp])
    if maxm == -1:
        ar[minm] = ar2[maxp]
        return ar
    if maxp == -1:
        ar[minp] = ar2[maxm]
        return ar
    if minp == -1:
        ar[minm] = ar2[maxp]
        return ar
    tempA = ar[minp] * ar2[maxp]
    tempB = ar[minm] * ar2[maxm]
    if tempA > tempB:
        ar[minm] = ar2[maxp]
    else:
        ar[minp] = ar2[maxm]
    return ar


N, K = list(map(int, input().rstrip().split(' ')))
nums = list(map(int, input().rstrip().split(' ' )))

ar = lab3(N, K, nums)
prod = 1
modul = 7 + 10**9
for x in ar:
    prod *= x
    prod %= modul
#print(ar)
print(prod)