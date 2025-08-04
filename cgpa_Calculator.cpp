#include <iostream>
#include <vector>
using namespace std;

class Subject{
    public:
    string subjectName;
    int credit;
    float gradePoint;

    //constructor
    Subject(string name, int cr, float gp)
    {
        subjectName = name;
        credit = cr;
        gradePoint = gp;
    }
};

class Student {
    public:
    string name;
    vector < Subject > subjects;
    
    //constructor
    Student(string studentName)
    {
        name=studentName;
    }

    void addSubject(string subjectName, int credit, float gradePoint)
    {
        Subject newSubject(subjectName, credit, gradePoint);
        subjects.push_back(newSubject);
    }

    float calculateCGPA()
    {
        int totalcredit = 0;
        float weightgradepoint=0;

        for(const Subject & subject : subjects)
        {
            totalcredit += subject.credit;
            weightgradepoint += subject.credit * subject.gradePoint;
        }
        return (totalcredit > 0) ? (weightgradepoint / totalcredit) : 0;
    }

    void displaySubjects()
    {
        cout << "\n--- Subjects Information ---\n";
        for (const Subject& subject : subjects) {
            cout << "Subject: " << subject.subjectName
                 << " | Credit: " << subject.credit
                 << " | Grade Point: " << subject.gradePoint << endl;
        }
    }

    void displayCGPA() 
    {
        cout << "\n--- Student Summary ---" << endl;
        cout << "Student Name: " << name << endl;
        float cgpa = calculateCGPA();
        cout << "Final CGPA: " << cgpa << endl;
    }
};   

int main()
{
    string studentName;
    int numsub;
    int i;

    cout<<"Enter student's name: ";
    getline (cin, studentName);

    cout<<"Enter the number of subjects: ";
    cin>>numsub;

    Student student(studentName);

    for(i = 0; i < numsub; i++)
    {
        string subjectName;
        int credit;
        float gradePoint;

        cout<<"\nEnter the subject's name: ";
        cin.ignore(); // To avoid newline issue after cin
        getline(cin, subjectName);

        cout<<"Enter the credit: ";
        cin>> credit;

        cout<<"Enter the grade point: ";
        cin>>gradePoint;
        student.addSubject(subjectName, credit, gradePoint);
    }
    student.displaySubjects();
    student.displayCGPA();
    return 0;
}
