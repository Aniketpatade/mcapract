import os

# Specify the directory path
directory = input("Enter the directory path: ")

# Get a list of files in the directory
files = os.listdir(directory)

# Sort files by creation date
sorted_files = sorted(
    files, key=lambda x: os.path.getctime(os.path.join(directory, x))
)

# Display sorted files with creation dates
print("Directory listing sorted by creation date:")
for file in sorted_files:
    creation_time = os.path.getctime(os.path.join(directory, file))
    print(f"{file} - Created at: {creation_time}")