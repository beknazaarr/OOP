#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
    void display() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }
    Time add(const Time& t) const {
        int totalSeconds = seconds + t.seconds;
        int totalMinutes = minutes + t.minutes + totalSeconds / 60;
        int totalHours = hours + t.hours + totalMinutes / 60;
        return Time(totalHours % 24, totalMinutes % 60, totalSeconds % 60);
    }
};

int main() {
    Time t1(11, 59, 59), t2(0, 0, 1), t3;
    t3 = t1.add(t2);
    t3.display();
    return 0;
}