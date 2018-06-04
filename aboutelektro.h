#ifndef ABOUTELEKTRO_H
#define ABOUTELEKTRO_H

#include <QDialog>

namespace Ui {
class aboutElektro;
}

class aboutElektro : public QDialog
{
    Q_OBJECT

public:
    explicit aboutElektro(QWidget *parent = 0);
    ~aboutElektro();

private:
    Ui::aboutElektro *ui;
};

#endif // ABOUTELEKTRO_H
