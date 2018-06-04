#include "properties.h"
#include "ui_properties.h"


properties::properties(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::properties)
{
    ui->setupUi(this);
    ui->LEikmax->setText("16");

}

properties::~properties()
{
    delete ui;
}

void properties::on_CHB_alternativeX_stateChanged(int arg1)
{

}

void properties::on_buttonBox_destroyed()
{

}
