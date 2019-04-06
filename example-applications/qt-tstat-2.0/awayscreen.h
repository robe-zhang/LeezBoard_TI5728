#ifndef AWAYSCREEN_H
#define AWAYSCREEN_H

#include <qglobal.h>

#include <QtGui>

#if QT_VERSION >= 0x050000

#include <QSpinBox>
#include <QLabel>
#include <QLineEdit>

#endif

class GlobalSettings;

class AwayScreen : public QWidget
{
    Q_OBJECT
public:
    explicit AwayScreen(QWidget *parent = 0);
    
    void setCurrentTempPtr(int* currentTempPointer);
signals:
    
public slots:
    void updateCurrentTemp();
    void updateUnit();

private:
    QLabel *awayLabel;
    QLabel *ecoLabel;
    QLabel *currentTempLabel;
    QSpinBox *upperBound;
    QSpinBox *lowerBound;

    int m_upperBound;
    int m_lowerBound;

    int *m_currentTemp;

    GlobalSettings* m_globalSettings;
};

#endif // AWAYSCREEN_H
