#ifndef LOADINGWIDGET_H
#define LOADINGWIDGET_H

#include <QWidget>
#include <QPalette>
#include <QColor>
#include <QPainter>
#include <QThread>

#include <thread>

namespace Ui {
class LoadingWidget;
}

class LoadingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingWidget(QWidget *parent = nullptr);
    ~LoadingWidget();

public:
    std::thread* th;

signals:
    void loading_is_complete_signal();

private:
    Ui::LoadingWidget *ui;

};

#endif // LOADINGWIDGET_H
