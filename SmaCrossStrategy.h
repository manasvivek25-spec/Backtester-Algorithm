#ifndef SMACROSSSTRATEGY_H
#define SMACROSSSTRATEGY_H

#include "IStrategy.h"

// This is a "Concrete" strategy that INHERITS from IStrategy
class SmaCrossStrategy : public IStrategy
{
public:
    // Constructor to pass in parameters
    SmaCrossStrategy(int shortPeriod, int longPeriod);

    // Overridden functions
    virtual QString getName() const override;
    virtual void run(const QVector<StockData>& priceData,
                     double& cash,
                     double& lastBuyPrice,
                     int& totalTrades,
                     int& winningTrades,
                     int& losingTrades) override;

private:
    // --- FUNCTION OVERLOADING ---
    // We demonstrate overloading by having two helpers
    // with the same name but different parameters.
    double calculateSMA(const QVector<StockData>& priceData, int currentIndex, int period) const;
    double calculateSMA(const QVector<double>& data) const; // A generic helper

    // --- ENCAPSULATION ---
    // Parameters are stored as private members
    int m_shortPeriod;
    int m_longPeriod;
};

#endif // SMACROSSSTRATEGY_H