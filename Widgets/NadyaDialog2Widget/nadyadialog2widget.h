#ifndef NADYADIALOG2WIDGET_H
#define NADYADIALOG2WIDGET_H

#include <QWidget>

namespace Ui {
class NadyaDialog2Widget;
}

class NadyaDialog2Widget : public QWidget
{
    Q_OBJECT

public:
    explicit NadyaDialog2Widget(QWidget *parent = nullptr);
    ~NadyaDialog2Widget();

signals:
    void button_clicked();

private:
    Ui::NadyaDialog2Widget *ui;

    void mousePressEvent(QMouseEvent* event) override;
};

#endif // NADYADIALOG2WIDGET_H
