#include "databasehelp.h"

DatabaseHelp::DatabaseHelp()
{
     // excelHelp=new ExcelHelp;
}

//连接数据库
bool DatabaseHelp::connectToDB1(QString dbName)
{
    //QMessageBox::information(NULL,"DBName",dbName);
    dbConn = QSqlDatabase::addDatabase("QODBC",dbName);
    dbConn.setDatabaseName(QString("DRIVER={SQL SERVER};"
                                   "SERVER=%1;"
                                   "DATABASE=%2;"
                                   "UID=%3;"
                                   "PWD=%4;").arg(DB_SERVER_1)
                           .arg(dbName)
                           .arg(USER_NAME_1)
                           .arg(PASSWD_1));


    if (!dbConn.open())
    {
        //QMessageBox::information(NULL,"connect to db1 fail",dbConn.lastError().text());
        cout<<"connect to db1 fail,"<<dbConn.lastError().text().toStdString()<<endl;
        return false;
    }
    return true;
}

//关闭数据库
bool DatabaseHelp::closeDB()
{
    return true;
}

//得到某一数据库的数据
int DatabaseHelp::getQQData(QString dbName)
{
    //bool ret2=connectToDB2();
    bool ret=connectToDB1(dbName);
    if(!ret)
    {
        //QMessageBox::information(NULL,"connect result:",QString::number(ret));
        cout<<"connect to db1 fail"<<endl;
        return 0;
    }
    sQuery = (QSqlQuery)dbConn;
    QString sql="SELECT TOP 10 [Number]"
                      ",[QQNO]"
                      ",[QQTime]"
                      ",[IDno]"
                      ",replace(replace(QQMsg,char(13),''),char(10),'')"
                      ",[ToNO]"
                      ",[IP]"
                      ",[SessionID] "
                  "FROM [S_QQMsg] "
                  "WHERE "
                  "CHARINDEX('"+QString::fromLocal8Bit("海洛因")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("甲卡西酮")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("甲基甲卡西酮")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("氯胺酮")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("K粉")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("甲基苯丙胺")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("冰毒")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("亚甲二氧甲基丙胺")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("摇头丸")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("MDMA")+"',QQMsg)>0 OR "
                      // "CHARINDEX('"+QString::fromLocal8Bit("甲卡西酮")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("浴盐")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("丧尸药")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("长治筋")+"',QQMsg)>0 OR "
                      // "CHARINDEX('"+QString::fromLocal8Bit("甲基苯丙胺")+"',QQMsg)>0 OR "
                      // "CHARINDEX('"+QString::fromLocal8Bit("冰毒")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("甲基安非他明")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("溴代苯丙酮")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("麻黄碱")+"',QQMsg)>0 OR "
                      // "CHARINDEX('"+QString::fromLocal8Bit("氯胺酮")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("邻氯苯基环戊酮")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("邻酮")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("羟亚胺")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("盐酸羟亚胺")+"',QQMsg)>0 OR "
                      // "CHARINDEX('"+QString::fromLocal8Bit("邻氯苯基环戊酮")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("邻氯苯甲酰氯")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("邻氯苯腈")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("邻氯苯甲酸")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("甲胺")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("反应釜")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("粉")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("本科")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("四号")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("海海")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("小海")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("药")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("东西")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("4号")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("肉")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("猪肉")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("嘎嘎")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("牙签")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("钻石")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("象牙棒")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("大咖")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("老板")+"',QQMsg)>0 OR "
                      // "CHARINDEX('"+QString::fromLocal8Bit("冰毒")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("煲猪肉")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("葱")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("小马")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("马儿")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("籽籽")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("轮胎")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("溜麻")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("溜麻古")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("溜麻果")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("小麻")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("果子")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("糖果")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("一手")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("一条")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("一筒")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("调")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("瞪")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("踢")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("条")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("盎司")+"',QQMsg)>0 OR "
                      // "CHARINDEX('"+QString::fromLocal8Bit("氯胺酮")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("块")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("原货")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("普货")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("龙珠")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("打K")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("嗑药")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("打飞")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("踏板")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("追龙")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("蚂蚁上树")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("开天窗")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("飘")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("昏")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("打头")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("嗨")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("烫几口")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("哦咖")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("打针")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("溜冰")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("玩冰")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("搞几口")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("条子")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("KIN")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("吸管")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("还愿")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("还个愿")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("喂")+"',QQMsg)>0 OR "
                     "CHARINDEX('"+QString::fromLocal8Bit("窑口")+"',QQMsg)>0;";


    //QMessageBox::information(NULL,"sql statement:",sql);
    bool retExec=sQuery.exec(sql);

    if(!retExec)
    {
        //QMessageBox::information(NULL,"waring:","sql exec fail");
        return 0;
    }
   // QList<QQData> QQDataList;
    //****************************************************************************
    QFile *file=new QFile(dbName+".csv");
    if(!file->open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug()<<"file open fail";
        return 0;
    }
    QTextStream out(file);
    //输出标题
    out<<"QQTime"<<",";
    out<<"Name"<<",";
    out<<"IP"<<",";
    out<<"QQNO"<<",";
    out<<"QQMsg"<<",";
    out<<"ToNO"<<",";
    out<<"IDno"<<",";
    out<<"TYPE"<<",";
    out<<"\n";
    //****************************************************************************


    while(sQuery.next())
    {
       // QQData qqData;
        QString Number=sQuery.value(0).toString();
        QString QQNO=sQuery.value(1).toString();
        QString QQTime=sQuery.value(2).toString();
        QString IDno=sQuery.value(3).toString();
        QString QQMsg=sQuery.value(4).toString();QQMsg.replace("\n","");QQMsg.replace(",","");
        QString ToNO=sQuery.value(5).toString();
        QString IP=sQuery.value(6).toString();
        QString SessionID=sQuery.value(7).toString();
        QString TYPE;
        if((IDno.toInt()>=9000&IDno.toInt()<20000)||IDno.toInt()>=29000)
            TYPE="group";
        else
            TYPE="person";
        QString Name=getNameByNumber(Number);
        //QQDataList.push_back(qqData);
        //QMessageBox::information(NULL,"","Number :"+qqData.Number+",Name:"+qqData.Name);

        //直接输出到文件

        out<<QQTime<<",";
        out<<Name<<",";
        out<<IP<<",";
        out<<QQNO<<",";
        out<<QQMsg<<",";
        out<<ToNO<<",";
        out<<IDno<<",";
        out<<TYPE<<",";
        out<<"\n";


 }
    file->close();
    //输出到文件
   // excelHelp->exportToExcel(dbName,QQDataList);

    cout<<dbName.toStdString()<<" finished."<<endl;
    dbConn.close();
   // dbConn2.close();
    return 0;
}

