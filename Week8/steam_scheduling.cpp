#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

/*
    Description: A scheduling program to keep track of classes
    as well as students enrolled in the classes.
    Kelsey Dimmick
    03.26.2018

*/

//Create a vector of classes? to access all?
/*
vector<Class> CreativeSteam;
CreativeSteam[i].f(x)name to get the information from the vector.
Need a separate f(x) to fill the vector of objects.
*/
//Need an operator overload to compare the 
//Prints the information to a file.

class Class {
    //Will use string stream to manipulate.
    private:
        //Name of the class being offered.
        string class_name_;
        //Class type.
        //Either School, Camps
        //Have print accordingly.
        string class_type_;
        //The date of the class being offered.
        //Tale care of multiple days?
        //make a vector vector<string> date;
        vector<string> date_;
        //Time of the classes.
        vector<string> time_;
        //Number of students enrolled in the class.
        int enrolled_;
        //Roster of the class.
        //Do a check to make sure in file.
        vector<string> roster;
        //Price daily of the class.
        double price_daily_;
        //Price monthly of the class.
        double price_monthly_;
        //For the location of the class.
        string location_;
        
    public:
        //Constructor.
        Class();
        
        //Set a new class.
        void SetClassName(string name);
        //To get the name of the class.
        string GetClassName();
        
        //To set the class type.
        void SetClassType(string type);
        //To get the class type.
        string GetClassType();
        
        //Setting the date for the class.
        void SetDate(string date);
        //To get the date for the class.
        string GetDate();
        
        //Setting the time for the class.
        void SetTime(string time);
        //To get the time for the class.
        string GetTime();
        
        //The number enrolled will be dictated by the vector created.
        void SetRoster(string student);
        
        //To set the daily price.
        void SetDailyPrice(double daily);
        //To get the daily price.
        double GetDailyPrice();
        
        //To set the monthly price.
        void SetMonthlyPrice(double monthly);
        //To get the monthly price.
        double GetMonthlyPrice();
        
        //To set the location of the class.
        void SetLocation(string location);
        //To get the location of the class.
        string GetLocation();
        
        /*
        For the whole object vector
        //To print to file.
        void PrintCamps();
        void PrintSchool();
        */
        //To print the information of the class.
        void PrintClassInfo();
};

