#include "purposesmenuinfowidget.h"
#include "ui_purposesmenuinfowidget.h"

PurposesMenuInfoWidget::PurposesMenuInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PurposesMenuInfoWidget)
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

    ui->label_image->setMinimumSize(QSize(this->height() / 2.6, this->width() / 2.2));
    ui->label_image->setMaximumSize(QSize(this->height() / 2.6, this->width() / 2.2));
    QPixmap book_image(":/image/Resource/icon_3.png");
    ui->label_image->setPixmap(book_image.scaled(ui->label_image->size()));
}

void PurposesMenuInfoWidget::mousePressEvent(QMouseEvent* event)
{
    emit button_clicked();
}

PurposesMenuInfoWidget::~PurposesMenuInfoWidget()
{
    delete ui;
}
