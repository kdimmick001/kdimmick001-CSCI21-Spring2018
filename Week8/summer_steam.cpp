#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//Create summer camps either in Paradise or Chico
//Add kids to the list
    //Including:
        //Name First and Last
        //Age
        //Parent Name
        //Parent Phone Number
        //Parent Email
        //Emergency Contact Name
        //Emergency Contact Number
        //If paid-> changed to amount owed
//Have a vector of classes dependent on location.

class Camp{
    private:
        //To hold the student names.
        vector<Student*> roster;
        //Adds to owed
        double price;
        //Time the class is being held.
        string time;
        //Dates being held.
        string dates;
        //Location.
        string location;
        //Name of the camp.
        string camp_name;
    
    public:
        //Overload Constructor
        Camp(string name);
        //Mutators for all variables.
        void SetPrice(double cost);
        void SetTime(string hours);
        void SetDates(string week);
        void SetLocation(string site);
        void SetClassName(string name);
        //Print overview of class.
        void PrintClassOverview();
        //To add a student to the roster
        void AddStudent(string camper_first, string camper_last);
};

Camp::Camp(string name){
    camp_name = name;
};

void Camp::SetPrice(double cost){
    price = cost;
    return;
};

void Camp::SetTime(string hours){
    time = hours;
    return;
};

void Camp::SetDates(string week){
    dates = week;
    return;
};

void Camp::SetLocation(string site){
    location = site;
    return;
};

void Camp::SetClassName(string name){
    camp_name = name;
    return;
};

//Need to be able to search for a student's records.
void Camp::AddStudent(string camper_first, string camper_last){
    Student* camper = new Student*;
    camper.SetFirstName(camper_first);
    camper.SetLastName(camper_last);
};

void Camp::PrintClassOverview(){
    cout << "---------------------------------" << endl;
    cout << "Name: " << camp_name << endl
    cout << "---------------------------------" << endl;
    cout << "Location: " << location << endl;
    cout << "Dates: " << dates << endl;
    cout << "Time: " << time << endl;
    cout << "Price: $" << price << endl;
    
};


class Student{
    private:
        string student_first_name;
        string student_last_name;
        int student_age;
        string parent_name;
        string phone_number;
        string email;
        string emergency_contact_number;
        string allergies;
        double amount_owed;
        Student* next;
        
    public:
        //Constructor
        Student();
};

Student::Student(){
    next = NULL;
};

void Student::SetName(string camper_first, string camper_last){
    student_first_name = camper_first;
    student_last_name = camper_last;
    return;
};

string Student::GetFirstName(){
    return student_first_name;
};

string Student::GetLastName(){
    return student_last_name;
};

void Student::SetAge(int age){
    student_age = age;
    return;
};

int Student::GetAge(){
    return student_age;
};

void Student::SetParentName(string parent){
    parent_name = parentt;
    return;
};

string Student::GetParentName(){
    return parent_name;
};

void Student::SetPhoneNumber(string phone){
    phone_number = phone;
    return;
};

string Student::GetPhoneNumber(){
    return phone_number;
};

void Student::SetEmail(string email_address){
    email = email_address;
    return;
};

string Student::GetEmail(){
    return email;
};

void Student::SetEmergencyContact(string emergency){
    emergency_contact_number = emergency;
    return;
};

string Student::GetEmergencyContact(){
    return emergency_contact_number;
};

void Student::SetAllergies(string allergic){
    allergies = allergic;
    return;
};

string Student::GetAllergies(){
    return allergies;
};

void Student::SetAmountOwed(double price){
    amount_owed = amount_owed + price;
    return;
};

double Student::GetAmountOwed(){
    return amount_owed;
};

void #include <string>
#include <iostream>
#include <fstream>
using namespace std;

//Create summer camps either in Paradise or Chico
//Add kids to the list
    //Including:
        //Name First and Last
        //Age
        //Parent Name
        //Parent Phone Number
        //Parent Email
        //Emergency Contact Name
        //Emergency Contact Number
        //If paid-> changed to amount owed
//Have a vector of classes dependent on location.

class Camp{
    private:
        //To hold the student names.
        vector<Student*> roster;
        //Adds to owed
        double price;
        //Time the class is being held.
        string time;
        //Dates being held.
        string dates;
        //Location.
        string location;
        //Name of the camp.
        string camp_name;
    
    public:
        //Overload Constructor
        Camp(string name);
        //Mutators for all variables.
        void SetPrice(double cost);
        void SetTime(string hours);
        void SetDates(string week);
        void SetLocation(string site);
        void SetClassName(string name);
        //Print overview of class.
        void PrintClassOverview();
        //To add a student to the roster
        void AddStudent(string camper_first, string camper_last);
};

Camp::Camp(string name){
    camp_name = name;
};

void Camp::SetPrice(double cost){
    price = cost;
    return;
};

void Camp::SetTime(string hours){
    time = hours;
    return;
};

void Camp::SetDates(string week){
    dates = week;
    return;
};

void Camp::SetLocation(string site){
    location = site;
    return;
};

void Camp::SetClassName(string name){
    camp_name = name;
    return;
};

//Need to be able to search for a student's records.
void Camp::AddStudent(string camper_first, string camper_last){
    Student* camper = new Student*;
    camper.SetFirstName(camper_first);
    camper.SetLastName(camper_last);
};

void Camp::PrintClassOverview(){
    cout << "---------------------------------" << endl;
    cout << "Name: " << camp_name << endl
    cout << "---------------------------------" << endl;
    cout << "Location: " << location << endl;
    cout << "Dates: " << dates << endl;
    cout << "Time: " << time << endl;
    cout << "Price: $" << price << endl;
    
};


class Student{
    private:
        string student_first_name;
        string student_last_name;
        int student_age;
        string parent_name;
        string phone_number;
        string email;
        string emergency_contact_number;
        string allergies;
        double amount_owed;
        Student* next;
        
    public:
        //Constructor
        Student();
};

Student::Student(){
    next = NULL;
};

void Student::SetName(string camper_first, string camper_last){
    student_first_name = camper_first;
    student_last_name = camper_last;
    return;
};

string Student::GetFirstName(){
    return student_first_name;
};

string Student::GetLastName(){
    return student_last_name;
};

void Student::SetAge(int age){
    student_age = age;
    return;
};

int Student::GetAge(){
    return student_age;
};

void Student::SetParentName(string parent){
    parent_name = parentt;
    return;
};

string Student::GetParentName(){
    return parent_name;
};

void Student::SetPhoneNumber(string phone){
    phone_number = phone;
    return;
};

string Student::GetPhoneNumber(){
    return phone_number;
};

void Student::SetEmail(string email_address){
    email = email_address;
    return;
};

string Student::GetEmail(){
    return email;
};

void Student::SetEmergencyContact(string emergency){
    emergency_contact_number = emergency;
    return;
};

string Student::GetEmergencyContact(){
    return emergency_contact_number;
};

void Student::SetAllergies(string allergic){
    allergies = allergic;
    return;
};

string Student::GetAllergies(){
    return allergies;
};

void Student::SetAmountOwed(double price){
    amount_owed = amount_owed + price;
    return;
};

double Student::GetAmountOwed(){
    return amount_owed;
};

void 