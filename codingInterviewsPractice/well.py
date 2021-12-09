import sys
import math

sys.stdin = open('/run/media/nzec/C/my-algorithms/input.txt', 'r')
sys.stdout = open('/run/media/nzec/C/my-algorithms/output.txt', 'w')

n,p,k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]


toys = 0
leftPoints = []
rightPoints = []
leftPointsSize = 0
rightPointsSize = 0

for i in range(n):
    if a[i] < p:
        leftPoints.append([a[i], b[i]])
        leftPointsSize += 1
    else:
        rightPoints.append([a[i], b[i]])
        rightPointsSize += 1

leftPoints.sort()
rightPoints.sort()

leftPathMax = []
rightPathMax = []

if leftPointsSize > 0:
    distance = p - leftPoints[0][0]
    iToys = leftPoints[0][1] 
    leftPathMax.append([distance, iToys])
    if abs(leftPathMax[0][0] <= k):
        toys = max(toys, leftPathMax[0][1])
        # leftPointsSize = 1

    for i in range(1, leftPointsSize):
        distance = p - leftPoints[i][0]
        iToys = leftPoints[i][1] + leftPathMax[i-1][1]
        leftPathMax.append([distance, iToys])
        if abs(leftPathMax[i][0] <= k):
            toys = max(toys, leftPathMax[i][1])
        #     leftPointsSize += 1
        # else:
        #     break
        


if rightPointsSize > 0:
    distance = rightPoints[0][0] - p
    iToys = rightPoints[0][1] 
    rightPathMax.append([distance, iToys])
    if abs(rightPathMax[0][0] <= k):
        toys = max(toys, rightPathMax[0][1])
        # rightPointsSize = 1

    for i in range(1, rightPointsSize):
        distance = rightPoints[i][0] - p
        iToys = rightPoints[i][1] + rightPathMax[i-1][1]
        rightPathMax.append([distance, iToys])
        if abs(rightPathMax[i][0] <= k):
            toys = max(toys, rightPathMax[i][1])
        #     rightPointsSize += 1
        # else:
        #     break
        
for i in range(leftPointsSize):
    distance = leftPathMax[i][0]
    iToys = leftPathMax[i][1]

    res = -99
    if(distance <= k):
        low = 0
        high = rightPointsSize - 1
        while low <= high:
            mid = int(math.ceil(low + (high - low)/2))
            if rightPathMax[mid][0] + distance <= k:
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
        if ans != -99:
            toys = max(toys, iToys + rightPathMax[ans][1])

print(toys)
