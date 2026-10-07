Transcript clear.
Transcript show: '========== RIDE SHARING SYSTEM =========='; cr; cr.

standard := StandardRide new
    initializeID: 'R101' pickup: 'Downtown' dropoff: 'Airport' distance: 12.
premium := PremiumRide new
    initializeID: 'R102' pickup: 'Airport' dropoff: 'Hotel' distance: 8.
standard2 := StandardRide new
    initializeID: 'R103' pickup: 'University' dropoff: 'Downtown' distance: 6.5.

rides := OrderedCollection with: standard with: premium with: standard2.

Transcript show: '---------- Ride Details ----------'; cr.
rides do: [ :ride |
    ride rideDetails.
    Transcript cr ].

driver := Driver new initializeID: 'D101' name: 'Michael' rating: 4.9.
driver addRide: standard.
driver addRide: premium.

rider := Rider new initializeID: 'U101' name: 'John'.
rider requestRide: standard.
rider requestRide: premium.

Transcript show: '---------- Driver Information ----------'; cr.
driver getDriverInfo.

Transcript cr; show: '---------- Rider Information ----------'; cr.
rider viewRides.

Transcript cr; show: '---------- Polymorphism Demonstration ----------'; cr.
rides do: [ :ride |
    Transcript
        show: ride rideType, ' (', ride rideID, ') Fare: $',
        ride fare printString; cr ].

Transcript cr; show: 'All ride-sharing system operations completed successfully.'; cr.
