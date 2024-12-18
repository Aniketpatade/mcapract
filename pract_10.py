# Accept a string from the user
string1 = input("Enter the first string: ")
string2 = input("Enter the second string: ")

# 1. Calculate length of the string
length = len(string1)
print("Length of the string:", length)

# 2. Reverse the string
reversed_string = string1[::-1]
print("Reversed string:", reversed_string)

# 3. Check equality of two strings
if string1 == string2:
    print("The two strings are equal.")
else:
    print("The two strings are not equal.")

# 4. Check if the string is a palindrome
if string1 == reversed_string:
    print("The string is a palindrome.")
else:
    print("The string is not a palindrome.")

# 5. Check if one string is a substring of the other
if string2 in string1:
    print(f'"{string2}" is a substring of "{string1}".')
else:
    print(f'"{string2}" is not a substring of "{string1}".')