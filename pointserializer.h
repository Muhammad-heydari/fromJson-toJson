#ifndef POINTSERIALIZER_H
#define POINTSERIALIZER_H

#include <string>
#include <vector>
#include <QJsonDocument>
#include <vector>
#include "point.h"
using namespace std;
class PointSerialier{
public:
static QJsonDocument toJson(std::vector<Point> points);
static vector<Point> fromJson(QJsonDocument doc);
};

#endif // POINTSERIALIZER_H
