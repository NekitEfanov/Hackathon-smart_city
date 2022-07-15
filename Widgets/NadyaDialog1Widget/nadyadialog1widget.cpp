#include "nadyadialog1widget.h"
#include "ui_nadyadialog1widget.h"

NadyaDialog1Widget::NadyaDialog1Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NadyaDialog1Widget)
{
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);

    ui->label_dialog->setMinimumSize(QSize(this->height() / 0.8, this->width() / 0.8));
    ui->label_dialog->setMaximumSize(QSize(this->height() / 0.8, this->width() / 0.8));
    QPixmap image(":/image/Resource/dialog_1.png");
    ui->label_dialog->setPixmap(image.scaled(ui->label_dialog->size()));

    ui->label_Nadya->setMinimumSize(QSize(this->height() / 0.8, this->width() / 0.8));
    ui->label_Nadya->setMaximumSize(QSize(this->height() / 0.8, this->width() / 0.8));
    image.load(":/image/Resource/assistant_1.png");
    ui->label_Nadya->setPixmap(image.scaled(ui->label_Nadya->size()));
}

void NadyaDialog1Widget::mousePressEvent(QMouseEvent* event)
{
    emit button_clicked();
}

NadyaDialog1Widget::~NadyaDialog1Widget()
{
    delete ui;
}
