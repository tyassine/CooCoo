#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slot1();
    void slot2();
    void slot3();
    void slot4();
    void slot5();
    void slot6();
    void slot7();
    void slot8();
    void slot9();
    void slot0();
   // void on_virguleBouton_clicked();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
