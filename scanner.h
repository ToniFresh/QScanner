#ifndef SCANNER_H
#define SCANNER_H


#include "ui_scanner.h"
#include "scannernet.h"

class Scanner : public QWidget, private Ui::Scanner
{
    Q_OBJECT

public:
    explicit Scanner(QWidget *parent = nullptr);
    void ScannerOutput();
private slots:
    void on_startButton_clicked();
private:
    ScannerNet* m_scan;
    QVector<int> m_ports;
    QVector<bool> m_resp;
};

#endif // SCANNER_H
