# Student Performance Tracker

## Problem Statement
The Student Performance Tracker is a software solution designed to manage
and sort academic scores, search for students, and handle duplicate entries using hashing.
This system leverages searching, sorting, and hashing techniques to efficiently retrieve
student records, rank students by grades, and manage data with collision resolution. The
assignment focuses on implementing these algorithms in C++ or Python to address real-world
academic performance tracking scenarios.

## Attributes
- **StudentID** -> Integer,unique identifier for each student
- **Studentname** -> String,name of the student
- **StudentGrade** -> Float,grade of the student
- **StudentCourse** -> String,course of the student
- **HashTable** -> Vector Array,stores student using hashing based on Students
- **StudentArray** -> Vector,stores all student records for searching and sorting
- **SortedList** -> Vector,used for stored and ranked data

## Methods
- **insertStudent()** -> Inserts student record into hash table
- **SearchById()** -> Searches for a student by ID using binary search
- **SearchByName()** -> Searches for a student by name using binary search
- **sortRecords()** -> Sorts students by grade using insertion sort
- **rankByPerformance()** -> Ranks student using heap sort
- **compareSortingComplexity()** -> Compares time and space complexities of sorting and seraching
- **displayChoice()** -> Displays menu-driven options

## Code Explanation
The Student Performance tracker utilizes multiple fundamental data structures and 
algorithms to manage student records efficiently and demonstrate real-world
applications of data organization,searching,and sorting in C++.

**HashTable** is used for sorting student records.Each student entry contains a unique
student ID,student name,grade,and course name.The hash table divides data into multiple buckets
using a simple hash function based on the modulus operator.

**BinarySearch** it repeatedly divides the dataset in half,significantly reducing the search
space at each step.This makes it far more efficient than linear search,especially for large
datasets,achieving a time complexity of O(log n).This structure simulates database like indexing 
and retrival mechanisms,where searches must be both fast and accurate.

**Insertion Sort** which sorts the list of students based on thier grades.Insertion sort
works by dividing the array into sorted and unsorted parts,then repeatedly picking elements
from the unsorted section.While not the fastest algorithm for vey large datasets.Insertion sort
provides a clear and intutive way to demonstrate sorting logic,making it accurate.

**HeapSort** A heap is a complete binary tree that satisfies the heap property — 
in this case, a max heap, where each parent node’s value (student grade) is 
greater than or equal to its children’s. Using C++’s STL functions make_heap() 
and sort_heap(), the program organizes students so that the highest grades bubble 
up to the top, enabling a sorted ranking in descending order. 
Heap Sort guarantees a worst-case time complexity of O(n log n) and performs 
efficiently even on larger datasets.

**MenuDriven** The menu-driven interface provides a clear and user-friendly way to 
interact with the system. Using a do-while loop and a switch statement, the program 
continuously presents options such as adding a record, searching, sorting, 
or ranking until the user chooses to exit. This approach demonstrates 
control structures, modular programming, and object-oriented principles, 
as all functionality is encapsulated within the StudentPerformanceTracker class.

## Time Complexity

- **insertStudent()** -> O(1)
- **SearchById()** -> O(log n)
- **SearchByName()** -> O(log n)
- **sortRecords()** -> O(n2)
- **rankByPerformance()** -> O(n log n)
- **compareSortingComplexity()** -> O(1)

## Space Complexity
- **Overal Space Complexity** -> O(n)

## Learning Outcomes
- Hashing and Collision handling
- Binary serach algorithm
- Insertion sort algorithm
- Heap sortand Priority Ranking
- Time and Space Complexity Analysis
- Menu-Driven Programming
- Real-World Application

## Code Output
<img width="529" height="529" alt="1" src="https://github.com/user-attachments/assets/43000198-7a39-49a0-a414-43169ad37cd5" />
<img width="519" height="302" alt="2" src="https://github.com/user-attachments/assets/f15a8e14-eaf0-4e68-a01d-f089b7318f71" />
<img width="498" height="352" alt="3" src="https://github.com/user-attachments/assets/ffa8e37b-00ac-4831-8ef5-9a74c4e67fc7" />
<img width="447" height="307" alt="4" src="https://github.com/user-attachments/assets/a9724b6b-5675-4354-b74b-a36ca9e7a25a" />
<img width="456" height="303" alt="5" src="https://github.com/user-attachments/assets/f8ce4a9e-49cd-44b5-8070-278f9aff4839" />
<img width="503" height="517" alt="6" src="https://github.com/user-attachments/assets/62a0c9b7-3916-4824-93d0-1fe55e29d561" />

## Student Details
- **Name** -> Sidharth Krishna S
- **Roll No** -> 2401720003
- **Course** -> BSc Computer Science
- **Semester** -> 3rd Semester
- **Assignment** -> Data Structures Lab Assignment 3
  
## GitHub Link
- C++ Code File -> https://github.com/SidharthBScCS/Student-Performance-Tracker/blob/main/StudentPerformance.cpp
