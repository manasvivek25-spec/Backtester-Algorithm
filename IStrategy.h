#ifndef ISTRATEGY_H
#define ISTRATEGY_H

#include "StockData.h"
#include <QVector>
#include <QString>

// This is an "Interface" class. It defines what a strategy
// *must* be able to do, but doesn't implement it.
class IStrategy
{
public:
    // Virtual destructor (good practice for base classes)
    virtual ~IStrategy() {}

    // Pure virtual functions (must be overridden)
    
    // Returns the name of the strategy for the report
    virtual QString getName() const = 0;

    // This is the main function that runs the backtest loop
    // It takes the data and "returns" the results by modifying
    // the variables that are passed by reference.
    virtual void run(const QVector<StockData>& priceData,
                     double& cash,
                     double& lastBuyPrice,
                     int& totalTrades,
                     int& winningTrades,
                     int& losingTrades) = 0;
};

#endif // ISTRATEGY_H