#ifndef GREETINGWIDGET_H
#define GREETINGWIDGET_H

#include <QWidget>
#include <QPalette>

namespace Ui {
class GreetingWidget;
}

class GreetingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GreetingWidget(QWidget *parent = nullptr);
    ~GreetingWidget();

private slots:
    void on_start_button_clicked();

signals:
    void start_button_clicked();

private:
    Ui::GreetingWidget *ui;
};

#endif // GREETINGWIDGET_H
