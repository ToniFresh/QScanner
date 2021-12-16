#include <QDebug>
#include <QVector>

#include "scanner.h"
#include "scannernet.h"

Scanner::Scanner(QWidget *parent) :
    QWidget(parent)
{
    m_scan = new ScannerNet;
    setupUi(this);
}

void Scanner::on_startButton_clicked()
{    
    resultWindow->setText("");
    m_ports.clear();

    QStringList portlist = portEntry->text().split(',');
    for(int i = 0; i < portlist.size(); i++) m_ports.append(portlist[i].toUInt());

    m_resp = ScannerNet::doScan(hostnameEntry->text(), m_ports);


    if(m_ports[0] != 0)Scanner::ScannerOutput();
}

void Scanner::ScannerOutput()
{    
    QString output;

    for(int i = 0; i < m_resp.size(); i ++)
    {
        if(m_resp[i] == true)
        {
            output = "Port "+ QString::number(m_ports[i]) + ": Connected !";
            resultWindow->setTextColor("green");
        }

        else
        {
            output = "Port " + QString::number(m_ports[i]) + ": not connected !";
            resultWindow->setTextColor("red");
        }

        resultWindow->append(output);

    }
}
