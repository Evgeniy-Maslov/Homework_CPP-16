#include "airportcongestion.h"
#include "ui_airportcongestion.h"

AirportCongestion::AirportCongestion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AirportCongestion)
{
    ui->setupUi(this);

    ui->lb_AirportName->clear();
    ui->lb_AirportName->setAlignment(Qt::AlignCenter);
    ui->tabWidget->setTabText(0, "загруженность аэропорта за год");
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabText(1, "загруженность аэропорта за месяц");
    ui->lb_months->setText("выбор месяца");
    ui->lb_months->setStyleSheet("color:black");
    SetCbMonths();
    QObject::connect(ui->pb_Close, &QPushButton::clicked, this, [&](){ AirportCongestion::close();});
    QObject::connect(ui->tabWidget, &QTabWidget::currentChanged, this, [&](){ if(ui->tabWidget->currentIndex() == 1) {
                                                                                ui->cb_months->setCurrentIndex(0);
                                                                                emit sig_RequestAirportWorkloadByMonth();
                                                                             }
                                                                             else{
                                                                                 ui->cb_months->setCurrentIndex(1);
                                                                             }});
    QObject::connect(ui->cb_months, &QComboBox::currentIndexChanged, this, [&](){ ScreenAirportWorkloadByMonth(months); });
}

void AirportCongestion::SetCbMonths()
{
    for(int i = 0; i < 12; i++ )
    {
        ui->cb_months->insertItem(i, MonthToString(i + 1));
    }
}

QVector<FlightDataForPeriod> AirportCongestion::ArrayFlightData(QSqlQueryModel* queryModel)
{
    QVector<FlightDataForPeriod> temp_array;
    for(int i = 0; i < queryModel->rowCount(); i++)
    {
        FlightDataForPeriod temp;
        temp.date = queryModel->data(queryModel->index(i, 1)).toDateTime();
        temp.count = queryModel->data(queryModel->index(i, 0)).toInt();
        temp_array.append(temp);
    }
    return temp_array;
}

void AirportCongestion::SetAirportName(QString name)
{
    ui->lb_AirportName->clear();
    ui->lb_AirportName->setText("аэропорт \"" +name + "\"");
    ui->tabWidget->setCurrentIndex(0);
}

void AirportCongestion::ParsingDatabase(QSqlQueryModel* queryModel)
{
    QVector<FlightDataForPeriod> array_flight_data_by_month_for_year = ArrayFlightData(queryModel);
    months.clear();
    for(int i = 0; i < array_flight_data_by_month_for_year.size(); i++)
    {
        months[array_flight_data_by_month_for_year[i].date.date().month()].push_back(array_flight_data_by_month_for_year[i]);
    }
    ScreenAirportWorkloadByMonth(months);
}

void AirportCongestion::RemovePlottable(QCustomPlot* cuspomplot)
{
    if( cuspomplot->plottableCount())
    {
        for(int i = 0; i < cuspomplot->plottableCount(); i++)
        {
            cuspomplot->removePlottable(i);
        }
    }
}

