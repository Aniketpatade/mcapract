# Program to compute max, min, sum, and average of N numbers

# Input the number of elements
n = int(input("Enter the number of elements: "))
# Initialize an empty list
numbers = []
# Accept N numbers from the user
for i in range(n):
    num = float(input(f"Enter number {i+1}: "))
    numbers.append(num)
# Compute results
maximum = max(numbers)
minimum = min(numbers)
total_sum = sum(numbers)
average = total_sum / n
# Display results
print(f"Maximum: {maximum}")
print(f"Minimum: {minimum}")
print(f"Sum: {total_sum}")
print(f"Average: {average}")