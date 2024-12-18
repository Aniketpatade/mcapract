# Python program to check Armstrong number

# Function to check Armstrong number
def is_armstrong(num):
    # Split the number into its digits
    a = num // 100        # Extract the hundreds digit
    b = (num // 10) % 10  # Extract the tens digit
    c = num % 10          # Extract the ones digit
    
    # Calculate the sum of the cubes of the digits
    sum_of_cubes = a**3 + b**3 + c**3
    
    # Check if the sum of cubes equals the original number
    if sum_of_cubes == num:
        return True
    else:
        return False

# Input a three-digit number
num = int(input("Enter a three-digit number: "))

# Check if the number is Armstrong
if is_armstrong(num):
    print(f"{num} is an Armstrong number.")
else:
    print(f"{num} is not an Armstrong number.")