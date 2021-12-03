#ifndef SCANNERGUI_H
#define SCANNERGUI_H

#include <QObject>

class ScannerGui : public QObject
{
    Q_OBJECT
public:
    explicit ScannerGui(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SCANNERGUI_H