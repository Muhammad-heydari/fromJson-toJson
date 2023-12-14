#ifndef POINT_H
#define POINT_H

#include <string>
#include <QJsonObject>
class Point
{
public:
    Point(const std::string &name,const int x,const int y,const int z,const std::string color);
    Point(QJsonObject qobj);
    void printpoint();
    int get_x();
    int get_y();
    int get_z();
    std::string get_name();
    std::string get_color();
    QJsonObject toJson();


private:
    std::string _name;
    int _x;
    int _y;
    int _z;
    std::string _color;

};

#endif // POINT_H
