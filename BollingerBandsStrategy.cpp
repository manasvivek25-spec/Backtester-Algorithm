#include "BollingerBandsStrategy.h"
#include <cmath> // For std::sqrt

BollingerBandsStrategy::BollingerBandsStrategy(int period, double stdDevMultiplier)
    : m_period(period), m_stdDevMultiplier(stdDevMultiplier)
{
}

QString BollingerBandsStrategy::getName() const
{
    return QString("Bollinger Bands(%1, %2)").arg(m_period).arg(m_stdDevMultiplier);
}

void BollingerBandsStrategy::run(const QVector<StockData>& priceData,
                                 double& cash,
                                 double& lastBuyPrice,
                                 int& totalTrades,
                                 int& winningTrades,
                                 int& losingTrades)
{
    if (priceData.size() < m_period) return;

    double shares = 0;
    bool inPosition = false;

    for (int i = m_period - 1; i < priceData.size(); ++i) {
        
        // 1. Calculate Bands
        double sma = calculateSMA(priceData, i, m_period);
        double stdDev = calculateStdDev(priceData, i, m_period);
        double upperBand = sma + (stdDev * m_stdDevMultiplier);
        double lowerBand = sma - (stdDev * m_stdDevMultiplier);

        double currentPrice = priceData[i].close;
        
        // --- Buy/Sell Logic ---

        // BUY Signal (Price crossed BELOW the lower band)
        if (currentPrice < lowerBand && !inPosition) {
            if (cash > 0) {
                shares = cash / currentPrice;
                lastBuyPrice = currentPrice;
                cash = 0;
                inPosition = true;
            }
        }
        // SELL Signal (Price crossed ABOVE the upper band)
        else if (currentPrice > upperBand && inPosition) {
            if (shares > 0) {
                double sellPrice = currentPrice;

                if (sellPrice > lastBuyPrice) winningTrades++;
                else losingTrades++;

                cash = shares * sellPrice;
                shares = 0;
                totalTrades++;
                inPosition = false;
            }
        }
    }
    
    // At the end, sell any shares we're still holding
    if (shares > 0) {
        cash = shares * priceData.last().close;
        shares = 0;
    }
}

// --- Helper Functions ---

double BollingerBandsStrategy::calculateSMA(const QVector<StockData>& priceData, int currentIndex, int period) const
{
    if (currentIndex < period - 1) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < period; ++i) {
        sum += priceData[currentIndex - i].close;
    }
    return sum / period;
}

double BollingerBandsStrategy::calculateStdDev(const QVector<StockData>& priceData, int currentIndex, int period) const
{
    if (currentIndex < period - 1) return 0.0;
    
    double sma = calculateSMA(priceData, currentIndex, period);
    double sumOfSquares = 0.0;

    for (int i = 0; i < period; ++i) {
        double price = priceData[currentIndex - i].close;
        sumOfSquares += (price - sma) * (price - sma); // (price - mean)^2
    }

    double variance = sumOfSquares / period;
    return std::sqrt(variance);
}