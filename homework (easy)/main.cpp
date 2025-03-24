#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double get_average_score(const int[], size_t size);
int get_student_above_average(const int[], size_t size);

int main() {

  int number_of_students{0};

  cout << "Enter the number of students: ";
  cin >> number_of_students;

  if (number_of_students <= 0) {
    cout << "Number of students must be positive!" << endl;
    return 1;
  }

  int *student_grades_ptr = new int[number_of_students];

  int i = 0;
  while (i < number_of_students) {
    cout << "Enter student " << i + 1 << "'s grade: ";
    cin >> student_grades_ptr[i];
    i++;
  }

  cout << endl;

  const double average_score = get_average_score(student_grades_ptr, number_of_students);

  cout << "Average grade: " << average_score << '\n';

  const int above_average = get_student_above_average(student_grades_ptr, number_of_students);

  cout << "Student above average: " << above_average << '\n';
  cout << "Student below average: " << number_of_students - above_average << '\n';

  delete[] student_grades_ptr;

  return 0;
}

double get_average_score(const int scores[], size_t size) {
  double total = 0.0;

  for (size_t i = 0; i < size; i++) {
    total += scores[i];
  }
  double average = total / size;

  return average;
}

int get_student_above_average(const int scores[], size_t size) {
  int above_average_counter = 0;

  const double average = get_average_score(scores, size);

  for (size_t i = 0; i < size; i++) {
    if (scores[i] > average) {
      above_average_counter++;
    }
  }

  return above_average_counter;
}