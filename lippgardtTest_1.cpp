#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

struct Manipulator {
    std::pair<double, double> currentPos;
    double length;
    std::vector<std::pair<double, double>> passedPoits;

    Manipulator(std::pair<double, double> setCurrentPos, double setLength) : currentPos(setCurrentPos), length(setLength){}

    void addPoint(std::pair<double, double>& newPoint) {
        passedPoits.push_back(newPoint);
    }

    void outPoints() {
        for (int i = 0; i < passedPoits.size(); i++) {
            std::cout << passedPoits[i].first << " " << passedPoits[i].second << " ";
        }
        std::cout << "\n";
    }

    void setCurrentPoint(std::pair<double, double> setPos) {
        currentPos = setPos;
    }

    void setCurrentPoint(double setX, double setY) {
        currentPos = {setX, setY};
    }
};

double getDistance(Manipulator& subjectManip, std::pair<double, double>& targetPoint) {
    return sqrt(pow(targetPoint.first - subjectManip.currentPos.first, 2) +
        pow(targetPoint.second - subjectManip.currentPos.second, 2));
}

void checkPoint(Manipulator& firstManip, Manipulator& secondManip, std::pair<double, double> targetPoint) {
    if (getDistance(firstManip, targetPoint) < getDistance(secondManip, targetPoint)) {
        firstManip.addPoint(targetPoint);
        firstManip.setCurrentPoint(targetPoint);
    }
    else {
        secondManip.addPoint(targetPoint);
        secondManip.setCurrentPoint(targetPoint);
    }
}

int main()
{
    Manipulator firstManip({ 0, 0 }, 4);
    Manipulator secondManip({ 2, 1 }, 3);

    std::vector<std::pair<double, double>> targetPoints = { {1, 3}, {2, 1.41}, {0.2, -7}, {-5, -1}, {0, 9} };

    for (auto i : targetPoints) {
        checkPoint(firstManip, secondManip, i);
    }

    firstManip.outPoints();
    secondManip.outPoints();
}
