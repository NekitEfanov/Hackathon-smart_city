#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std::chrono_literals;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);
    this->setWindowTitle("Spectry");
}

void MainWindow::start()
{
    loading_widget.reset(new LoadingWidget());
    ui->gridLayout->replaceWidget(ui->widget, loading_widget.get());
    loading_widget->show();

//Initialization Widgets
    greeting_widget.reset(new GreetingWidget());
    nadya_dialog1_widget.reset(new NadyaDialog1Widget());
    nadya_dialog2_widget.reset(new NadyaDialog2Widget());
    main_menu_widget.reset(new MainMenuWidget());

    connect(loading_widget.get(),
            &LoadingWidget::loading_is_complete_signal,
            this,
            &MainWindow::loading_screen_was_shown);

    connect(greeting_widget.get(),
            &GreetingWidget::start_button_clicked,
            this,
            &MainWindow::on_start_button_clicked);

    connect(nadya_dialog1_widget.get(),
            &NadyaDialog1Widget::button_clicked,
            this,
            &MainWindow::nadya_dialog1_button_clicked);

    connect(nadya_dialog2_widget.get(),
            &NadyaDialog2Widget::button_clicked,
            this,
            &MainWindow::nadya_dialog2_button_clicked);
}

void MainWindow::loading_screen_was_shown()
{
    loading_widget->th->join();
    delete loading_widget->th;

    ui->gridLayout->replaceWidget(loading_widget.get(), greeting_widget.get());
    loading_widget->hide();
    greeting_widget->show();
}

void MainWindow::nadya_dialog1_button_clicked()
{
    ui->gridLayout->replaceWidget(nadya_dialog1_widget.get(), nadya_dialog2_widget.get());
    nadya_dialog1_widget->hide();
    nadya_dialog2_widget->show();
}

void MainWindow::nadya_dialog2_button_clicked()
{
    ui->gridLayout->replaceWidget(nadya_dialog2_widget.get(), main_menu_widget.get());
    nadya_dialog2_widget->hide();
    main_menu_widget->show();
}

void MainWindow::on_start_button_clicked()
{
    ui->gridLayout->replaceWidget(greeting_widget.get(), nadya_dialog1_widget.get());
    greeting_widget->hide();
    nadya_dialog1_widget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

