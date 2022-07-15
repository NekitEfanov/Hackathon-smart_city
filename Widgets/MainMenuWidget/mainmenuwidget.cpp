#include "mainmenuwidget.h"
#include "ui_mainmenuwidget.h"

MainMenuWidget::MainMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this);
    ui->gridLayout->setMargin(0);

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(229, 218, 241));
    ui->widget_2->setPalette(palette);
    ui->widget_2->setAutoFillBackground(true);

    float scale_x = 5;
    float scale_y = 5;

    //This place will be optimized in the future
    ui->masterminds_button->setMaximumSize(QSize(this->height() / scale_x, this->width() / scale_y));
    ui->masterminds_button->setMinimumSize(QSize(this->height() / scale_x, this->width() / scale_y));
    ui->masterminds_button->setStyleSheet("border-image: url(:/image/Resource/book_2.png) stretch; ");

    ui->purposes_button->setMaximumSize(QSize(this->height() / scale_x, this->width() / scale_y));
    ui->purposes_button->setMinimumSize(QSize(this->height() / scale_x, this->width() / scale_y));
    ui->purposes_button->setStyleSheet("border-image: url(:/image/Resource/icon_1.png) stretch; ");

    ui->progress_button->setMaximumSize(QSize(this->height() / scale_x, this->width() / scale_y));
    ui->progress_button->setMinimumSize(QSize(this->height() / scale_x, this->width() / scale_y));
    ui->progress_button->setStyleSheet("border-image: url(:/image/Resource/list_1.png) stretch; ");

    ui->chat_button->setMaximumSize(QSize(this->height() / scale_x, this->width() / scale_y));
    ui->chat_button->setMinimumSize(QSize(this->height() / scale_x, this->width() / scale_y));
    ui->chat_button->setStyleSheet("border-image: url(:/image/Resource/message_1.png) stretch; ");

    ui->theory_button->setMaximumSize(QSize(this->height() / scale_x, this->width() / scale_y));
    ui->theory_button->setMinimumSize(QSize(this->height() / scale_x, this->width() / scale_y));
    ui->theory_button->setStyleSheet("border-image: url(:/image/Resource/document_1.png) stretch; ");

    book_text_widget.reset(new BookTextWidget());
    purposes_menu_info_widget.reset(new PurposesMenuInfoWidget());

    ui->gridLayout->replaceWidget(ui->widget, book_text_widget.get());
    ui->widget->hide();
    book_text_widget->show();

    connect(purposes_menu_info_widget.get(),
            &PurposesMenuInfoWidget::button_clicked,
            this,
            &MainMenuWidget::purposes_menu_info_widget_button_clicked);
}

//This place will be optimized in the future
void MainMenuWidget::on_purposes_button_clicked()
{
    if (!book_text_widget->isHidden()) {
        ui->gridLayout->replaceWidget(book_text_widget.get(), purposes_menu_info_widget.get());
        book_text_widget->hide();

        ui->masterminds_button->setStyleSheet("border-image: url(:/image/Resource/book_1.png) stretch; ");
        ui->purposes_button->setStyleSheet("border-image: url(:/image/Resource/icon_2.png) stretch; ");
        purposes_menu_info_widget->show();
    }
}

void MainMenuWidget::purposes_menu_info_widget_button_clicked()
{
    //ui->gridLayout->replaceWidget(purposes_menu_info_widget.get(), purposes_menu_widget.get());
    //purposes_menu_info_widget->hide();
    //purposes_menu_widget->show();
}

MainMenuWidget::~MainMenuWidget()
{
    delete ui;
}