void AirportCongestion::ScreenAirportWorkloadByMonth(QMap<int, QVector<FlightDataForPeriod>>& months)
{
    RemovePlottable(ui->tab_AirportTrafficMonth);
    QCPGraph* graph;
    graph = new QCPGraph(ui->tab_AirportTrafficMonth->xAxis, ui->tab_AirportTrafficMonth->yAxis);
    graph->setPen(QPen(Qt::blue));
    graph->setAntialiased(false);

    ui->tab_AirportTrafficMonth->xAxis2->setVisible(true);
    ui->tab_AirportTrafficMonth->xAxis2->setTickLabels(false);
    ui->tab_AirportTrafficMonth->yAxis2->setVisible(true);
    ui->tab_AirportTrafficMonth->yAxis2->setTickLabels(false);
    connect(ui->tab_AirportTrafficMonth->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->tab_AirportTrafficMonth->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->tab_AirportTrafficMonth->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->tab_AirportTrafficMonth->yAxis2, SLOT(setRange(QCPRange)));

    int maxValue_yAxis = 0;

    for(int i = 0; i < months[ui->cb_months->currentIndex() + 1].size() - 1; i++)
    {
        if( months[ui->cb_months->currentIndex() + 1].value(i).count > maxValue_yAxis)
        {
            maxValue_yAxis = months[ui->cb_months->currentIndex() + 1].value(i).count;
        }
    }
    int minValue_yAxis = maxValue_yAxis;

    for(int i = 0; i < months[ui->cb_months->currentIndex() + 1].size() - 1; i++)
    {
        if( months[ui->cb_months->currentIndex() + 1].value(i).count < minValue_yAxis)
        {
            minValue_yAxis = months[ui->cb_months->currentIndex() + 1].value(i).count;
        }
    }

    ui->tab_AirportTrafficMonth->xAxis->setRange(1, months[ui->cb_months->currentIndex() + 1].size());
    ui->tab_AirportTrafficMonth->xAxis->ticker()->setTickCount(months[ui->cb_months->currentIndex() + 1].size());
    ui->tab_AirportTrafficMonth->yAxis->setRange(minValue_yAxis - 1, maxValue_yAxis + 1);
    ui->tab_AirportTrafficMonth->yAxis->ticker()->setTickCount((maxValue_yAxis + 1) - (minValue_yAxis - 1));
    ui->tab_AirportTrafficMonth->yAxis->setPadding(5);

    for(int i = 0; i < months[ui->cb_months->currentIndex() + 1].size(); i++)
    {
        graph->addData(months[ui->cb_months->currentIndex() + 1].value(i).date.date().day(), months[ui->cb_months->currentIndex() + 1].value(i).count);
    }

    ui->tab_AirportTrafficMonth->replot();
}

void AirportCongestion::ScreenGeneralStatisticsForYear(QSqlQueryModel* queryModel)
{
    RemovePlottable(ui->tab_AirportTrafficYear);
    QVector<FlightDataForPeriod> array_flight_data_for_year = ArrayFlightData(queryModel);

    QCPBars* diagramma;
    diagramma = new QCPBars(ui->tab_AirportTrafficYear->xAxis, ui->tab_AirportTrafficYear->yAxis);
    diagramma->setName(ui->lb_AirportName->text());
    diagramma->setAntialiased(false);
    diagramma->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    diagramma->setBrush(QColor(111, 9, 176));
    diagramma->setWidth(0.6);

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for(int i = 0; i < array_flight_data_for_year.size(); i++)
    {
        textTicker->addTick(array_flight_data_for_year[i].date.date().month(), MonthToString(array_flight_data_for_year[i].date.date().month()));
    }

    ui->tab_AirportTrafficYear->xAxis->setTicker(textTicker);
    ui->tab_AirportTrafficYear->xAxis->setTickLabelRotation(60);
    ui->tab_AirportTrafficYear->xAxis->setSubTicks(false);
    ui->tab_AirportTrafficYear->xAxis->setTickLength(0, 4);
    ui->tab_AirportTrafficYear->xAxis->setRange(0, array_flight_data_for_year.size() + 1);

    int maxValue_yAxis = 0;
    for(int i = 0; i < array_flight_data_for_year.size() - 1; i++){
        if(array_flight_data_for_year[i].count > maxValue_yAxis){
            maxValue_yAxis = array_flight_data_for_year[i].count;
        }
    }
    ui->tab_AirportTrafficYear->yAxis->setPadding(5);
    ui->tab_AirportTrafficYear->yAxis->setRange(0, maxValue_yAxis + (maxValue_yAxis / 15));
    ui->tab_AirportTrafficYear->yAxis->setLabel("суммарное количество всех вылетов и прилетов");

    for(int i = 0; i < array_flight_data_for_year.size(); i++)
    {
        diagramma->addData(array_flight_data_for_year[i].date.date().month(), array_flight_data_for_year[i].count);
    }

    ui->tab_AirportTrafficYear->replot();
}

QString AirportCongestion::MonthToString(int _month)
{
    QString month;
    switch(_month)
    {
    case 1:{ month = "январь"; break; }
    case 2:{ month = "февраль"; break; }
    case 3:{ month = "март"; break; }
    case 4:{ month = "апрель"; break; }
    case 5:{ month = "май"; break; }
    case 6:{ month = "июнь"; break; }
    case 7:{ month = "июль"; break; }
    case 8:{ month = "август"; break; }
    case 9:{ month = "сентябрь"; break; }
    case 10:{ month = "октябрь"; break; }
    case 11:{ month = "ноябрь"; break; }
    case 12:{ month = "декабрь"; break; }
    }
    return month;
}

AirportCongestion::~AirportCongestion()
{
    delete ui;
}
