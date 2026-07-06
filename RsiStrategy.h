#ifndef RSISTRATEGY_H
#define RSISTRATEGY_H

#include "IStrategy.h"

class RsiStrategy : public IStrategy
{
public:
    RsiStrategy(int period, int oversold, int overbought);

    virtual QString getName() const override;
    virtual void run(const QVector<StockData>& priceData,
                     double& cash,
                     double& lastBuyPrice,
                     int& totalTrades,
                     int& winningTrades,
                     int& losingTrades) override;

private:
    // Helper function to calculate all RSI values
    QVector<double> calculateRSI(const QVector<StockData>& priceData) const;

    int m_period;
    int m_oversold;
    int m_overbought;
};

#endif // RSISTRATEGY_H