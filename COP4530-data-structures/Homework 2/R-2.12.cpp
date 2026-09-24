/* Name: Diya Jain
U81673988 */

#include "iostream"
#include "string"
using namespace std;

class person
{
    string uid;
    string name;

    public:
    void printPerson();
    string GetName();
};

class Student : public person
{
private:
    string major;
    int graduation;

public:
    void printStudent();
    void printMajor();
};

class ugStudent : Student
{
    private:
    string level;
    public:

    void setLevel(string lev)
    {
        this->level = lev;
    }
};

class GradStudent : Student
{
    private:
    string level;
    string dept;
    public:

    void setLevel(string lev)
    {
        this->level = lev;
    }

    void setDept(string dep)
    {
        this->dept = dep;
    }
};

class Faculty : person
{
    private:
    string decipline;
    public:
    void setDecipline(string decipline)
    {
        this->decipline = decipline;
    }
};

class Professor : Faculty
{
    private:
    bool tenured;
    string officeLoc;
    string researchArea;
    public:
    void setTenure(bool ten)
    {
        this->tenured = ten;
    }
    void SetResearchArea(string area)
    {
        this->researchArea =area;
    }
    void SetOfficeLoc(string loc)
    {
        this->officeLoc =loc;
    }
};

class Instructor : Faculty
{
    private:
    string classRoom;
    public:
    void setClassCode(string ccode)
    {
        this->classRoom = ccode;
    }
};

int main()
{
    return 0;
}