#ifndef BACKTESTER_H
#define BACKTESTER_H

#include <QString>
#include <QVector>
#include "StockData.h" // Includes the StockData struct and operator overloads
#include "IStrategy.h" // Includes the Strategy Interface

class Backtester
{
public:
    Backtester();

    // --- UPDATED FUNCTION SIGNATURE ---
    // Now accepts 'initialCapital' as the 3rd parameter
    QString runBacktest(QString ticker, IStrategy* strategy, double initialCapital);

private:
    // We only need to store the loaded price data here.
    // Cash, trades, and P/L are now local variables inside runBacktest.
    QVector<StockData> m_priceData;

    // Helper function to load data from disk or resources
    bool loadData(QString ticker);
};

#endif // BACKTESTER_H
