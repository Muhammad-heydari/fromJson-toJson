#include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <QJsonDocument>
#include <QJsonDocument>
#include "pointserializer.h"
#include "point.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (argc == 2){

        ifstream i {argv[1]};
        if (!i)
            {
                // Print an error and exit
                cout<< "Uh oh, ???.txt could not be opened for reading!\n";
                return 1;
            }


        std::string strInput;
        while (i)
            {
            std::string str;
            i >> str;
            strInput += str;
           }



        QString qstr = QString::fromStdString(strInput);
        QJsonDocument doc = QJsonDocument::fromJson(qstr.toUtf8());



        vector<Point> myvec=  PointSerialier::fromJson(doc);




        for (auto item: myvec){
            item.printpoint();
        }


        auto qdoc = PointSerialier::toJson(myvec);
        QString strJson(qdoc.toJson(QJsonDocument::Compact));
        ofstream o{"ddd.json"};


       o<<strJson.toStdString()<<endl;







    }

    return a.exec();
}
