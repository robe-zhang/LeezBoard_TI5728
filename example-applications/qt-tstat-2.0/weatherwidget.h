#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

#include <qglobal.h>
#include <QtGui>
#include <QtSvg/QSvgWidget>

#if QT_VERSION >= 0x050000

#include <QStackedWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

#endif

class QLabel;
class WeatherData;
class WeatherDataWidget;
class ForecastDataWidget;
class GlobalSettings;

class WeatherWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WeatherWidget(QWidget *parent = 0);
    void setCity(QString);
    void setClock(QTime);

    void setWeatherData(WeatherData* weatherData);
    WeatherData* weatherData();

    enum CurrentStatus { Updating, UpdateSuccess, UpdateFailed };

    QVariantHash getCurrentData();

signals:
    void valueChanged();
    void webReloadRequested();

public slots:
    void setStatusUpdated();
    void setStatusUpdating();
    void setStatusFailed();

    void updateData();

    void mousePressEvent(QMouseEvent *);

    void advanceStatusWidget();




protected:

private:
    QString weatherStyleSheet;
    QTime *clock;
    QLabel *statusLabel;
    QLabel *statusLabel2;
    QLabel *statusMovieLabel;
    QMovie *statusMovie;
    QStackedWidget *statusStackedWidget;
    WeatherDataWidget* weatherDataWidget;
    ForecastDataWidget* forecastDataWidget;
    WeatherData* m_weatherData;

    GlobalSettings *m_globalSettings;

    CurrentStatus m_currentStatus;
    QTimer statusMessageTimer;

    //layout related functions
    void buildStatusWidget();
};

#endif // WEATHERWIDGET_H
