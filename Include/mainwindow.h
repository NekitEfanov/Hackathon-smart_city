#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <loadingwidget.h>
#include <greetingwidget.h>
#include <nadyadialog1widget.h>
#include <nadyadialog2widget.h>
#include <mainmenuwidget.h>

#include <memory>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void start();

private slots:
    void on_start_button_clicked();
    void nadya_dialog1_button_clicked();
    void nadya_dialog2_button_clicked();
    void loading_screen_was_shown();

private:
    Ui::MainWindow *ui;

    std::shared_ptr<LoadingWidget> loading_widget;
    std::shared_ptr<GreetingWidget> greeting_widget;
    std::shared_ptr<NadyaDialog1Widget> nadya_dialog1_widget;
    std::shared_ptr<NadyaDialog2Widget> nadya_dialog2_widget;
    std::shared_ptr<MainMenuWidget> main_menu_widget;

};
#endif // MAINWINDOW_H
