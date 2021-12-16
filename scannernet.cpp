#include <QCoreApplication>
#include <QAbstractSocket>
#include <QTcpSocket>

#include "scannernet.h"


ScannerNet::ScannerNet(QObject *parent) : QObject(parent)
{

}

QVector<bool> ScannerNet::doScan(QString hostname, QVector<int> ports)
{    
    QVector<bool> resp;

    QTcpSocket* socket = new QTcpSocket();

    for ( int i = 0; i < ports.size(); i++)
    {        
        socket->connectToHost(hostname, ports[i]);

        if (!socket->waitForConnected(1000)) {  //1000ms
            //qDebug("Port %d: Can not connect", port);
            resp.append(false);
        } else {
            //qDebug("Port %d: Connected !", port);
            resp.append(true);
            socket->disconnectFromHost();
        }
  }


  return resp;
}
