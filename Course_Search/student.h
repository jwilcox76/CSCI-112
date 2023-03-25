/*Joshua Wilcox
 *CSCI 112 - 6/12/2022
 *student class header file
 */

#include "person.h"


class Student: public  Person{
    private:
        int credits;
    public:
        int getCredits(){return credits;};
        void setCredits(int c){credits = c;};
};
