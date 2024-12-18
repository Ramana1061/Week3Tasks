#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

class VehicleData {
public:
    int speed;             // Speed in km/h
    float fuelLevel;       // Fuel level in percentage (0-100)
    int engineTemperature; // Engine temperature in Celsius

    VehicleData() : speed(0), fuelLevel(100.0), engineTemperature(90) {}

    void updateData() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> speedDist(0, 220); // Speed: 0 to 220 km/h
        uniform_int_distribution<> tempDist(80, 120); // Temperature: 80 to 120°C
        uniform_real_distribution<> fuelDist(0.0, 100.0); // Fuel: 0 to 100%

        speed = speedDist(gen);
        engineTemperature = tempDist(gen);
        fuelLevel = fuelDist(gen);
    }
};

class Display {
public:
    void showData(const VehicleData& data) {
        system("clear");  // For Linux/Unix. Use "cls" for Windows to clear the console.
        cout << "Vehicle Data Display\n";
        cout << "---------------------\n";
        cout << "Speed: " << data.speed << " km/h\n";
        cout << "Fuel: " << fixed << setprecision(1) << data.fuelLevel << " %\n";
        cout << "Engine Temp: " << data.engineTemperature << " °C\n";
        displayWarnings(data);
    }

private:
    void displayWarnings(const VehicleData& data) {
        if (data.engineTemperature > 100) {
            cout << "\n*** Warning: Engine temperature is too high! ***\n";
        }
        if (data.fuelLevel < 10) {
            cout << "\n*** Warning: Fuel level is critically low! ***\n";
        }
    }
};

void updateVehicleData(VehicleData& data) {
    while (true) {
        data.updateData();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void displayVehicleData(Display& display, VehicleData& data) {
    while (true) {
        display.showData(data);
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    VehicleData vehicleData;
    Display display;

    thread updateThread(updateVehicleData, ref(vehicleData));
    thread displayThread(displayVehicleData, ref(display), ref(vehicleData));

    updateThread.join();
    displayThread.join();

    return 0;
}