int main() {
    //A vector of objects to hold all the classes being offered.
    vector<Class> creative_steam;
    //A vector of objects to hold all the students information.
    vector <NewStudent> students;
    
    //An int variable to hold the program's option.
    int option = 10;
    
    //A dummy variable to hold all string input.
    string input;
    //A dummy variable to hold extra string info.
    string info;
                
    //Dummy variable for the name of the class.
    string name;
    
    //A dummy variable to hold all integer input.
    int number;
    
    //A dummy variable to hold all double input.
    double price;
    
    //while (option != 0){
    //Will continue to prompt after each choice until the user enters a 0.
    cout << "Please choose an option: " << endl << endl;
    cout << "1. Create a new class." << endl;
    cout << "2. Access a class." << endl;
    cout << "3. To add a student to a class." << endl;
    cout << "4. Create a new student." << endl;
    cout << "5. Access student information." << endl;
    cout << "Enter 0 to quit."
    cin >> option;
    cout << endl;
    
    if (option == 1){
        //Want to fill the vector of objects with a new class object.
        Class newclass;
        
        cout << "Enter a class name: ";
        cin >> input;
        cout << endl;
        //Check to see if the same name is present in another class.
        for (int i = 0; i < creative_steam.size(); ++i){
            info = creative_steam(i).GetClassName();
            if (info == input){
                cout << "This class already exists." << endl;
                option = 0;
            }
        }
        newclass.SetClassName(input);
        cout << "Is it a school or camp class? (please enter school or camp): ";
        cin >> input;
        cout << endl;
        newclass.SetClassType(input);
        cout << "How many days will this class be going on for?: ";
        cin >> number;
        cout << endl;
        for (int i = 0; i < number; ++i){
            cout << "Enter a date for the class to be held: (00/00/0000)";
            cin >> input;
            cout << endl;
            newclass.SetDate(input);
            cout << "Enter a time the class will be from: (00:00-00:00)";
            cin >> input;
            cout << endl;
            newclass.SetTime(input);
        }
        
        cout << "Enter a daily price: $";
        cin >> price;
        cout << endl;
        newclass.SetDailyPrice(price);
        
        cout << "Enter a monthly price (if this is a camp this will be the weekly price): $";
        cin >> price;
        cout << endl;
        newclass.SetMonthlyPrice(price);
        
        cout << "Where will this class be held? (Enter: office if at the office): ";
        cin >> input;
        cout << endl;
        newclass.SetLocation(input);
        
        //To push_back onto the object vector.
        creative_steam.push_back(newclass);
        
        cout << "Your new class information has been created for: " << newclass.GetClassName() << endl << endl;
        
        cout << "Please choose another option or enter 0 to exit." << endl << endl;
        cout << "1. Create a new class." << endl;
        cout << "2. Access a class." << endl;
        cout << "3. To add a student to a class." << endl;
        cout << "4. Create a new student." << endl;
        cout << "5. Access student information." << endl;
        cout << "Enter 0 to quit."
        cin >> option;
        cout << endl;
        
    }
    if (option == 2){
        //Want to access a class in the creative_steam vector and modify it or get information.
        //Ask the user.
        cout << "Would you like to access class information or modify the information? (Enter access or modify): ";
        cin >> input;
        cout << endl;
        if (input == "access"){
            cout << "Enter a class you would like to access: ";
            cin >> info;
            cout << endl;
            
            for (int i = 0; i < creative_steam.size(); ++ i){
                name = creative_steam(i).GetClassName();
                if (name == info){
                    creative_steam(i).PrintClassInfo();
                    option = 0;
                }
            }
            cout << "Could not find any record of class." << endl;
            option = 0;
            
        }
        if (input == "modify"){
            cout << "Enter a class you would like to modify: ";
            cin >> info;
            cout << endl;
            for (int i = 0; i < creative_steam.size(); ++i){
                if (creative_steam(i) == info){
                    cout << "What would you like to modify?: " << endl << endl;
                    cout << "1. Name" << endl;
                    cout << "2. Date" << endl;
                    cout << "3. Time" << endl;
                    cout << "4. Daily Price" << endl;
                    cout << "5. Monthly Price" << endl;
                    cout << "6. Class Type" << endl;
                    cout << "7. Location" << endl;
                    cout << "8. Roster" << endl;
                    //Do not need to modify class size does so automatically with roster.
                    //cout << "9. Class Size" << endl;
                    cin >> number;
                    
                    string date;
                    
                    if (number == 1){
                        cout << "Enter a new name: ";
                        cin >> name;
                        cout << endl;
                        creative_steam(i).SetClassName(name);
                        cout << "The name has been changed to: " << creative_steam(i).GetClassName() << endl;
                        option = 0;
                    }
                    if (number == 2){
                        cout << "Would you like to enter a new date or erase an old date? (Enter new or erase): ";
                        cin >> name;
                        cout << endl;
                        if (name == "new"){
                            cout << "Enter a new date: (00/00/0000)";
                            cin >> date;
                            cout << endl;
                            creative_steam(i).SetDate(date);
                            cout << "The date " << creative_steam(i).GetDate() << " has been added to the " << creative_steam(i).GetClassName() << " class." endl;
                            option = 0;
                        }
                        if (name == "old"){
                            //Make the Set function run through the vector to look for same date and erase.
                            cout << "What date would you like to erase? (00/00/0000): ";
                            cin >> date;
                            cout << endl;
                            creative_steam(i).SetData(date);
                            cout << "The date " << date << " has been erased for the " << creative_steam(i).GetClassName() << " class." endl;
                            option = 0;
                        }
                    }
                    if (number == 3){
                        cout << "Enter a new time for the class to be held: (00:00)";
                        cin >> date;
                        cout << endl;
                        creative_steam(i).SetTime(date);
                        cout << "The new time for " << creative_steam(i).GetClassName() << "is: " << creative_steam(i).GetTime() << endl;
                        option = 0;
                    }
                    if (number == 4){
                        cout << "Enter a new daily price: $";
                        cin >> date;
                        cout << endl;
                        creative_steam(i).SetDailyPrice(date);
                        cout << "The new daily price for " << creative_steam(i).GetClassName() << " is: " << creative_steam(i).GetDailyPrice() << "." << endl;
                        option = 0;
                    }
                    if (number == 5){
                        cout << "Enter a new monthly price: $";
                        cin >> date;
                        cout << endl;
                        creative_steam(i).SetMonthlyPrice(date);
                        cout << "The new monthly price for " << creative_steam(i).GetClassName() << " is: " << creative_steam(i).GetMonthlyPrice() << "." << endl;
                        option = 0; 
                    }
                    if (number == 6){
                        cout << "Enter a new class type: (please enter school or camp)";
                        cin >> date;
                        cout << endl;
                        creative_steam(i).SetClassType(date);
                        cout << "The class type for " << creative_steam(i).GetClassName() << " is now: " << creative_steam(i).GetClassType() << "." << endl;
                        option = 0
                    }
                    if (number == 7){
                        cout << "Enter a new location were the class will be held: (Enter: office if at the office)";
                        cin >> date;
                        cout << endl;
                        creative_steam(i).SetLocation(date);
                        cout << "The " << creative_steam(i).GetClassName() << " is now being held at: " << creative_steam(i).GetLocation() << "." << endl;
                        option = 0;
                    }
                    if (number == 8){
                        cout << "Enter a first and last name of the student to be removed from the roster: ";
                        cin >> date;
                        cout << endl;
                        //Modify the roster set to be able to remove names as well.
                        
                        option = 0;
                        
                    }
                }
            }
            
            
        }
        
    }
    if (option == 3){
        //To add a student to an existing class.
        cout << "Enter a class to add a student to: ";
        cin >>
        cout << endl;
        cout << "Enter the student's name to add to the " << creative_steam(i).GetClassName() << " class: ";
        cin >>
        cout << endl;
        //Add name to vector.
    }
    if (option == 4){
        //Want to fill the vector of objects with a new student object.
        
    }
    if (option == 5){
        //Want to access a class in the students vector and modify it or get information.
        //Ask the user.
        
    }
    if (option == 0){
        
    }
    
    
    //}
}
/*
vector<NewStudent> students;

*/

//A class to create a new student.
class NewStudent {
    private:
        string student_first_name_;
        string student_last_name_;
        string parent_first_name;
        string parent_last_name_;
        string primary_phone_number_;
        string secondary_phone_number_;
        string email_address_;
        string postal_address_;
        char po_;
        string money_owed_;
        string money_paid_;
        
    public:
}