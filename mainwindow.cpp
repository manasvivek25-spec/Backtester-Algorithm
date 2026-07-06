#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QVariantMap>

// For text alignment
#include <QTextCursor>
#include <QTextBlockFormat>

// --- INCLUDE ALL YOUR STRATEGY CLASSES ---
#include "IStrategy.h"
#include "SmaCrossStrategy.h"
#include "BollingerBandsStrategy.h"
#include "RsiStrategy.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // --- POPULATE THE COMBO BOX ---
    ui->strategyComboBox->addItem("SMA Crossover");
    ui->strategyComboBox->addItem("Bollinger Bands");
    ui->strategyComboBox->addItem("RSI");

    // --- CONNECT THE COMBO BOX TO THE SLOT ---
    connect(ui->strategyComboBox,
            SIGNAL(currentIndexChanged(int)),
            this,
            SLOT(on_strategyComboBox_currentIndexChanged(int)));

    // Set the initial page to match the dropdown (index 0)
    ui->strategyParamsStackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// This function is called when the dropdown selection changes
void MainWindow::on_strategyComboBox_currentIndexChanged(int index)
{
    // This just shows the correct page of inputs
    ui->strategyParamsStackedWidget->setCurrentIndex(index);
}

// This function is called when you click the "Run Backtest" button
void MainWindow::on_runButton_clicked()
{
    QString ticker = ui->tickerInput->text();

    // 1. Get Initial Capital from UI
    double initialCapital = ui->capitalInput->value();

    // 2. Get the strategy type from the dropdown's current index
    StrategyType strategyType = (StrategyType)ui->strategyComboBox->currentIndex();

    // 3. Create a pointer for our polymorphic strategy object
    IStrategy* strategy = nullptr;

    // 4. The "Strategy Factory"
    switch (strategyType) {
    case SMA_CROSSOVER: {
        int shortP = ui->shortPeriodInput->value();
        int longP = ui->longPeriodInput->value();
        if (shortP >= longP) {
            QMessageBox::warning(this, "Input Error", "The 'Short Period' must be less than the 'Long Period'.");
            return; // Stop
        }
        strategy = new SmaCrossStrategy(shortP, longP);
        break;
    }
    case BOLLINGER_BANDS: {
        int period = ui->bbPeriodInput->value();
        double stdDev = ui->bbStdDevInput->value();
        strategy = new BollingerBandsStrategy(period, stdDev);
        break;
    }
    case RSI: {
        int period = ui->rsiPeriodInput->value();
        int oversold = ui->rsiOversoldInput->value();
        int overbought = ui->rsiOverboughtInput->value();
        strategy = new RsiStrategy(period, oversold, overbought);
        break;
    }
    }

    if (strategy == nullptr) {
        qDebug() << "Error: Strategy object was null.";
        return; // Safety check
    }

    // 5. Call the backtester with the strategy AND capital
    QString resultMessage = m_backtester.runBacktest(ticker, strategy, initialCapital);

    // 6. Clean up memory
    delete strategy;
    strategy = nullptr;

    // 7. Display the result (Centered)
    ui->resultsOutput->clear();
    QTextCursor cursor = ui->resultsOutput->textCursor();
    QTextBlockFormat format;
    format.setAlignment(Qt::AlignCenter);
    cursor.mergeBlockFormat(format);
    ui->resultsOutput->setTextCursor(cursor);
    ui->resultsOutput->setText(resultMessage);

    qDebug() << "Backtest complete. Ticker:" << ticker;
}
