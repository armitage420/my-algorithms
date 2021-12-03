import sys

def arrayManipulation(n, queries):
    arr = [0] * n

    for query in queries:
        
        startIndex = query[0]-1
        endPos = query[1]
        cost = query[2]
        
        arr[startIndex] += cost 
        
        if endPos < len(arr):
            arr[endPos] -= cost
        
    maxValue = arr[0]
    curr = 0
    
    # OPTION 1:
    # for i in range(len(arr)):
    #     curr += arr[i]
    #     maxValue = max(maxValue,curr)
    
    # OPTION 2:
    prev = 0
    for i in range(len(arr)):
        arr[i] += prev 
        prev = arr[i]
        maxValue = max(maxValue,arr[i])
    
    return maxValue

# For getting input from input.txt file
sys.stdin = open('codingInterviewsPractice/dynamicProgramming/input.txt', 'r')
# Printing the Output to output.txt file
sys.stdout = open('codingInterviewsPractice/dynamicProgramming/output.txt', 'w')

first_multiple_input = input().rstrip().split()

n = int(first_multiple_input[0])

m = int(first_multiple_input[1])

queries = []

for _ in range(m):
    queries.append(list(map(int, input().rstrip().split())))

result = arrayManipulation(n, queries)

sys.stdout.write(str(result) + '\n')