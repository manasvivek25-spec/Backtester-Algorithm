#include "RsiStrategy.h"

RsiStrategy::RsiStrategy(int period, int oversold, int overbought)
    : m_period(period), m_oversold(oversold), m_overbought(overbought)
{
}

QString RsiStrategy::getName() const
{
    return QString("RSI(%1) Strategy (O/S: %2, O/B: %3)")
           .arg(m_period).arg(m_oversold).arg(m_overbought);
}

void RsiStrategy::run(const QVector<StockData>& priceData,
                      double& cash,
                      double& lastBuyPrice,
                      int& totalTrades,
                      int& winningTrades,
                      int& losingTrades)
{
    if (priceData.size() < m_period + 2) return; // Need at least 2 RSI values

    // 1. Get all RSI values
    QVector<double> rsiValues = calculateRSI(priceData);

    double shares = 0;
    bool inPosition = false; // Are we currently holding shares?

    // --- THE FIX IS HERE ---
    // We must start at m_period + 1 so that [i-1] is a valid RSI
    for (int i = m_period + 1; i < priceData.size(); ++i) {
        double rsi = rsiValues[i];
        double prevRsi = rsiValues[i-1]; // This is now a real RSI value
        
        // --- Buy/Sell Logic ---
        
        // BUY Signal (RSI crosses UP from oversold)
        if (rsi > m_oversold && prevRsi <= m_oversold && !inPosition) {
            if (cash > 0) {
                shares = cash / priceData[i].close;
                lastBuyPrice = priceData[i].close;
                cash = 0;
                inPosition = true;
            }
        }
        // SELL Signal (RSI crosses DOWN from overbought)
        else if (rsi < m_overbought && prevRsi >= m_overbought && inPosition) {
            if (shares > 0) {
                double sellPrice = priceData[i].close;
                
                if (sellPrice > lastBuyPrice) winningTrades++;
                else losingTrades++;
                
                cash = shares * sellPrice;
                shares = 0;
                totalTrades++;
                inPosition = false;
            }
        }
    }
    
    // Sell any remaining shares at the end
    if (shares > 0) {
        cash = shares * priceData.last().close;
        shares = 0;
    }
}


// --- This helper function is unchanged, but included for completeness ---
QVector<double> RsiStrategy::calculateRSI(const QVector<StockData>& priceData) const
{
    QVector<double> rsiValues(priceData.size(), 0.0);
    if (priceData.size() <= m_period) return rsiValues;

    double avgGain = 0.0;
    double avgLoss = 0.0;

    // First, calculate the initial average gain/loss for the first 'period'
    for (int i = 1; i <= m_period; ++i) {
        double change = priceData[i] - priceData[i - 1]; 
        
        if (change > 0) {
            avgGain += change;
        } else {
            avgLoss += -change; // (as a positive number)
        }
    }
    avgGain /= m_period;
    avgLoss /= m_period;

    double rs = (avgLoss == 0) ? 100.0 : (avgGain / avgLoss);
    rsiValues[m_period] = 100.0 - (100.0 / (1.0 + rs));

    // Now, calculate the rest using the smoothed method
    for (int i = m_period + 1; i < priceData.size(); ++i) {
        double change = priceData[i] - priceData[i - 1];
        
        double gain = (change > 0) ? change : 0.0;
        double loss = (change < 0) ? -change : 0.0;

        // The smoothing formula
        avgGain = (avgGain * (m_period - 1) + gain) / m_period;
        avgLoss = (avgLoss * (m_period - 1) + loss) / m_period;

        rs = (avgLoss == 0) ? 100.0 : (avgGain / avgLoss);
        rsiValues[i] = 100.0 - (100.0 / (1.0 + rs));
    }
    
    return rsiValues;
}