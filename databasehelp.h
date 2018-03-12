#ifndef DATABASEHELP_H
#define DATABASEHELP_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTime>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <thread>

using namespace std;


//定义数据库的基本信息
#define DB_SERVER_1            "180.104.100.105,7001"
//#define DB_SERVER_1            "127.0.0.1,7001"
#define USER_NAME_1            "sa"
#define PASSWD_1               "XZYKTXB2007"
#define DB_PREFIX_NAME         "S_QQmsg"


#define DB_SERVER_2            "180.104.100.100,7001"
#define USER_NAME_2            "sa"
#define PASSWD_2               "XZYKTXB2007"
#define DB_NAME2               "netbar"

class DatabaseHelp
{
public:
    DatabaseHelp();

    //连接数据库
    bool connectToDB1(QString dbName);

    //关闭数据库
    bool closeDB();

    //得到数据
    int getQQData(QString dbName);

    //遍历数据库得到数据
    void loopGetQQData(int from ,int to );


    //连接DB2
    bool connectToDB2();

    //根据Number得到Name
    QString getNameByNumber(QString Number);

private:
    //属性
        QSqlDatabase dbConn;
        QSqlQuery sQuery;

        //得到的所有数据
        //QList<QQData> QQDataList;

      //
         QSqlDatabase dbConn2;
         QSqlQuery query2;

         //ExcelHelp *excelHelp;

};

#endif // DATABASEHELP_H
