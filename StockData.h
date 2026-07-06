#ifndef STOCKDATA_H
#define STOCKDATA_H

#include <QDate>
#include <QDebug>

struct StockData {
    QDate date;
    double open;
    double high;
    double low;
    double close;

    // --- ARITHMETIC OPERATOR OVERLOADING ---
    // Overloads the subtraction operator.
    // This allows you to write: double change = stock[i] - stock[i-1];
    // It returns the change in the closing price.
    double operator-(const StockData& other) const {
        return this->close - other.close;
    }
};

// --- DEBUG OPERATOR OVERLOADING ---
// This lets you write: qDebug() << myStockData;
inline QDebug operator<<(QDebug dbg, const StockData &data)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "StockData("
                  << data.date.toString("yyyy-MM-dd") << ", "
                  << "C: " << data.close
                  << ")";
    return dbg;
}

#endif // STOCKDATA_H