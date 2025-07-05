#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "veclass.h"
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QVector<std::shared_ptr<Car>>& _cars, QVector<std::shared_ptr<Truck>>& _trucks ,QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QVector<std::shared_ptr<Car>>& cars;
    QVector<std::shared_ptr<Truck>>& trucks;
};
#endif // MAINWINDOW_H
