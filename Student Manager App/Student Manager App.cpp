#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
using namespace std;


struct Students
{
    string firstName;
    string lastName;
    int age;
    int studentID;
    float grade;
};


class StudentManager {
private:
    //vector<Students> students;
    Students* students;
    int count;
    int capacity;


public:
    StudentManager(int cap) {
        capacity = cap;
        count = 0;
        students = new Students[capacity];
    }
    ~StudentManager() {
        delete[] students;
    }

    /*void addStudentVector(const string& firstName, const string& lastName, int age, int studentID, float grade) {
        Students newStudent = { firstName, lastName, age, studentID, grade };
        students.push_back(newStudent);
        count++;
    }*/


    void addStudent(const string& firstName, const string& lastName, int age, int studentID, float grade) {
        if (count < capacity)
        {
            students[count].firstName = firstName;
            students[count].lastName = lastName;
            students[count].age = age;
            students[count].grade = grade;
            students[count].studentID = studentID;
            count++;
        }
        else
        {
            cout << "There is no capacity for adding new student!!" << endl;
        }
    }
    void deleteStudent(int studentID) {

        bool found = false;
        for (int i = 0; i < count; i++) {
            if (students[i].studentID == studentID) {
                found = true;
                for (int j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];  // Öðrenciyi silmek için diziyi kaydýr
                }
                count--;
                cout << "Student has been deleted: " << studentID << endl;
                break;
            }
        }
        if (!found) {
            cout << "Öðrenci bulunamadý!" << endl;
        }
    }
    void listStudent() {
        if (count == 0)
        {
            cout << "There is no student: " << endl;
        }
        else {
            cout << "Students: " << endl;
            cout << setw(10) << "Student ID" << setw(20) << "Name" << setw(20) << "Surname" << setw(5) << "Age" << setw(10) << "Grade" << endl;

            for (int i = 0; i < count; i++)
            {
                cout << setw(10) << students[i].studentID << setw(20) << students[i].firstName
                    << setw(20) << students[i].lastName << setw(5) <<
                    students[i].age << setw(10) << students[i].grade << endl;
                /*cout <<students[i].studentID << "             "
                    << students[i].firstName << "   "
                    << students[i].lastName << "   "
                    << students[i].age << "    "
                    << students[i].grade << endl;*/
            }
        }

    }
    void updateStudentGrade(int studentID, float newGrade) {
        bool found = false;
        for (int i = 0; i < count; i++)
        {
            if (students[i].studentID == studentID)
            {
                found = true;
                students[i].grade = newGrade;
                cout << "Grade has been updated: " << endl;
            }

        }
        if (!found)
        {
            cout << "There is no student. " << endl;

        }
    }


};
int main()
{
    bool quit = false;
    int operation;
    StudentManager manager(10);
    while (!quit)
    {
        cout << endl << "Student Manager System! Please choose what you want to do (0 for quit): " << endl
            << "1) Add new students " << endl
            << "2) Delete a student by ID " << endl
            << "3) List all students " << endl
            << "4) Change grade by ID " << endl;
        cin >> operation;

        if (operation == 0)
        {
            cout << "Stoped";
            break;
        }
        else if (operation == 1)
        {
            string* name = new string;
            string* surname = new string;
            int* age = new int;
            float* grade = new float;
            int* ID = new int;
            int* num = new int;
            cout << "How many student would you like to add? " << endl;
            cin >> *num;
            if (*num > 0)
            {
                for (int i = 0; i < *num; i++)
                {
                    cout << " Student ID: " << endl;
                    cin >> *ID;
                    cout << " Student name: " << endl;
                    cin >> *name;
                    cout << " Student surname: " << endl;
                    cin >> *surname;
                    cout << " Student age: " << endl;
                    cin >> *age;
                    cout << " Student grade: " << endl;
                    cin >> *grade;

                    manager.addStudent(*name, *surname, *age, *ID, *grade);

                }
            }
            delete name;
            delete surname;
            delete age;
            delete ID;
            delete grade;
            cout << "Students has been added! " << endl;
        }
        else if (operation == 2)
        {
            int* ID = new int;
            cout << "Write the student ID you want to delete: " << endl;
            cin >> *ID;
            manager.deleteStudent(*ID);
            delete ID;
        }
        else if (operation == 3)
        {
            manager.listStudent();
        }
        else if (operation == 4)
        {
            int* Id = new int;
            float* grade = new float[5];
            cout << "Write the student ID: " << endl;
            cin >> *Id;
            cout << "Student grade: ";
            cin >> *grade;
            manager.updateStudentGrade(*Id, *grade);
            delete Id;
            delete grade;
        }
        else
        {
            cout << "Unkonwn input please try again! " << endl;
        }
    }
}
