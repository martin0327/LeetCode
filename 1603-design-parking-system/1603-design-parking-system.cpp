class ParkingSystem {
public:
    vector<int> a;
    ParkingSystem(int x, int y, int z) {
        a = vector<int>(3);
        a[0] = x, a[1] = y, a[2] = z;
    }
    
    bool addCar(int x) {
        if (a[--x]) return a[x]--;
        else return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */