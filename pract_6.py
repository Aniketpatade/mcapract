import math

def smallest_divisor(n):
    for i in range(2, n + 1):
        if n % i == 0:
            return i

# Input two numbers
a = int(input("Enter the first number: "))
b = int(input("Enter the second number: "))

# Compute smallest divisors
smallest_div_a = smallest_divisor(a)
smallest_div_b = smallest_divisor(b)

# Compute GCD
gcd = math.gcd(a, b)

# Output results
print(f"The smallest divisor of {a} is {smallest_div_a}")
print(f"The smallest divisor of {b} is {smallest_div_b}")
print(f"The GCD of {a} and {b} is {gcd}")