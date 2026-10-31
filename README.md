# Student Record Manager

A console-based Student Record Management System developed using C++. This project allows users to efficiently manage student records through a menu-driven interface with file handling for permanent data storage.

## Features

- **Add Student:** Add new student records with roll number, name, course, and marks.
- **Display Students:** View all stored student records.
- **Search Student:** Find a student using their roll number.
- **Update Student:** Modify existing student details.
- **Delete Student:** Remove student records.
- **File Handling:** Automatically save and load records using text files.
- **Input Validation:** Validate marks within the range of 0–100.
- **Duplicate Prevention:** Prevent duplicate roll numbers.
- **Menu-Driven Interface:** Easy-to-use command-line navigation.

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL (`vector`)
- File Handling (`fstream`)
- Visual Studio Code
- GCC Compiler (MinGW)

## Project Structure

```text
Student-Record-Manager/
│
├── src/
│   └── main.cpp
│
├── data/
│   └── students.txt
│
├── .gitignore
├── README.md
└── student.exe
```

## How to Run

### Prerequisites
- GCC compiler installed (MinGW)
- Visual Studio Code (recommended)

### Steps

1. Clone the repository:

   ```bash
   git clone https://github.com/SOUHARDGUPTA/Student-Record-Manager.git
   ```

2. Navigate to the project directory:

   ```bash
   cd Student-Record-Manager
   ```

3. Compile the program:

   ```bash
   g++ src/main.cpp -o student
   ```

4. Run the program:

   ```bash
   ./student
   ```

   On Windows PowerShell:

   ```powershell
   .\student.exe
   ```

## Data Storage

Student records are stored in `data/students.txt` and automatically loaded when the program starts. Changes are saved whenever records are added, updated, or deleted.

## Learning Objectives

This project demonstrates practical implementation of:

- Classes and objects
- Encapsulation and member functions
- Vectors and loops
- Conditional statements
- CRUD operations
- File input/output
- Basic input validation

## Author

**Souhard Gupta**

GitHub: [@SOUHARDGUPTA](https://github.com/SOUHARDGUPTA)

## License

This project is open-source and available for educational purposes.
