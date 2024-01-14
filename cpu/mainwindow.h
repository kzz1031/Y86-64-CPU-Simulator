#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cpu.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void click();
    void on_next_stage_clicked();
    void start_clicked();


private:
    Ui::MainWindow *ui;
    cpu cpu;
};
#endif // MAINWINDOW_H
