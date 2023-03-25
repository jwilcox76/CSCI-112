/*Joshua Wilcox
 *CSCI 112 - 11/9/2022
 *lab6
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Term {
    private:
    int coeff;
    int exp;
    public:
    Term(string);
    Term() {coeff = 0; exp = 0; };
    void print();
    int get_exp() { return exp; }
    void set_exp(int e) { exp = e; }
    int get_coeff() { return coeff; }
    void set_coeff(int n) { coeff = n; }
};

void Term::print() {
//Print statement that checks for a 1 and 0 in the coefficient place and the exponent place.
    string a = "";
    if(get_coeff() != 0 && get_coeff() != 1){
        a = a + std::to_string(get_coeff());
    }
    if(get_exp() != 0){
        a = a + "x";
        if(get_exp() != 1){
            a = a + std::to_string(get_exp());
        }
    }

    cout << a << " ";
}

Term::Term(string input) {
//the follow sequecnce of if statements reads in the term to set values for its coefficient and exponent.
    int index = input.find("x");
    string temp;
    if(index == 0){
        coeff = 1;
        temp = input.substr(index+1);
        if(temp == ""){
            exp = 1;
        }
        else{
            exp = stoi(temp);
        }
    }
    else if(index == -1){
        coeff = stoi(input);
        exp = 0;
    }
    else{
        coeff = stoi(input.substr(0, index));
        temp = input.substr(index+1);
        if(temp == ""){
            exp = 1;
        }
        else{
            exp = stoi(temp);
        }
    }
    set_coeff(coeff);
    set_exp(exp);
}

class Polynomial {
    private:
    vector<Term> terms;
    public:
    void simplify();
    void read();
};

void Polynomial::read() {
    string str;
    char op;
    bool done = false;

//reads in terms and creates new term object
    while (!done) {
        cin >> str;
        cin >> op;
        if (cin.eof()) {
            done = true;
        }
        //this if is used for negative values
        if(op == '-'){
            str = "-"+str;
        }
        Term newTerm(str);
        terms.push_back(newTerm);
    }
}

bool compare(Term t1, Term t2) {
    return t1.get_exp() > t2.get_exp();
}

void Polynomial::simplify() {
//This function adds together the like terms and simplifies the expression
    int sumCoeff = 0;
    int expCompare = 0;
    sort(terms.begin(), terms.end(), compare);
    for(Term m : terms){
        if(expCompare == 0){
            expCompare = m.get_exp();
            sumCoeff = m.get_coeff();
        }
        else{
            if(expCompare == m.get_exp()){
                sumCoeff += m.get_coeff();
            }
            else{

                string a = std::to_string(sumCoeff) + "x" + std::to_string(expCompare);
                Term term(a);                
                term.print();
                cout << "+ ";
                sumCoeff = m.get_coeff();
                expCompare = m.get_exp();
            }
        }

    }
    string a = std::to_string(sumCoeff) + "x" + std::to_string(expCompare);
    Term term(a);
    term.print();
    cout << endl;
}

int main(void) {
    Polynomial poly;
    poly.read();
    poly.simplify();
    return(0);
}
