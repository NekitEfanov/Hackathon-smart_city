#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <booktextwidget.h>
#include <purposesmenuinfowidget.h>
#include <purposesmenuwidget.h>

#include <memory>
#include <QWidget>

namespace Ui {
class MainMenuWidget;
}

class MainMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenuWidget(QWidget *parent = nullptr);
    ~MainMenuWidget();

private slots:
    void on_purposes_button_clicked();
    void purposes_menu_info_widget_button_clicked();

private:
    Ui::MainMenuWidget *ui;

    std::shared_ptr<BookTextWidget> book_text_widget;
    std::shared_ptr<PurposesMenuInfoWidget> purposes_menu_info_widget;
    std::shared_ptr<PurposesMenuWidget> purposes_menu_widget;
};

#endif // MAINMENUWIDGET_H
