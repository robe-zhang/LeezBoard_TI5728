#ifndef SCHEDULESCREEN_H
#define SCHEDULESCREEN_H

#include <qglobal.h>
#include <QtGui>

#if QT_VERSION >= 0x050000

#include <QTimer>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QButtonGroup>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDesktopWidget>
#include <QGraphicsSceneMouseEvent>

#endif

#include "schedulepoint.h"

class GlobalSettings;

class ScheduleScreen : public QWidget
{
    Q_OBJECT
public:
    explicit ScheduleScreen(QWidget *parent = 0);
    
signals:
    void valueChanged();
    void clicked();
    
public slots:
    void shiftLeft();
    void shiftRight();
    void increaseTemp();
    void decreaseTemp();
    void selectDay(SchedulePoint *);
    void unselectDay();
    void updateData();
    void createScheduleScene();
    void showEvent(QShowEvent *);
    void addSchedulePoints();
    void disableRow(bool checked);
    void initializeScene();
    void initializeGraphics();

private:
    QButtonGroup *daysButtonGroup;
    QGraphicsScene *scene;
    QGraphicsView *view;

    int seqNumber;
    QList <SchedulePoint *> pointList;
    QList <QPair<QPointF, int> > pointSave;


    SchedulePoint *currentPoint;
    void showPoint(SchedulePoint *);
    QLabel *currentTime;

    QRectF pointArea;
    qreal weekHeight;
    qreal timeBlockWidth;
    qreal timeWidth;

    GlobalSettings* m_globalSettings;

    bool m_initialized;

protected:
    void mousePressEvent(QMouseEvent */* event */);
};

#endif // SCHEDULESCREEN_H
