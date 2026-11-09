
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Get a valid distance in miles
double getDistance() {
    double distance;

    while (true) {
        cout << "Enter distance travelled in miles: ";

        if (cin >> distance && distance >= 0) {
            return distance;
        }

        cout << "Invalid distance. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Get a valid fuel type
string getFuelType() {
    string fuel;

    while (true) {
        cout << "Enter fuel type (petrol or diesel): ";
        cin >> fuel;

        if (fuel == "petrol" || fuel == "diesel") {
            return fuel;
        }

        cout << "Invalid fuel type. Try again.\n";
    }
}

// Calculate CO2 emissions
double calculateEmissions(double distance, string fuel) {
    double litresUsed = (distance / 100) * 9.66;
    double emissions;

    if (fuel == "diesel") {
        emissions = litresUsed * 2.68;
    } else {
        emissions = litresUsed * 2.31;
    }

    return emissions;
}

int main() {
    double distance = getDistance();
    string fuel = getFuelType();

    double result = calculateEmissions(distance, fuel);

    cout << fixed << setprecision(2);
    cout << "Estimated CO2 emissions: "
         << result << " kg\n";

    return 0;
}


