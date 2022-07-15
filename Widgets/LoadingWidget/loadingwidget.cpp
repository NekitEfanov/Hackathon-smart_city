#include "loadingwidget.h"
#include "ui_loadingwidget.h"

#include <chrono>

using namespace std::chrono_literals;

LoadingWidget::LoadingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadingWidget)
{
    ui->setupUi(this);
    QPalette palette = QPalette();
    palette.setColor(QPalette::Window, QColor(140, 52, 236));
    this->setAutoFillBackground(true);
    setPalette(palette);

    ui->label->setMinimumSize(QSize(this->height() / 2, this->width() / 1.2));
    ui->label->setMaximumSize(QSize(this->height() / 2, this->width() / 1.2));
    QPixmap icon(":/image/Resource/icon_3.png");
    ui->label->setPixmap(icon.scaled(ui->label->size()));


    //For animation in the future
    th = new std::thread([this]() {
        std::this_thread::sleep_for(4000ms);
        emit loading_is_complete_signal();
        }
    );
}

LoadingWidget::~LoadingWidget()
{
    delete ui;
}
