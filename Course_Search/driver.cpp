/*Joshua Wilcox
 *CSCI112
 *11/30/2022
 */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "employee.h"
#include "student.h"
#include "class.h"
using namespace std;


//each of the following split functions are respondisble for taking in a string picking out its relavent information and placing that information into a vector

vector<string> splitStudent(string s){
    vector<string> v;
    string one,two,three,four;
    int pos1,pos2,pos3;

    pos1 = s.find(",");
    pos2 = s.find(",",pos1+1);
    pos3 = s.find(",", pos2+1);

    one = s.substr(0,pos1);
    two = s.substr(pos1+1, (pos2-1)-pos1);
    three = s.substr(pos2+1, (pos3-1)-pos2);
    four = s.substr(pos3+1);

    v.push_back(one);
    v.push_back(two);
    v.push_back(three);
    v.push_back(four);
    return v;

}

vector<string> splitEmployee(string s){
    vector<string> v;
    string one,two,three,four,five;
    int pos1,pos2,pos3,pos4;

    pos1 = s.find(",");
    pos2 = s.find(",",pos1+1);
    pos3 = s.find(",", pos2+1);
    pos4 = s.find(",", pos3+1);

    one = s.substr(0,pos1);
    two = s.substr(pos1+1, (pos2-1)-pos1);
    three = s.substr(pos2+1, (pos3-1)-pos2);
    four = s.substr(pos3+1, (pos4-1)-pos3);
    five = s.substr(pos4+1);

    v.push_back(one);
    v.push_back(two);
    v.push_back(three);
    v.push_back(four);
    v.push_back(five);
    return v;
}

vector<string> splitClass(string s){
    vector<string> v;
    string one,two,three,four,five,six,seven,eight,nine,ten;
    int pos1,pos2,pos3,pos4,pos5,pos6,pos7,pos8,pos9;

    pos1 = s.find(",");
    pos2 = s.find(",",pos1+1);
    pos3 = s.find(",", pos2+1);
    pos4 = s.find(",", pos3+1);
    pos5 = s.find(",", pos4+1);
    pos6 = s.find(",", pos5+1);
    pos7 = s.find(",", pos6+1);
    pos8 = s.find(",", pos7+1);
    pos9 = s.find(",", pos8+1);


    one = s.substr(0,pos1);
    two = s.substr(pos1+1, (pos2-1)-pos1);
    three = s.substr(pos2+1, (pos3-1)-pos2);
    four = s.substr(pos3+1, (pos4-1)-pos3);
    five = s.substr(pos4+1, (pos5-1)-pos4);
    six = s.substr(pos5+1, (pos6-1)-pos5);
    seven = s.substr(pos6+1, (pos7-1)-pos6);
    eight = s.substr(pos7+1, (pos8-1)-pos7);
    nine = s.substr(pos8+1, (pos9-1)-pos8);
    ten = s.substr(pos9+1);


    //These two lines of codes are used to remove the quotation marks around the names of the teachers
    seven.replace(0, 1, "");
    seven.replace(seven.size() - 1, 1, "");

    v.push_back(one);
    v.push_back(two);
    v.push_back(three);
    v.push_back(four);
    v.push_back(five);
    v.push_back(six);
    v.push_back(seven);
    v.push_back(eight);
    v.push_back(nine);
    v.push_back(ten);
    return v;


}

//the following read functions are responsible for reading in information from each file, calling upon the split function, and using the vectors returned from the split function to fillout the variable field of each class type (students, employees and classes)

void read_student(vector<Student>& students){
    ifstream inpfile;
    inpfile.open("students.csv");
    string str;
    vector<string> vec;

    while(getline(inpfile, str)){
        vec = splitStudent(str);
        Student e;
        e.setFname(vec[0]);
        e.setLname(vec[1]);
        e.setInt(stoi(vec[2]));
        e.setCredits(stoi(vec[3]));

        students.push_back(e);
    }

    inpfile.close();

}


void read_emps(vector<Employee>& employees){
    ifstream inpfile;
    inpfile.open("employees.csv");
    string str;
    vector<string> vec;

    while(getline(inpfile, str)){
        vec = splitEmployee(str);
        Employee e;
        e.setFname(vec[0]);
        e.setLname(vec[1]);
        e.setInt(stoi(vec[2]));
        e.setType(vec[3]);
        e.setWork(vec[4]);

        employees.push_back(e);
    }

    inpfile.close();

}


