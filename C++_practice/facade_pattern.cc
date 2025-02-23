#include <iostream>
#include <vector>
#include <string>  
using namespace std;

class Engine {
    public:
        void Start(){
            cout << "Engine started" << endl;
        }
        void Stop(){
            cout << "Engine stopped" << endl;
        }

};

class Lights {
    public:
        void TurnOn(){
            cout << "Lights on" << endl;
        }
        void TurnOff(){
            cout << "Lights off" << endl;
        }
};

class Car {
    private:
        Engine engine;
        Lights lights;

    public:
        void StartCar(){
            engine.Start();
            lights.TurnOn();

            cout << "Car is ready to drive" << endl;
        }

        void StopCar(){
            lights.TurnOff();
            engine.Stop();

            cout << "Car has stopped" << endl;
        }
};

int main(){
    Car car;

    car.StartCar();
    car.StopCar();

    return 0;
}