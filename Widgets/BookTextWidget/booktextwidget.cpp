#include "booktextwidget.h"
#include "ui_booktextwidget.h"

BookTextWidget::BookTextWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookTextWidget)
{
    ui->setupUi(this);
    ui->verticalLayout->setMargin(0);

    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor(140, 52, 236));
    ui->label_2->setAutoFillBackground(true);
    ui->label_2->setPalette(palette);

    palette.setColor(QPalette::Window, QColor(229, 218, 241));
    ui->label_1->setAutoFillBackground(true);
    ui->label_1->setPalette(palette);

    ui->label_book_image->setMinimumSize(QSize(this->height() / 1.6, this->width() / 1.4));
    ui->label_book_image->setMaximumSize(QSize(this->height() / 1.6, this->width() / 1.4));
    QPixmap book_image(":/image/Resource/book_1.png");
    ui->label_book_image->setPixmap(book_image.scaled(ui->label_book_image->size()));
}

BookTextWidget::~BookTextWidget()
{
    delete ui;
}
