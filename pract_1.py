# Write a Python Program to Calculate the sum of Three Given Numbers,
# if the Values are Equal Then Return Three Times of Their Sum.

def add_values(x, y, z):
    if x == y == z:
        return (x + y + z) * 3
    return x + y + z

a = int(input("Enter First Number : "))
b = int(input("Enter Second Number : "))
c = int(input("Enter Third Number : "))

print("Sum is : %d" % add_values(a, b, c))