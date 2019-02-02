#ifndef ANALOGTIMER_H
#define ANALOGTIMER_H

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class analogtimer;
}

class analogtimer : public QWidget
{
    Q_OBJECT

public:
    explicit analogtimer(QWidget *parent = nullptr);
    ~analogtimer();

private:
    Ui::analogtimer *ui;

protected:
    void paintEvent(QPaintEvent *event) override;
};



#endif // ANALOGTIMER_H
