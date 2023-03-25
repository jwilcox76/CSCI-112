/*Joshua Wilcox
 *CSCI 112 - 6/12/2022
 *person class header file
 */

#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person{
    protected:
        string fname, lname;
        int id;
    public:
        void setFname(string fn){fname = fn;};
        void setLname(string ln){lname = ln;};
        void setInt(int d){id = d;};

        string getFname(){return fname;};
        string getLname(){return lname;};
        int getId(){return id;};

};

#endif
