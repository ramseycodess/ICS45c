#include <iostream>
#include "convert_knots.hpp"

using namespace std;

// Function definition
double knots_to_miles_per_minute(int knot) {
    double feet_per_hour = knot * 6076.0;
    double miles_per_hour = feet_per_hour / 5280.0;
    return miles_per_hour / 60.0;
}

int main() {
    int knots = 0;
    cout << "Enter integer speed in knots: ";
    cin >> knots;
    cout << "Speed in miles per minute is "
         << knots_to_miles_per_minute(knots)
         << endl;
    return 0;
}
