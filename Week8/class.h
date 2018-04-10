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
        vector<NewStudent> roster_;
        //Price daily of the class.
        double price_daily_;
        //Price monthly of the class.
        double price_monthly_;
        //For the location of the class.
        string location_;
        
    public:
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
        void SetRoster(NewStudent &student);
        
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