#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPushButton *exitButton;
    QPushButton *arrayButton;
    QPushButton *answer;
    QLabel *outText;
private slots:
    void swap();
    void setText(const QString &txt);
};

#endif // WIDGET_H
