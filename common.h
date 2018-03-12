#ifndef COMMON_H
#define COMMON_H

#endif // COMMON_H
#include <QDateTime>
struct QQData
{
   QDateTime QQTime;
   QString Number;
   QString Name;    //需要根据Number 查出
   QString IP;
   QString QQNO;
   QString QQMsg;
   QString ToNO;
   QString IDno;
   QString TYPE;   //根据IDno判断 IDno>9000 and IDno<20000 or IDno >29000 为群，否则为私人号

   QString SessionID;
};
