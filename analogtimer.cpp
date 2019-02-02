#include <QtWidgets>

#include "analogtimer.h"
#include "ui_analogtimer.h"


analogtimer::analogtimer(QWidget *parent) :
    QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(update));
    timer-> start(1000);

    setWindowTitle(tr("Jam Clock"));
    resize(200,200);
}

void analogtimer::paintEvent(QPaintEvent *)
{
    static const QPoint LenganJam[3]={
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(0, -40)
    };

    static const QPoint LenganMenit[3] = {
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(0, -80)
    };

    QColor WarnaJam(150,0,150);
    QColor WarnaMenit(0,150,10,191);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() /2, height() / 2);
    painter.scale(side/200.0, side/200.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(WarnaJam);

    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(LenganJam,3);
    painter.restore();

    painter.setPen(WarnaJam);
    for(int i=0; i<12; i++){
        painter.drawLine(88,0,96,0);
        painter.rotate(30.0);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(WarnaMenit);

    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second()/ 60.0));
    painter.drawConvexPolygon(LenganMenit,3);
    painter.restore();

    painter.setPen(WarnaMenit);

    for(int j=0; j<60; j++){
        if((j%5) != 0)
            painter.drawLine(92,0,96,0);
        painter.rotate(6.0);
    }






}

analogtimer::~analogtimer()
{
    delete ui;
}
