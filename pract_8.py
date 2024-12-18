# Python program to generate a list and a tuple from comma-separated numbers

# Accept input from the user
numbers = input("Enter comma-separated numbers: ")

# Generate a list by splitting the input string
numbers_list = numbers.split(",")

# Convert the list into a tuple
numbers_tuple = tuple(numbers_list)

# Print the list and tuple
print("List:", numbers_list)
print("Tuple:", numbers_tuple)