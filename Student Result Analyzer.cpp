#include <iostream>
using namespace std;

class Student
{
    string name, roll, course, semester, year;
    int marks[9];

    string subjects[9] = {
        "CS25C01","CS25C03","CY25C01","EN25C01",
        "MA25C01","ME25C04","PH25C01","UC25A01","UC25H01"
    };

public:

    void getDetails()
    {
        cout << "Enter Student Name: ";
        cin >> name;

        cout << "Enter Roll Number: ";
        cin >> roll;

        cout << "Enter Course: ";
        cin >> course;

        cout << "Enter Semester: ";
        cin >> semester;

        cout << "Enter Year: ";
        cin >> year;
    }

    void getMarks()
    {
        cout << "\nEnter marks for 9 subjects:\n";

        for(int i = 0; i < 9; i++)
        {
            cout << subjects[i] << ": ";
            cin >> marks[i];

            if(marks[i] < 0 || marks[i] > 100)
            {
                throw "Invalid Mark Entered!";
            }
        }
    }

    string getGrade(int m)
    {
        if(m >= 91) return "S";
        else if(m >= 81) return "A+";
        else if(m >= 71) return "A";
        else if(m >= 66) return "B+";
        else if(m >= 61) return "B";
        else if(m >= 56) return "C+";
        else if(m >= 50) return "C";
        else return "U";
    }

    float getGradePoint(string grade)
    {
        if(grade == "S") return 10;
        else if(grade == "A+") return 9;
        else if(grade == "A") return 8;
        else if(grade == "B+") return 7;
        else if(grade == "B") return 6.5;
        else if(grade == "C+") return 6;
        else if(grade == "C") return 5;
        else return 0;
    }

    void displayResult()
    {
        float totalPoints = 0;

        cout << "\n========================================\n";
        cout << "  CHRIST THE KING ENGINEERING COLLEGE\n";
        cout << "========================================\n";

        cout << "\nName       : " << name;
        cout << "\nRoll No    : " << roll;
        cout << "\nCourse     : " << course;
        cout << "\nSemester   : " << semester;
        cout << "\nYear       : " << year;

        cout << "\n\nSubject\tMarks\tGrade\tPoint\n";

        for(int i = 0; i < 9; i++)
        {
            string grade = getGrade(marks[i]);
            float point = getGradePoint(grade);

            cout << subjects[i] << "\t"
                 << marks[i] << "\t"
                 << grade << "\t"
                 << point << endl;

            totalPoints += point;
        }

        float avg = totalPoints / 9;

        cout << "\nTotal Grade Points : " << totalPoints << endl;
        cout << "Average Grade Point: " << avg << endl;

        cout << "========================================\n";
    }
};

int main()
{
    Student s;

    try
    {
        s.getDetails();
        s.getMarks();
        s.displayResult();
    }
    catch(const char* msg)
    {
        cout << "\nException: " << msg << endl;
    }

    return 0;
}
