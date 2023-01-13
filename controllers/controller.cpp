#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include <iostream>

#define TIME_STEP 32

using namespace webots;

int main() {
    Robot *robot = new Robot();

    DistanceSensor *sensor = robot->getDistanceSensor("ds");
    sensor->enable(TIME_STEP);

    while (robot->step(TIME_STEP) != -1) {
        std::cout << "Distance: " << sensor->getValue() << std::endl;
    }

    delete robot;
    return 0;
}