#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct Student{
    int StudentID;
    string StudentName;
    float StudentGrade;
    string StudentCourse;

    static void insertStudent(vector<Student> hashTable[],Student s){
        int index = s.StudentID % 10;
        hashTable[index].push_back(s);
        cout << "Student added into hash table" << endl;
    }

    static int SearchById(vector<Student>& arr,int id){
        sort(arr.begin(), arr.end(), [](Student a, Student b){ 
            return a.StudentID < b.StudentID; 
        });
        int low = 0, high = arr.size() - 1;
        while(low<=high){
            int mid = (low + high) / 2;
            if(arr[mid].StudentID==id){
                return mid;
            }
            else if(arr[mid].StudentID<id){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }

    static int SearchByName(vector<Student>& arr,string name){
        sort(arr.begin(), arr.end(), [](Student a, Student b){ 
            return a.StudentName < b.StudentName; 
        });
        int low = 0;
        int high = arr.size() - 1;
        while(low<=high){
            int mid = (low + high) / 2;
            if(arr[mid].StudentName==name){
                return mid;
            }
            else if(arr[mid].StudentName<name){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }

    static void sortRecords(vector<Student>& arr){
        for (int i = 1; i < arr.size();i++){
            Student key = arr[i];
            int j = i - 1;
            while(j>=0 && arr[j].StudentGrade>key.StudentGrade){
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    static void display(Student s){
        cout << "Student Details" << endl;
        cout << "ID: " << s.StudentID << endl;
        cout << "Name: " << s.StudentName << endl;
        cout << "Grade: " << s.StudentGrade << endl;
        cout << "Course: " << s.StudentCourse << endl;
    }
};

class StudentPerformanceTracker{
    vector<Student> HashTable[10];
    vector<Student> StudentArray;
    vector<Student> SortedList;

    public:

    void addStudentRecord(int id,string name,float grade,string course){
        Student s = {id, name, grade, course};
        Student::insertStudent(HashTable, s);
        StudentArray.push_back(s);
    }

    void searchByStudent(int id){
        int index = Student::SearchById(StudentArray, id);
        if(index!=-1){
            Student::display(StudentArray[index]);
        }
        else{
            cout << "Student ID not found" << endl;
        }
    }

    void searchByStudent(string name){
        int index = Student::SearchByName(StudentArray, name);
        if(index!=-1){
            Student::display(StudentArray[index]);
        }
        else{
            cout << "Student name not found" << endl;
        }
    }

    void sortByGrades(){
        SortedList = StudentArray;
        Student::sortRecords(SortedList);
        cout << "Students sorted by grade using Insertion sort" << endl;
        for(Student s:SortedList){
            cout << "Name: " << s.StudentName << endl;
            cout << "Grade: " << s.StudentGrade << endl;
        }
    }

    void rankByPerformance(){
        SortedList = StudentArray;
        make_heap(SortedList.begin(), SortedList.end(), [](Student a, Student b){ 
            return a.StudentGrade < b.StudentGrade; 
        });
        sort_heap(SortedList.begin(), SortedList.end(), [](Student a, Student b){ 
            return a.StudentGrade < b.StudentGrade; 
        });
        cout << "Student Ranking using heap sort" << endl;
        for(Student s:SortedList){
            cout << "Name: " << s.StudentName << endl;
            cout << "Grade: " << s.StudentGrade << endl;
        }
    }

    void compareSortingComplexity(){
        cout << "Insertion Sort" << endl;
        cout << "Time Complexity:O(n)" << endl;
        cout << "Space Complexity:O(1)" << endl;

        cout << "Bubble Sort" << endl;
        cout << "Time Complexity:O(n)" << endl;
        cout << "Space Complexity:O(1)" << endl;

        cout << "Merge Sort" << endl;
        cout << "Time Complexity:O(n log n)" << endl;
        cout << "Space Complexity:O(n)" << endl;

        cout << "Quick Sort" << endl;
        cout << "Time Complexity:O(n log n)" << endl;
        cout << "Space Complexity:O(n log n)" << endl;

        cout << "Heap Sort" << endl;
        cout << "Time Complexity:O(n log n)" << endl;
        cout << "Space Complexity:O(1)" << endl;

        cout << "Binary Search" << endl;
        cout << "Time Complexity:O(log n)" << endl;
        cout << "Space Complexity:O(1)" << endl;
    }

    void displayChoice(){
        cout << "Student Performance Tracker by SIDHARTH 2401720003" << endl;
        cout << "1.Add Student Record" << endl;
        cout << "2.Search Student by ID using Binary Search" << endl;
        cout << "3.Search Student by Name using Binary Search" << endl;
        cout << "4.Sort Students by Grade using Insertion Sort" << endl;
        cout << "5.Rank Students by Performance using Heap Sort" << endl;
        cout << "6.Compare Sorting Complexity" << endl;
        cout << "7.Exit" << endl;
    }
};

int main(){
    StudentPerformanceTracker tracker;
    int choice;

    do{
        tracker.displayChoice();
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                int id;
                cout << "Enter student ID: ";
                cin >> id;
                cin.ignore();

                string name;
                cout << "Enter Student Name: ";
                getline(cin, name);

                float grade;
                cout << "Enter Grade: ";
                cin >> grade;
                cin.ignore();

                string course;
                cout << "Enter Course Details: ";
                getline(cin, course);

                tracker.addStudentRecord(id, name, grade, course);
                break;
            }

            case 2:{
                int id;
                cout << "Enter Student ID to search: ";
                cin >> id;
                tracker.searchByStudent(id);
                break;
            }


            case 3:{
                string name;
                cout << "Enter Student Name to search: ";
                cin.ignore();
                getline(cin, name);
                tracker.searchByStudent(name);
                break;
            }

            case 4:{
                tracker.sortByGrades();
                break;
            }

            case 5:{
                tracker.rankByPerformance();
                break;
            }

            case 6:{
                tracker.compareSortingComplexity();
                break;
            }

            case 7:{
                cout << "Exited....." << endl;
                break;
            }

            default:
                cout << "Invalid choice.Please try again." << endl;
        }
    } while (choice != 7);
}