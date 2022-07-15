#ifndef PURPOSESMENUWIDGET_H
#define PURPOSESMENUWIDGET_H

#include <QWidget>

namespace Ui {
class PurposesMenuWidget;
}

class PurposesMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PurposesMenuWidget(QWidget *parent = nullptr);
    ~PurposesMenuWidget();

private:
    Ui::PurposesMenuWidget *ui;
};

#endif // PURPOSESMENUWIDGET_H
