#ifndef BOLLINGERBANDSSTRATEGY_H
#define BOLLINGERBANDSSTRATEGY_H

#include "IStrategy.h"

// Concrete strategy for Bollinger Bands
class BollingerBandsStrategy : public IStrategy
{
public:
    // Constructor to pass in parameters
    BollingerBandsStrategy(int period, double stdDevMultiplier);

    // Overridden functions
    virtual QString getName() const override;
    virtual void run(const QVector<StockData>& priceData,
                     double& cash,
                     double& lastBuyPrice,
                     int& totalTrades,
                     int& winningTrades,
                     int& losingTrades) override;

private:
    // Helper functions encapsulated within this class
    double calculateSMA(const QVector<StockData>& priceData, int currentIndex, int period) const;
    double calculateStdDev(const QVector<StockData>& priceData, int currentIndex, int period) const;

    // Encapsulated parameters
    int m_period;
    double m_stdDevMultiplier;
};

#endif // BOLLINGERBANDSSTRATEGY_H