void read_class(vector<Class>& classes){
    ifstream inpfile;
    inpfile.open("classes.csv");
    string str;
    vector<string> vec;

    while(getline(inpfile, str)){
        vec = splitClass(str);
        Class e;
        e.setClassName(vec[0]);
        e.setTitle(vec[1]);
        e.setTeacher(vec[6]);
        e.setDateTime(vec[7]);
        e.setLocation(vec[8]);
        e.setCredit(stoi(vec[9]));
        classes.push_back(e);
    }

    inpfile.close();

}

//The following print statements use the selected student object and a copy of the class vector to print out the relavent information

void printStudent(vector<Class> classes, Student student){
    vector<string> classesSelect;
    vector<string> classesValid;
    vector<string> classesInvalid;
    string input, classInfo;
    int totalCredits = 0;

    cout << "Enter classes to take - one line with spaces between: " << endl;;
    getline(cin, input);
    cout << endl;

//this for loop looks to see if the the class indexed over matches on from the string input, if so and if else statement is used to see if the student is able to take the class. This works the same for the employee function
    for(int i = 0; i < classes.size(); ++i){
        if(input.find(classes[i].getClassName()) != string::npos){
            classesSelect.push_back(classes[i].getClassName());
            totalCredits = totalCredits + classes[i].getCredit();
            if(21 >= totalCredits){
                classInfo = classes[i].getClassName() + " " + classes[i].getTitle() + " Taught by " + classes[i].getTeacher() + " At " + classes[i].getDateTime() + " In " + classes[i].getLocation();
                classesValid.push_back(classInfo);
            }
            else{
                classesInvalid.push_back(classes[i].getClassName());
            }
        }
    }

    cout << "Student name: " << student.getLname() << " " << student.getFname() << " ID: " << student.getId() << " Current credits: " << student.getCredits() << endl;

    cout << "Is regestered for:  " << endl;
    for(int i = 0; i < classesValid.size(); ++i){
        cout << classesValid[i] << endl;
    }
    for(int i = 0; i < classesInvalid.size(); ++i){
        cout << "Could not register for "  << classesInvalid[i] << endl;
    }
}

void printEmployee(vector<Class> classes, Employee employee){
    vector<string> classesSelect;
    vector<string> classesValid;
    vector<string> classesInvalid;
    string input, classInfo;
    int totalCredits = 0;
    int empCredits;
    cout << "Enter classes to take - one line with spaces between: " << endl;
    getline(cin, input);
    cout << endl;
    //This is the only part that is different from the printStudent function
    //This if else statement is used to decide how many credits the employee can take depending on if that employee is part-time or full-time
    if(employee.getType().compare("PT") == 0){
        empCredits = 3;
    }
    else{
        empCredits = 7;
    }

    for(int i = 0; i < classes.size(); ++i){
        if(input.find(classes[i].getClassName()) != string::npos){
            classesSelect.push_back(classes[i].getClassName());
            totalCredits = totalCredits + classes[i].getCredit();
            if(empCredits >= totalCredits){
                classInfo = classes[i].getClassName() + " " + classes[i].getTitle() + " Taught by " + classes[i].getTeacher() + " At " + classes[i].getDateTime() + " In " + classes[i].getLocation();
                classesValid.push_back(classInfo);
            }
            else{
                classesInvalid.push_back(classes[i].getClassName());
            }
        }
    }

    cout << "Employee name: " << employee.getLname() << " " << employee.getFname() << " ID: " << employee.getId() << " Type: " << employee.getType() << " Works in: " << employee.getWork() << endl;

    cout << "Is regestered for:  " << endl;
    for(int i = 0; i < classesValid.size(); ++i){
        cout << classesValid[i] << endl;
    }
    for(int i = 0; i < classesInvalid.size(); ++i){
        cout << "Could not register for "  << classesInvalid[i] << endl;
    }


}


int main(){
    string name, fname, lname;
    int pos;

    //Vectors of each class are called and filled out with the relavent information
    vector<Employee> employees;
    read_emps(employees);
    vector<Class> classes;
    read_class(classes);
    vector<Student> students;
    read_student(students);

    cout << "Enter the first and last name: ";
    getline(cin, name);


    pos = name.find(" ");
    fname = name.substr(0, pos);
    lname = name.substr(pos+1);


    //These for loops are used to decide whether the name inputed is a student or an employee
    for(int i  = 0; i < students.size(); ++i){
        if(fname == students[i].getLname() && lname == students[i].getFname()){
            printStudent(classes, students[i]);
        }
    }

    for(int i = 0; i < employees.size(); ++i){
        if(fname == employees[i].getLname() && lname == employees[i].getFname()){
            printEmployee(classes, employees[i]);
        }
    }
    return(0);

}
