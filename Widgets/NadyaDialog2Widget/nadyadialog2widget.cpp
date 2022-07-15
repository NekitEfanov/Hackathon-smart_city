#include "nadyadialog2widget.h"
#include "ui_nadyadialog2widget.h"

NadyaDialog2Widget::NadyaDialog2Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NadyaDialog2Widget)
{
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);

    ui->label_dialog->setMinimumSize(QSize(this->height() / 0.8, this->width() / 0.8));
    ui->label_dialog->setMaximumSize(QSize(this->height() / 0.8, this->width() / 0.8));
    QPixmap image(":/image/Resource/dialog_2.png");
    ui->label_dialog->setPixmap(image.scaled(ui->label_dialog->size()));

    ui->label_Nadya->setMinimumSize(QSize(this->height() / 0.8, this->width() / 0.8));
    ui->label_Nadya->setMaximumSize(QSize(this->height() / 0.8, this->width() / 0.8));
    image.load(":/image/Resource/assistant_2.png");
    ui->label_Nadya->setPixmap(image.scaled(ui->label_Nadya->size()));
}

void NadyaDialog2Widget::mousePressEvent(QMouseEvent* event)
{
    emit button_clicked();
}

NadyaDialog2Widget::~NadyaDialog2Widget()
{
    delete ui;
}
