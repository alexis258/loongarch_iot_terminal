#ifndef WINDOW5_H
#define WINDOW5_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class window5;
}

class window5 : public QWidget
{
    Q_OBJECT

public:
    explicit window5(QWidget *parent = nullptr);
    ~window5();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::window5 *ui;
};

#endif // WINDOW5_H
