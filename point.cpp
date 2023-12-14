#include "point.h"
#include <iostream>

Point::Point(const std::string &name,const int x,const int y,const int z,const std::string color):
    _name(name),_x(x),_y(y),_z(z),_color(color)
{

}

Point::Point(QJsonObject qobj)
{
    _x = qobj.value("x").toInt();
    _y = qobj.value("y").toInt();
    _z = qobj.value("z").toInt();
    _name =qobj.value("name").toString().toStdString() ;
    _color =qobj.value("color").toString().toStdString() ;
}

void Point::printpoint()
{

        std::cout<<" name : "<<_name<<" x = "<<_x<<" y = "<<_y<<" z = "<<_z<<" color = "<<_color<<std::endl;

}

int Point::get_x()
{
    return _x;
}

int Point::get_y()
{
    return _y;
}

int Point::get_z()
{
    return _z;
}

std::string Point::get_name()
{
    return _name;
}

std::string Point::get_color()
{
    return _color;
}

QJsonObject Point::toJson()
{
    QJsonObject qjsonobj;

    qjsonobj.insert("x",_x);
    qjsonobj.insert("y",_y);

    return qjsonobj;

}
