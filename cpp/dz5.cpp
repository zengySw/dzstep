#include <iostream>
#include <cctype>

using namespace std;

class elevator {
private:
    const int lowest = 1;
    const int highest;
    bool status;
    int FloorRightNow;

public:
    elevator() : highest(1), status(false), FloorRightNow(1) {}

    elevator(int higherFloor, bool works, int floorRN)
        : highest(higherFloor), status(works), FloorRightNow(floorRN) {}

    void turn_power(bool wait_for_checking) {
        status = wait_for_checking;
        cout << "Elevator power is now " << (status ? "ON" : "OFF") << endl;
    }

    bool is_on() const {
        return status;
    }

    int current_floor() const {
        return FloorRightNow;
    }

    void call_elevator() {
        if (!status) {
            cout << "Elevator is OFF. Turn it ON first.\n";
            return;
        }

        int temp;
        cout << "Enter floor to call elevator to (1–" << highest << "): ";
        cin >> temp;
        if (temp < lowest || temp > highest) {
            cout << "Invalid floor.\n";
            return;
        }
        FloorRightNow = temp;
        cout << "Elevator moved to floor " << FloorRightNow << endl;
    }
};

int main() {
    int temp, floor, floorrn;
    bool stat;
    char a;

    cout << "1. Set highest floor (custom)\n2. Use defaults\n";
    cin >> temp;

    elevator lift = (temp == 1)
                        ? (
                              cout << "Enter highest floor, current floor, and status (y/n): ",
                              cin >> floor >> floorrn >> a,
                              elevator(floor, tolower(a) == 'y', floorrn)
                              )
                        : elevator();

    while (true) {
        cout << "\nElevator Menu:\n";
        cout << "1. Call elevator\n";
        cout << "2. Turn power ON/OFF\n";
        cout << "3. Show status\n";
        cout << "4. Show current floor\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> temp;

        switch (temp) {
        case 1:
            lift.call_elevator();
            break;
        case 2:
            cout << "Turn power ON (y) or OFF (n): ";
            cin >> a;
            lift.turn_power(tolower(a) == 'y');
            break;
        case 3:
            cout << "Elevator is " << (lift.is_on() ? "ON" : "OFF") << endl;
            break;
        case 4:
            cout << "Current floor: " << lift.current_floor() << endl;
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid option.\n";
        }
    }
}
