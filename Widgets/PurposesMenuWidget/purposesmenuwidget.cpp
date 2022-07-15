#include "purposesmenuwidget.h"
#include "ui_purposesmenuwidget.h"

PurposesMenuWidget::PurposesMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PurposesMenuWidget)
{
    ui->setupUi(this);
}

PurposesMenuWidget::~PurposesMenuWidget()
{
    delete ui;
}