//遍历数据库得到数据
void DatabaseHelp::loopGetQQData(int from,int to)
{
    connectToDB2();

    for(int i=from;i<=to;i++)
    {
        getQQData(QString(DB_PREFIX_NAME).append(QString::number(i)));
    }
    /*
    //5月
    for(int i=20170501;i<=20170531;i++)
    {
        getQQData(QString(DB_PREFIX_NAME).append(QString::number(i)));
    }
    //6月
    for(int i=20170601;i<=20170631;i++)
    {
        getQQData(QString(DB_PREFIX_NAME).append(QString::number(i)));
    }
    //7月
    for(int i=20170701;i<=20170731;i++)
    {
        getQQData(QString(DB_PREFIX_NAME).append(QString::number(i)));
    }
    //8月
    for(int i=20170801;i<=20170806;i++)
    {
        getQQData(QString(DB_PREFIX_NAME).append(QString::number(i)));
    }
    */
    dbConn2.close();
}


//连接数据库2
bool DatabaseHelp::connectToDB2()
{
    dbConn2= QSqlDatabase::addDatabase("QODBC","DB2");
    dbConn2.setDatabaseName(QString("DRIVER={SQL SERVER};"
                                   "SERVER=%1;"
                                   "DATABASE=%2;"
                                   "UID=%3;"
                                   "PWD=%4;").arg(DB_SERVER_2)
                           .arg(DB_NAME2)
                           .arg(USER_NAME_2)
                           .arg(PASSWD_2));
    if(!dbConn2.open())
    {
        //QMessageBox::information(NULL,"connect to db2 fail!","fail");
        cout<<"connect to db2 fail!"<<endl;
        return false;
    }
    return true;

}

//根据Number得到Name
QString DatabaseHelp::getNameByNumber(QString Number)
{

    if(!dbConn2.isOpen())  //连接中断则重连
    {
        if(!dbConn2.open())
        {
            //QMessageBox::information(NULL,"open db2 fail","Number is "+Number);
            cout<<"open db2 fail"<<"Number is "+Number.toStdString()<<endl;
            return "fail";
        }
    }
    query2=(QSqlQuery)dbConn2;
    bool ret=query2.exec("SELECT [Name] FROM [s_netbar] where Number = '"+Number+"'");
    if(!ret)
    {
        //QMessageBox::information(NULL,"get netbar fail !","Number is "+Number);
        return "fail";
    }
    while(query2.next())
    {
        QString Name=query2.value(0).toString();
        return Name;
    }
    return "";
}
