
    //To set the name of the class.
    void Class::SetClassName(string name){
        class_name_ = name;
        
        return;
    };
    //To get the name of the class.
    string Class::GetClassName(){
        return class_name_;
    };
    //To set the class type.
    void Class::SetClassType(string type){
        class_type_ = type;
        return;
    };
    //To get the class type.
    string Class::GetClassType(){
        return class_type_;  
    };
    //To set the date for the class.
    void Class::SetDate(string date){
        date_.push_back(date);
        return;
    };
    //To get the date for the class.
    string Class::GetDate(){
        return date_.back();
    };
    //To set the time for the class.
    void Class::SetTime(string time){
        time_.push_back(time);
        return;
    };
    //To get the time for the class.
    string Class::GetTime(){
        return time_.back();
    };
    //To add to the roster and increase the enrollment number.
    void Class::SetRoster(NewStudent &student){
        roster_.push_back(student);
        enrolled_ = enrolled_ + 1;
        return;
    };
    //To set the daily price.
    void Class::SetDailyPrice(double daily){
        price_daily_ = daily;
        return;
    };
    //To get the daily price.
    double Class::GetDailyPrice(){
        return price_daily_;
    };
    //To set the monthly price.
    void Class::SetMonthlyPrice(double monthly){
        price_monthly_ = monthly;
        return;
    };
    //To get the monthly price.
    double Class::GetMonthlyPrice(){
        return price_monthly_;
    };
    //To set the location of the class.
    void Class::SetLocation(string location){
        location_ = location;
        return;
    };
    //To get the location of the class.
    string Class::GetLocation(){
        return location_;
    };
    //To print all the class info.
    void Class::PrintClassInfo(){
        
    };