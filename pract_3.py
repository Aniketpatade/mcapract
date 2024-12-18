# Accept marks for five courses
marks = []
for i in range(1, 6):
    marks.append(int(input(f"Enter marks for course {i}: ")))

# Check if student has failed in any course
if any(mark < 40 for mark in marks):
    print("Result: Fail")
else:
    # Calculate aggregate percentage
    total = sum(marks)
    aggregate = (total / 500) * 100

    # Determine grade
    if aggregate > 75:
        grade = "Distinction"
    elif 60 <= aggregate < 75:
        grade = "First Division"
    elif 50 <= aggregate < 60:
        grade = "Second Division"
    elif 40 <= aggregate < 50:
        grade = "Third Division"
    
    print(f"Result: Pass\nAggregate: {aggregate:.2f}%\nGrade: {grade}")