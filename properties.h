#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QDialog>


namespace Ui {
class properties;
}

class properties : public QDialog
{
    Q_OBJECT

public:
    explicit properties(QWidget *parent = 0);
    ~properties();

private slots:
    void on_CHB_alternativeX_stateChanged(int arg1);

    void on_buttonBox_destroyed();

private:
    Ui::properties *ui;

};

#endif // PROPERTIES_H
