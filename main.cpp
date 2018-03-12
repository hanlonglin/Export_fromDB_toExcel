#include <QCoreApplication>
#include "databasehelp.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string from,to;
    cout<<"input from number："<<endl;
    cin>>from;
    cout<<"input to number :"<<endl;
    cin>>to;

    cout<<"start export data..."<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    DatabaseHelp DBHelp;
    DBHelp.loopGetQQData(QString::fromStdString(from).toInt(),QString::fromStdString(to).toInt());
    cout<<"all finished"<<endl;
    return a.exec();
}
