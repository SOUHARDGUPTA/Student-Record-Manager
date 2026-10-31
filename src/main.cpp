#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Student {
public:
    int rollNumber;
    string name;
    string course;
    float marks;

    void inputDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Course: ";
        getline(cin, course);

        do {
            cout << "Enter Marks (0-100): ";
            cin >> marks;

            if (marks < 0 || marks > 100) {
                cout << "Invalid marks! Please enter between 0 and 100." << endl;
            }
        } while (marks < 0 || marks > 100);
    }

    void displayDetails() {
        cout << "\nRoll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "----------------------------" << endl;
    }
};

void saveToFile(vector<Student>& students) {
    ofstream file("data/students.txt");

    for (int i = 0; i < students.size(); i++) {
        file << students[i].rollNumber << endl;
        file << students[i].name << endl;
        file << students[i].course << endl;
        file << students[i].marks << endl;
    }

    file.close();
}

void loadFromFile(vector<Student>& students) {
    ifstream file("data/students.txt");
    Student s;

    while (file >> s.rollNumber) {
        file.ignore();
        getline(file, s.name);
        getline(file, s.course);
        file >> s.marks;
        file.ignore();

        students.push_back(s);
    }

    file.close();
}

int main() {
    vector<Student> students;
    int choice;

    loadFromFile(students);

    do {
        cout << "\n================================" << endl;
        cout << " STUDENT RECORD MANAGEMENT SYSTEM" << endl;
        cout << "================================" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            s.inputDetails();

            bool exists = false;

            for (int i = 0; i < students.size(); i++) {
                if (students[i].rollNumber == s.rollNumber) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                cout << "\nRoll number already exists!" << endl;
            } else {
                students.push_back(s);
                saveToFile(students);
                cout << "\nStudent added successfully!" << endl;
            }
        }

        else if (choice == 2) {
            if (students.empty()) {
                cout << "\nNo student records found!" << endl;
            } else {
                for (int i = 0; i < students.size(); i++) {
                    students[i].displayDetails();
                }
            }
        }

        else if (choice == 3) {
            int roll;
            bool found = false;

            cout << "Enter Roll Number to search: ";
            cin >> roll;

            for (int i = 0; i < students.size(); i++) {
                if (students[i].rollNumber == roll) {
                    students[i].displayDetails();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nStudent not found!" << endl;
            }
        }

        else if (choice == 4) {
            int roll;
            bool found = false;

            cout << "Enter Roll Number to update: ";
            cin >> roll;

            for (int i = 0; i < students.size(); i++) {
                if (students[i].rollNumber == roll) {
                    cout << "\nEnter new details:" << endl;

                    students[i].inputDetails();

                    bool duplicate = false;

                    for (int j = 0; j < students.size(); j++) {
                        if (j != i &&
                            students[j].rollNumber == students[i].rollNumber) {
                            duplicate = true;
                            break;
                        }
                    }

                    if (duplicate) {
                        cout << "\nRoll number already exists! Update cancelled." << endl;
                    } else {
                        saveToFile(students);
                        cout << "\nStudent updated successfully!" << endl;
                    }

                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nStudent not found!" << endl;
            }
        }

        else if (choice == 5) {
            int roll;
            bool found = false;

            cout << "Enter Roll Number to delete: ";
            cin >> roll;

            for (int i = 0; i < students.size(); i++) {
                if (students[i].rollNumber == roll) {
                    students.erase(students.begin() + i);
                    saveToFile(students);
                    cout << "\nStudent deleted successfully!" << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nStudent not found!" << endl;
            }
        }

        else if (choice == 6) {
            saveToFile(students);
            cout << "\nRecords saved successfully!" << endl;
            cout << "Goodbye!" << endl;
        }

        else {
            cout << "\nInvalid choice! Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
