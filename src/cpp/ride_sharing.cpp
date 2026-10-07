#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Ride {
private:
    string rideID;
    string pickupLocation;
    string dropoffLocation;
    double distance;

public:
    Ride(string id, string pickup, string dropoff, double miles)
        : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(miles) {}

    virtual ~Ride() = default;

    string getRideID() const { return rideID; }
    string getPickupLocation() const { return pickupLocation; }
    string getDropoffLocation() const { return dropoffLocation; }
    double getDistance() const { return distance; }

    virtual string getRideType() const = 0;
    virtual double fare() const = 0;

    virtual void rideDetails() const {
        cout << "Ride ID: " << rideID << '\n'
             << "Type: " << getRideType() << '\n'
             << "Pickup: " << pickupLocation << '\n'
             << "Dropoff: " << dropoffLocation << '\n'
             << "Distance: " << distance << " miles\n"
             << "Fare: $" << fixed << setprecision(2) << fare() << "\n";
    }
};

class StandardRide : public Ride {
public:
    StandardRide(string id, string pickup, string dropoff, double miles)
        : Ride(id, pickup, dropoff, miles) {}

    string getRideType() const override { return "Standard Ride"; }
    double fare() const override { return getDistance() * 2.00; }
};

class PremiumRide : public Ride {
public:
    PremiumRide(string id, string pickup, string dropoff, double miles)
        : Ride(id, pickup, dropoff, miles) {}

    string getRideType() const override { return "Premium Ride"; }
    double fare() const override { return getDistance() * 3.50; }
};

class Driver {
private:
    string driverID;
    string name;
    double rating;
    vector<shared_ptr<Ride>> assignedRides;  // Encapsulated collection

public:
    Driver(string id, string driverName, double driverRating)
        : driverID(id), name(driverName), rating(driverRating) {}

    void addRide(const shared_ptr<Ride>& ride) { assignedRides.push_back(ride); }

    void getDriverInfo() const {
        cout << "Driver ID: " << driverID << '\n'
             << "Name: " << name << '\n'
             << "Rating: " << rating << '\n'
             << "Completed Rides: " << assignedRides.size() << "\n";
    }
};

class Rider {
private:
    string riderID;
    string name;
    vector<shared_ptr<Ride>> requestedRides;

public:
    Rider(string id, string riderName) : riderID(id), name(riderName) {}

    void requestRide(const shared_ptr<Ride>& ride) { requestedRides.push_back(ride); }

    void viewRides() const {
        cout << "Rider ID: " << riderID << "\nName: " << name
             << "\nRequested Rides: " << requestedRides.size() << "\n";
        for (const auto& ride : requestedRides) {
            cout << "  " << ride->getRideID() << " - " << ride->getRideType()
                 << " - $" << fixed << setprecision(2) << ride->fare() << '\n';
        }
    }
};

int main() {
    cout << "========== RIDE SHARING SYSTEM ==========\n\n";

    vector<shared_ptr<Ride>> rides;
    rides.push_back(make_shared<StandardRide>("R101", "Downtown", "Airport", 12.0));
    rides.push_back(make_shared<PremiumRide>("R102", "Airport", "Hotel", 8.0));
    rides.push_back(make_shared<StandardRide>("R103", "University", "Downtown", 6.5));

    cout << "---------- Ride Details ----------\n";
    for (const auto& ride : rides) { // Polymorphism
        ride->rideDetails();
        cout << '\n';
    }

    Driver driver("D101", "Michael", 4.9);
    driver.addRide(rides[0]);
    driver.addRide(rides[1]);

    Rider rider("U101", "John");
    rider.requestRide(rides[0]);
    rider.requestRide(rides[1]);

    cout << "---------- Driver Information ----------\n";
    driver.getDriverInfo();

    cout << "\n---------- Rider Information ----------\n";
    rider.viewRides();

    cout << "\n---------- Polymorphism Demonstration ----------\n";
    for (const auto& ride : rides) {
        cout << ride->getRideType() << " (" << ride->getRideID()
             << ") Fare: $" << fixed << setprecision(2) << ride->fare() << '\n';
    }

    cout << "\nAll ride-sharing system operations completed successfully.\n";
    return 0;
}
