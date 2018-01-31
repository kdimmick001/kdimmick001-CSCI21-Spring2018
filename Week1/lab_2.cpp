/*
 * Name        : lab_2.cpp
 * Author      : Kelsey Dimmick
 * Description : Using Arithmetic to finish the functions MakeChange() and
 *               LaunchHumanCannonball()
 * Sources     :
 */

// Please note the header above. You need to include the name of the file, the
// author, a description of the program and any sources used
#include "lab_2.h"


/*
 * Given an initial integer value (representing change to be given, such as in a
 * financial transaction), break the value down into the number of quarters,
 * dimes, nickels, and pennies that would be given as change.
 * @param int initial_value - The amount of change to be broken down in pennies.
 * @param int quarters  - The number of quarters that come out of initial_value
 * @param int dimes - The number of dimes that come out of initial_value,
 *                    after quarters have been taken out
 * @param int nickels - The number of nickels that come out of initial_value,
 *                      after quarters and dimes have been taken out
 * @param int pennies - The number of pennies that come out of initial_value,
 *                      after quarters, dimes, and nickels have been taken out
 */
void MakeChange(int initial_value, int &quarters, int &dimes, int &nickels,
                int &pennies) {
  // CODE HERE
  
  //Creating a variable to hold excess change after one of the coins are gathered.
  int extra;
  
  //A while function to continue taking from the initial value until the value of extra is 0.
  while (extra != 0){
    quarters = initial_value / 25; //the amount of quarters from the initial
    extra = initial_value % 25; //the amount left over after all the quarters are taken out
    dimes = extra / 10; //the amount of dimes from the left over change
    extra = extra % 10; //the amount left over after all the dimes are taken out
    nickels = extra / 5; //the amound of nickels from the extra
    extra = extra % 5; //the amount left over after all the nickles are taken out
    pennies = extra; //that left over amount is then made into pennies.
}

cout << "From your initial value you will recieve: " << endl;
cout << "Quarters: " << quarters << endl;
cout << "Dimes: " << dimes << endl;
cout << "Nickels: " << nickels << endl;
cout << "Pennies: " << pennies << endl;

};

/*
 * Computes the horizontal distance traveled by a human cannonball given an
 * initial velocity and launch angle. Simplified -- does not account for many
 * factors that affect projectile motion.
 * @param double initial_velocity - Represents the initial velocity of the
 *                                  human cannonball in meters/second
 * @param double launch_angle -  Represents the launch angle of the human
 *                               cannonball in degrees
 * @return double  - Represents the horizontal distance the human cannonball
 *                   will travel
 */
double LaunchHumanCannonball(double initial_velocity, double launch_angle) {
    
    
  // (1) Convert launch_angle from degrees to radians
   double radian_angle = launch_angle * (kPI/180);
  // CODE HERE

  // (2) Compute final horizontal/x velocity
  double x_velocity = initial_velocity * cos(radian_angle);
  // CODE HERE

  // (3) Compute final vertical/y velocity
  double y_velocity = initial_velocity * sin(radian_angle) * -1;
  // CODE HERE

  // (4) Compute time of flight
  double flight_time = (y_velocity) * 2 / -9.8;
  // CODE HERE

  // (5) Compute horizontal/x distance traveled
  double x_distance = x_velocity * flight_time;
  // CODE HERE

  // (6) Return horizontal/x distance
  // CODE HERE
  
  return x_distance;
};
