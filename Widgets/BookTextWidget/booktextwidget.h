#ifndef BOOKTEXTWIDGET_H
#define BOOKTEXTWIDGET_H

#include <QWidget>

namespace Ui {
class BookTextWidget;
}

class BookTextWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BookTextWidget(QWidget *parent = nullptr);
    ~BookTextWidget();

private:
    Ui::BookTextWidget *ui;
};

#endif // BOOKTEXTWIDGET_H
