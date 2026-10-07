Object subclass: #Ride
    instanceVariableNames: 'rideID pickupLocation dropoffLocation distance'
    classVariableNames: ''
    package: 'RideSharing'.

Ride >> initializeID: anID pickup: aPickup dropoff: aDropoff distance: miles
    rideID := anID.
    pickupLocation := aPickup.
    dropoffLocation := aDropoff.
    distance := miles.
    ^ self

Ride >> rideID
    ^ rideID

Ride >> distance
    ^ distance

Ride >> fare
    self subclassResponsibility

Ride >> rideType
    self subclassResponsibility

Ride >> rideDetails
    Transcript
        show: 'Ride ID: ', rideID; cr;
        show: 'Type: ', self rideType; cr;
        show: 'Pickup: ', pickupLocation; cr;
        show: 'Dropoff: ', dropoffLocation; cr;
        show: 'Distance: ', distance printString, ' miles'; cr;
        show: 'Fare: $', self fare printString; cr.

Ride subclass: #StandardRide
    instanceVariableNames: ''
    classVariableNames: ''
    package: 'RideSharing'.

StandardRide >> fare
    ^ self distance * 2.0

StandardRide >> rideType
    ^ 'Standard Ride'

Ride subclass: #PremiumRide
    instanceVariableNames: ''
    classVariableNames: ''
    package: 'RideSharing'.

PremiumRide >> fare
    ^ self distance * 3.5

PremiumRide >> rideType
    ^ 'Premium Ride'

Object subclass: #Driver
    instanceVariableNames: 'driverID name rating assignedRides'
    classVariableNames: ''
    package: 'RideSharing'.

Driver >> initializeID: anID name: aName rating: aRating
    driverID := anID.
    name := aName.
    rating := aRating.
    assignedRides := OrderedCollection new.
    ^ self

Driver >> addRide: aRide
    assignedRides add: aRide

Driver >> getDriverInfo
    Transcript
        show: 'Driver ID: ', driverID; cr;
        show: 'Name: ', name; cr;
        show: 'Rating: ', rating printString; cr;
        show: 'Completed Rides: ', assignedRides size printString; cr.

Object subclass: #Rider
    instanceVariableNames: 'riderID name requestedRides'
    classVariableNames: ''
    package: 'RideSharing'.

Rider >> initializeID: anID name: aName
    riderID := anID.
    name := aName.
    requestedRides := OrderedCollection new.
    ^ self

Rider >> requestRide: aRide
    requestedRides add: aRide

Rider >> viewRides
    Transcript
        show: 'Rider ID: ', riderID; cr;
        show: 'Name: ', name; cr;
        show: 'Requested Rides: ', requestedRides size printString; cr.
    requestedRides do: [ :each |
        Transcript
            show: '  ', each rideID, ' - ', each rideType,
            ' - $', each fare printString; cr ].
