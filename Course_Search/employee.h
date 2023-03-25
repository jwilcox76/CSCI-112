/*Joshua Wilcox
 *CSCI 112 - 12/6/2022
 *employee class header file
 */


#include "person.h"

class Employee: public Person{
    private:
       string type, work;
    public:
        string getType(){return type;};
        string getWork(){return work;};

        void setType(string t){type = t;};
        void setWork(string w){work = w;};
};
