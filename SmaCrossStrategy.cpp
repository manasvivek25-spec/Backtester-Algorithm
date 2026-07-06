#include "SmaCrossStrategy.h"

SmaCrossStrategy::SmaCrossStrategy(int shortPeriod, int longPeriod)
    : m_shortPeriod(shortPeriod), m_longPeriod(longPeriod)
{
    // Constructor initializes members
}

QString SmaCrossStrategy::getName() const
{
    return QString("%1-day vs %2-day SMA Crossover").arg(m_shortPeriod).arg(m_longPeriod);
}

void SmaCrossStrategy::run(const QVector<StockData>& priceData,
                           double& cash,
                           double& lastBuyPrice,
                           int& totalTrades,
                           int& winningTrades,
                           int& losingTrades)
{
    if (priceData.size() < m_longPeriod + 1) return;

    double shares = 0;
    bool inPosition = false; // <-- 1. Use a boolean flag, just like in RSI/BB

    for (int i = m_longPeriod; i < priceData.size(); ++i) {
        double smaShort = calculateSMA(priceData, i, m_shortPeriod);
        double smaLong = calculateSMA(priceData, i, m_longPeriod);
        double prevSmaShort = calculateSMA(priceData, i - 1, m_shortPeriod);
        double prevSmaLong = calculateSMA(priceData, i - 1, m_longPeriod);

        // Golden Cross (BUY)
        if (smaShort > smaLong && prevSmaShort <= prevSmaLong) {
            if (!inPosition) { // <-- 2. Only buy if we are NOT in a position
                shares = cash / priceData[i].close;
                lastBuyPrice = priceData[i].close;
                cash = 0;
                inPosition = true; // <-- 3. Mark that we are IN the market
            }
        }
        // Death Cross (SELL)
        else if (smaShort < smaLong && prevSmaShort >= prevSmaLong) {
            if (inPosition) { // <-- 4. Only sell if we ARE in a position
                double sellPrice = priceData[i].close;
                if (sellPrice > lastBuyPrice) winningTrades++;
                else losingTrades++;

                cash = shares * sellPrice;
                shares = 0;
                totalTrades++;
                inPosition = false; // <-- 5. Mark that we are OUT of the market
            }
        }
    }
    
    // Sell any remaining shares at the end
    if (inPosition) { // <-- 6. Use the boolean flag
        cash = shares * priceData.last().close;
        shares = 0;
        // We don't count this as a "trade" since it's an end-of-test liquidation
    }
}

// --- Helper Functions (Unchanged) ---

double SmaCrossStrategy::calculateSMA(const QVector<StockData>& priceData, int currentIndex, int period) const
{
    if (currentIndex < period - 1) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < period; ++i) {
        sum += priceData[currentIndex - i].close;
    }
    return sum / period;
}

double SmaCrossStrategy::calculateSMA(const QVector<double>& data) const
{
    if (data.isEmpty()) return 0.0;
    double sum = 0.0;
    for (double val : data) {
        sum += val;
    }
    return sum / data.size();
}