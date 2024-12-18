import math

# Function to check if the number is prime
def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

# Function to calculate prime factors
def prime_factors(n):
    factors = []
    for i in range(2, n + 1):
        while n % i == 0:
            factors.append(i)
            n = n // i
    return factors

# Main function
def main():
    num = int(input("Enter a number: "))

    # a) Square root
    print(f"Square Root of {num}: {math.sqrt(num)}")

    # b) Square
    print(f"Square of {num}: {num ** 2}")

    # c) Cube
    print(f"Cube of {num}: {num ** 3}")

    # d) Prime check
    if is_prime(num):
        print(f"{num} is a Prime Number.")
    else:
        print(f"{num} is not a Prime Number.")

    # e) Factorial
    fact = 1
    for i in range(1, num + 1):
        fact *= i
    print(f"Factorial of {num}: {fact}")

    # f) Prime factors
    print(f"Prime factors of {num}: {prime_factors(num)}")

# Call the main function
if __name__ == "__main__":
    main()