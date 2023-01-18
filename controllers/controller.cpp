#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Lidar.hpp>
#include <string.h>
#include <iostream>
#include <fstream>

#define TIME_STEP 32

using namespace webots;
using namespace std;

int main() {
    Robot *robot = new Robot();

    Lidar *lidar = robot->getLidar("Hokuyo URG-04LX-UG01");
    lidar->enable(TIME_STEP);
    lidar->enablePointCloud();

    while (robot->step(TIME_STEP) != -1) {
        const LidarPoint *points = lidar->getPointCloud();


    }

    delete robot;
    return 0;
}

void outputPointCloud(Lidar *lidar) {
    const string filename = "point_cloud.csv";

    ofstream file(filename);

    if (file.is_open()) {
        const LidarPoint *points = lidar->getPointCloud();

        for (int i = 0; i < lidar->getNumberOfPoints(); i++) {
            file << points[i].x << "," << points[i].y << "," << points[i].z << endl;
        }

        file.close();
    }
}