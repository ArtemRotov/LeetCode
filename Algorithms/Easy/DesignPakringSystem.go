/*
1603. Design Parking System
Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.

Implement the ParkingSystem class:

ParkingSystem(int big, int medium, int small) Initializes object of the ParkingSystem class. The number of slots for each parking space are given as part of the constructor.
bool addCar(int carType) Checks whether there is a parking space of carType for the car that wants to get into the parking lot. carType can be of three kinds: big, medium, or small, which are represented by 1, 2, and 3 respectively. A car can only park in a parking space of its carType. If there is no space available, return false, else park the car in that size space and return true.
*/


type ParkingSystem struct {
    m [3]int
}


func Constructor(big int, medium int, small int) ParkingSystem {
    p := ParkingSystem{m : [3]int{}}

    p.m[0] = big
    p.m[1] = medium
    p.m[2] = small

    return p
}


func (this *ParkingSystem) AddCar(carType int) bool {
    if this.m[carType-1] > 0 {
        this.m[carType-1]--
        return true
    }

    return false
}


/**
 * Your ParkingSystem object will be instantiated and called as such:
 * obj := Constructor(big, medium, small);
 * param_1 := obj.AddCar(carType);
 */
