class EMPLOYEE:
    # Class variable to count total employees
    total_employees = 0

    def __init__(self, name, designation, gender, date_of_joining, salary):
        self.name = name
        self.designation = designation
        self.gender = gender
        self.date_of_joining = date_of_joining
        self.salary = salary
        EMPLOYEE.total_employees += 1  # Increment total employees

    # Static method to return total employees
    @staticmethod
    def get_total_employees():
        return EMPLOYEE.total_employees

    # Function to count male and female employees
    @staticmethod
    def count_by_gender(employee_list):
        male_count = sum(1 for emp in employee_list if emp.gender == "Male")
        female_count = sum(1 for emp in employee_list if emp.gender == "Female")
        return male_count, female_count

    # Function to get employees with salary > 10,000
    @staticmethod
    def get_high_salary_employees(employee_list):
        return [emp.name for emp in employee_list if emp.salary > 10000]

    # Function to get employees with designation "Asst Manager"
    @staticmethod
    def get_asst_manager(employee_list):
        return [emp.name for emp in employee_list if emp.designation == "Asst Manager"]


# Example usage
employees = [
    EMPLOYEE("John", "Manager", "Male", "2015-01-10", 12000),
    EMPLOYEE("Jane", "Asst Manager", "Female", "2018-03-15", 15000),
    EMPLOYEE("Doe", "Asst Manager", "Male", "2020-07-20", 9500),
    EMPLOYEE("Alice", "Executive", "Female", "2019-06-30", 10500),
]

# Display outputs
print("Total Employees:", EMPLOYEE.get_total_employees())
male_count, female_count = EMPLOYEE.count_by_gender(employees)
print("Male Employees:", male_count)
print("Female Employees:", female_count)
print("Employees with salary > 10,000:", EMPLOYEE.get_high_salary_employees(employees))
print("Employees with designation 'Asst Manager':", EMPLOYEE.get_asst_manager(employees))