

class Class{
    private:
        string className, title, teacher, dateTime, timeTime, location;
        int credits;
    public:
        string getClassName(){return className;};
        string getTitle(){return title;};
        string getTeacher(){return teacher;};
        string getDateTime(){return dateTime;};
        string getTimeTime(){return timeTime;};
        string getLocation(){return location;};
        int getCredit(){return credits;};

        void setClassName(string cn){className = cn;};
        void setTitle(string t){title = t;};
        void setTeacher(string t){teacher = t;};
        void setDateTime(string dt){dateTime = dt;};
        void setTimeTime(string tt){timeTime = tt;};
        void setLocation(string l){location = l;};
        void setCredit(int c){credits = c;};
};
