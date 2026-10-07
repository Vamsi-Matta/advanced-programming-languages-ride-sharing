# advanced-programming-languages-ride-sharing

# Ride Sharing Application – Pharo Smalltalk

## Overview

This project is a Ride Sharing application developed using **Pharo Smalltalk**. The purpose of the project is to demonstrate object-oriented programming concepts such as classes, inheritance, instance variables, methods, collections, and polymorphism.

The application models a basic ride-sharing system with riders, drivers, and different ride types.

## Classes

The project contains the following main classes:

### Ride
Represents the base ride information.

Instance variables include:
- rideID
- pickupLocation
- dropoffLocation
- distance
- fare

### StandardRide
A subclass of `Ride` representing a standard ride.

The fare is calculated based on the ride distance.

### PremiumRide
A subclass of `Ride` representing a premium ride.

The premium ride uses a higher fare rate than the standard ride.

### Rider
Represents a customer requesting rides.

Instance variables include:
- riderID
- name
- requestedRides

The `requestedRides` collection stores rides requested by the rider.

### Driver
Represents a driver in the ride-sharing system.

Instance variables include:
- driverID
- name
- rating
- assignedRides

The `assignedRides` collection stores rides assigned to the driver.

## Key Features

- Creates riders and drivers
- Creates standard and premium rides
- Stores pickup and drop-off locations
- Stores ride distance
- Calculates fares using polymorphic `calculateFare` methods
- Maintains requested rides for riders
- Maintains assigned rides for drivers
- Demonstrates inheritance between `Ride`, `StandardRide`, and `PremiumRide`
- Uses `OrderedCollection` for ride management

## Fare Calculation

The application demonstrates polymorphism by implementing `calculateFare` differently for each ride type.

Example with a distance of 10:

- Standard Ride Fare: **20**
- Premium Ride Fare: **30**

Each subclass responds to the same `calculateFare` message while providing its own implementation.

## Testing

The application was tested using the Pharo Playground.

Testing included:

- Creating Rider objects
- Creating Driver objects
- Creating StandardRide objects
- Creating PremiumRide objects
- Adding rides to `requestedRides`
- Adding rides to `assignedRides`
- Verifying rider and driver information
- Verifying ride information
- Testing StandardRide fare calculation
- Testing PremiumRide fare calculation

The test results confirmed that the objects, collections, inheritance, and fare calculations function correctly.

## Technologies Used

- Pharo
- Smalltalk
- Object-Oriented Programming

## Screenshots

The `screenshots` folder contains evidence of the implementation and successful testing of the application in Pharo.

## Author

**Vamsi Matta**  
University of the Cumberlands  
Advanced Programming Languages