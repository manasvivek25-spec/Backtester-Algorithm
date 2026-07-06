#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "backtester.h"
#include "IStrategy.h" // <-- Include the new headers
#include "StockData.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// --- ADD THIS ENUM (can also be in its own file) ---
enum StrategyType {
    SMA_CROSSOVER,
    BOLLINGER_BANDS,
    RSI
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_runButton_clicked();
    void on_strategyComboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Backtester m_backtester;
};
#endif // MAINWINDOW_H
