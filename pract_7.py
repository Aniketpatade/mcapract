# Accept the size of the list
N = int(input("Enter the number of integers: "))

# Accept the list of integers
numbers = []
print("Enter the integers:")
for i in range(N):
    num = int(input())
    numbers.append(num)

# Initialize empty lists for even and odd numbers
even_list = []
odd_list = []

# Partition the numbers into even and odd lists
for num in numbers:
    if num % 2 == 0:
        even_list.append(num)
    else:
        odd_list.append(num)

# Display the results
print("Even Numbers:", even_list)
print("Odd Numbers:", odd_list)