import random

def generate_student_data(num_students):
    first_names = ["Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Hank", "Ivy", "Jack"]
    last_names = ["Smith", "Johnson", "Williams", "Jones", "Brown", "Miller", "Davis", "Garcia", "Rodriguez", "Martinez"]

    student_data = []

    for _ in range(num_students):
        first_name = random.choice(first_names)
        last_name = random.choice(last_names)
        quiz_scores = [random.randint(0, 100) for _ in range(10)]

        # Calculate letter grade
        average_score = sum(quiz_scores) / len(quiz_scores)
        letter_grade = calculate_letter_grade(average_score)

        student_data.append((first_name, last_name, *quiz_scores, letter_grade))

    return student_data

def calculate_letter_grade(score):
    if 90 <= score <= 100:
        return 'A'
    elif 80 <= score < 90:
        return 'B'
    elif 70 <= score < 80:
        return 'C'
    elif 60 <= score < 70:
        return 'D'
    else:
        return 'F'

def print_student_data(student_data):
    for student in student_data:
        formatted_data = ' '.join(map(str, student))
        print(formatted_data)

# Generate student data
students = generate_student_data(10)

# Print formatted data
print_student_data(students)
