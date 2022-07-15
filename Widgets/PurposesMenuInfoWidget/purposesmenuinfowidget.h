#ifndef PURPOSESMENUINFOWIDGET_H
#define PURPOSESMENUINFOWIDGET_H

#include <QWidget>

namespace Ui {
class PurposesMenuInfoWidget;
}

class PurposesMenuInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PurposesMenuInfoWidget(QWidget *parent = nullptr);
    ~PurposesMenuInfoWidget();

signals:
    void button_clicked();

private:
    Ui::PurposesMenuInfoWidget *ui;

    void mousePressEvent(QMouseEvent* event);
};

#endif // PURPOSESMENUINFOWIDGET_H
