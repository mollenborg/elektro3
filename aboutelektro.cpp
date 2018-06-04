#include "aboutelektro.h"
#include "ui_aboutelektro.h"

aboutElektro::aboutElektro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutElektro)
{
    ui->setupUi(this);
}

aboutElektro::~aboutElektro()
{
    delete ui;
}
