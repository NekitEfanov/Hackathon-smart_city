#include "greetingwidget.h"
#include "ui_greetingwidget.h"

GreetingWidget::GreetingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GreetingWidget)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor(140, 52, 236));
    ui->label->setAutoFillBackground(true);
    ui->label->setPalette(palette);

    ui->start_button->setMaximumSize(QSize(this->height() / 0.8, this->width() / 0.6));
    ui->start_button->setMinimumSize(QSize(this->height() / 0.8, this->width() / 0.6));
    ui->start_button->setStyleSheet("border-image: url(:/image/Resource/button_start.png) stretch; ");
}

GreetingWidget::~GreetingWidget()
{
    delete ui;
}

void GreetingWidget::on_start_button_clicked()
{
    emit start_button_clicked();
}

