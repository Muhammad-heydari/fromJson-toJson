
#include <fstream>
#include <iostream>
#include <QJsonDocument>
#include "pointserializer.h"
#include <vector>
#include <QJsonArray>
#include <QJsonObject>








QJsonDocument PointSerialier::toJson(std::vector<Point> points)
{

    QJsonArray qjsonarr;
    for(auto item : points){
        QJsonObject qjsonobj;
        qjsonobj.insert("name",QString::fromStdString(item.get_name()));
        qjsonobj.insert("x",item.get_x());
        qjsonobj.insert("y",item.get_y());
        qjsonobj.insert("z",item.get_z());
        qjsonobj.insert("color",QString::fromStdString(item.get_color()));

        qjsonarr.push_back(qjsonobj);

}


    QJsonDocument doc(qjsonarr);
    return doc;
}

vector<Point> PointSerialier::fromJson(QJsonDocument doc)
{
    QJsonArray jsonarray = doc.array();

    vector<Point> myvec;
    int end = jsonarray.size();
    for(int i = 0;i!=end;i++){
        QJsonObject qobj;
        qobj = jsonarray[i].toObject();
        int x = qobj.value("x").toInt();
        int y = qobj.value("y").toInt();
        int z = qobj.value("z").toInt();
        QString qname =qobj.value("name").toString() ;
        std::string name = qname.toStdString();
        QString qcolor =qobj.value("color").toString() ;
        std::string color = qcolor.toStdString();

        myvec.push_back(Point(name,x,y,z,color));


    }










        return myvec;
}
