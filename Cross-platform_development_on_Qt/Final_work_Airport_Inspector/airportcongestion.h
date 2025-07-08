#ifndef AIRPORTCONGESTION_H
#define AIRPORTCONGESTION_H

#include "qcustomplot.h"
#include <QDialog>
#include <QDate>
#include <qsqlquerymodel.h>


//***** структура - данные о рейсах за период
struct FlightDataForPeriod
{
    int count;
    QDateTime date;

    bool operator<(FlightDataForPeriod &flight_date_period) const
    {
        return date < flight_date_period.date;
    }
    ~FlightDataForPeriod(){}
};



namespace Ui {
class AirportCongestion;
}

class AirportCongestion : public QDialog
{
    Q_OBJECT

public:
    explicit AirportCongestion(QWidget *parent = nullptr);
    ~AirportCongestion();

Q_SIGNALS:
    void sig_RequestAirportWorkloadByMonth();
    void sig_RequestAirportWorkloadForYear();

public Q_SLOTS:
    void SetAirportName(QString name);
    void ParsingDatabase(QSqlQueryModel* queryModel);
    void ScreenAirportWorkloadByMonth(QMap<int, QVector<FlightDataForPeriod>>& months);
    void ScreenGeneralStatisticsForYear(QSqlQueryModel* queryModel);

private:
    QString MonthToString(int month);
    void SetCbMonths();
    QVector<FlightDataForPeriod> ArrayFlightData(QSqlQueryModel* queryModel);
    void RemovePlottable(QCustomPlot* cuspomplot);

    Ui::AirportCongestion *ui;
    QMap<int, QVector<FlightDataForPeriod>> months;
};

#endif // AIRPORTCONGESTION_H
