#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class FileWindow;
class SerialWindow;
class NetworkWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFileWindow();
    void openSerialWindow();
    void openNetworkWindow();
    void openFile();  // 打开文件的槽函数
    void plotGraph();
    void startTextTimer();

private:
    Ui::MainWindow *ui;
    FileWindow *fileWindowptr;
    SerialWindow *serialWindowptr;
    NetworkWindow *networkWindowptr;
};
#endif // MAINWINDOW_H
