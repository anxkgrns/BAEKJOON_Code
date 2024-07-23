import sys


queue_name = []
queue_number = []

n = int(sys.stdin.readline())

for i in range(n):
    a, b = sys.stdin.readline().split()
    queue_name.append(a)
    queue_number.append(b)

for i in range(int((n-1)/2)):
    skip = int(queue_number.pop(0))
    queue_name.pop(0)
    for j in range(skip-1):
        queue_number.append(queue_number.pop(0))
        queue_name.append(queue_name.pop(0))
    queue_name.pop(0)
    queue_number.pop(0)

print(queue_name[0])

        

    

