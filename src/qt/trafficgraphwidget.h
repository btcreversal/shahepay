// Copyright (c) 2011-2015 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Raven Core developers
// Copyright (c) 2020-2021 The shahepay Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SHAHEPAY_QT_TRAFFICGRAPHWIDGET_H
#define SHAHEPAY_QT_TRAFFICGRAPHWIDGET_H

#include <QWidget>
#include <QQueue>

class ClientModel;

QT_BEGIN_NAMESPACE
class QPaintEvent;
class QTimer;
QT_END_NAMESPACE

class TrafficGraphWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrafficGraphWidget(QWidget *parent = 0);
    void setClientModel(ClientModel *model);
    int getGraphRangeMins() const;

protected:
    void paintEvent(QPaintEvent *);

public Q_SLOTS:
    void updateRates();
    void setGraphRangeMins(int mins);
    void clear();

private:
    void paintPath(QPainterPath &path, QQueue<float> &samples);

    QTimer *timer;
    float fMax;
    int nMins;
    QQueue<float> vSamplesIn;
    QQueue<float> vSamplesOut;
    quint64 nLastBytesIn;
    quint64 nLastBytesOut;
    ClientModel *clientModel;
};

#endif // SHAHEPAY_QT_TRAFFICGRAPHWIDGET_H
