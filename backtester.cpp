#include "backtester.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <cmath>

Backtester::Backtester()
{
    // Constructor
}

// --- THE MASTER FUNCTION ---
QString Backtester::runBacktest(QString ticker, IStrategy* strategy, double initialCapital)
{
    if (strategy == nullptr) {
        return "Error: No strategy provided.";
    }

    // Clear old data
    m_priceData.clear();

    // 1. Load data
    bool success = loadData(ticker);

    if (!success) {
        return "Error: Could not find or load data file for " + ticker + ".";
    }

    // --- INITIALIZE LOCAL VARIABLES ---
    // FIX: We use a local variable 'cash', not 'm_cash'
    double cash = initialCapital;
    int totalTrades = 0;
    int winningTrades = 0;
    int losingTrades = 0;
    double lastBuyPrice = 0.0;

    // --- 2. RUN THE STRATEGY ---
    // We pass our local 'cash' variable to the strategy
    strategy->run(m_priceData, cash, lastBuyPrice, totalTrades, winningTrades, losingTrades);

    QString strategyName = strategy->getName();

    // --- 3. CALCULATE REPORT ---
    double profitPercent = ((cash - initialCapital) / initialCapital) * 100.0;
    double winRate = 0.0;
    if (totalTrades > 0) {
        winRate = (double)winningTrades / totalTrades * 100.0;
    }

    // --- 4. FORMAT OUTPUT STRING ---
    QString result = "Successfully loaded " + QString::number(m_priceData.size()) + " days...\n";
    result += "Strategy: " + strategyName + "\n";
    result += "Initial Cash: $" + QString::number(initialCapital) + "\n";
    result += "Total Trades: " + QString::number(totalTrades) + "\n";
    result += "Winning Trades: " + QString::number(winningTrades) + "\n";
    result += "Losing Trades: " + QString::number(losingTrades) + "\n";
    result += "Win Rate: " + QString::number(winRate, 'f', 1) + " %\n";
    result += "Final Cash: $" + QString::number(cash) + "\n";
    result += "Profit/Loss: " + QString::number(profitPercent, 'f', 2) + " %";

    return result;
}

// --- THE SMART DATA LOADER (Unchanged) ---
bool Backtester::loadData(QString ticker)
{
    QString filePath = ticker;

    // 1. Check if file exists on disk exactly as typed
    if (QFile::exists(filePath)) {
        qDebug() << "Found local file on disk:" << filePath;
    }
    // 2. Check if file exists on disk with .csv appended
    else if (QFile::exists(filePath + ".csv")) {
        filePath = filePath + ".csv";
        qDebug() << "Found local file on disk (added extension):" << filePath;
    }
    // 3. Fallback: Look in the Qt Resource System
    else {
        filePath = ":/" + ticker + ".csv";
        qDebug() << "Looking in resources for:" << filePath;
    }

    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open file:" << filePath;
        return false;
    }

    QTextStream in(&file);

    if (!in.atEnd()) {
        in.readLine();
    }

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        if (fields.size() == 5) {
            StockData dayData;
            dayData.date = QDate::fromString(fields[0], "yyyy-MM-dd");
            dayData.open = fields[1].toDouble();
            dayData.high = fields[2].toDouble();
            dayData.low = fields[3].toDouble();
            dayData.close = fields[4].toDouble();

            m_priceData.append(dayData);
        }
    }

    file.close();
    return !m_priceData.isEmpty();
}
