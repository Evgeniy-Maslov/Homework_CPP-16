#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDataStream>
#include <QMessageBox>
#include <QtGlobal>
#include <QtConcurrent>

///Подключаем все что нужно для графиков
#include <QLineSeries>
#include <QtCharts>
#include <QChartView>

#define FD 1000.0 //частота дискретизации

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Метод считывает данные из исходного файла
    QVector<uint32_t> ReadFile(QString path, uint8_t numberChannel);
    //Метод преобразует данные физические величины, В?
    QVector<double> ProcessFile(QVector<uint32_t> dataFile);
    //Метод ищет Максимумы
    QVector<double> FindMax(QVector<double> resultData);
    //Метод ищет минимумы
    QVector<double> FindMin(QVector<double> resultData);
    //Метод отображает результаты
    void DisplayResult(QVector<double> mins, QVector<double> maxs);



Q_SIGNALS:
    void data_is_ready_for_rendering();
    void clear_series();
    void signal_DisplayResult(QVector<double> mins, QVector<double> maxs);

private Q_SLOTS:
    void on_pb_path_clicked();
    void on_pb_start_clicked();
    void chart_display();


private:
    Ui::MainWindow *ui;

    QMainWindow *window;
    QChart* chart;
    QSplineSeries *series;
    QChartView *chartview;

    QString pathToFile = "D:\\source\\Homework_CPP-16\\Cross-platform_development_on_Qt\\7_QtCharts_QCustomPlot\\PreGraphic\\build\\Desktop-Debug\\testData.adc";
    uint8_t numberSelectChannel = 0xEA;

    QVector<uint32_t> readData;
    QVector<double> procesData;
    QVector<double> mins, maxs;

};
#endif // MAINWINDOW_H
