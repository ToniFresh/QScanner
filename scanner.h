#ifndef SCANNER_H
#define SCANNER_H

#include "ui_scanner.h"

class Scanner : public QWidget, private Ui::Scanner
{
    Q_OBJECT

public:
    explicit Scanner(QWidget *parent = nullptr);
private slots:
    void on_startButton_clicked();
};

#endif // SCANNER_H
