#ifndef NADYADIALOG1WIDGET_H
#define NADYADIALOG1WIDGET_H

#include <QWidget>

namespace Ui {
class NadyaDialog1Widget;
}

class NadyaDialog1Widget : public QWidget
{
    Q_OBJECT

public:
    explicit NadyaDialog1Widget(QWidget *parent = nullptr);
    ~NadyaDialog1Widget();

signals:
    void button_clicked();

private:
    Ui::NadyaDialog1Widget *ui;

    void mousePressEvent(QMouseEvent* event) override;
};

#endif // NADYADIALOG1WIDGET_H
