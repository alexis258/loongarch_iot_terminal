#ifndef BATT_H
#define BATT_H

#include <QWidget>
#include <QPainter>
#include <QtMath>
#include <QDebug>

class batt : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int value READ getValue WRITE setValue)
    Q_PROPERTY(int minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(int maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(int alarmValue READ getAlarmValue WRITE setAlarmValue)

public:
    explicit batt(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *) override;
    void resizeEvent(QResizeEvent *) override;

protected:
    void drawBorder(QPainter *painter);
    void drawRightHead(QPainter *painter);
    void drawBackground(QPainter *painter);
    void drawText(QPainter *painter);

public slots:
    void setValue(int value);           // 设置当前值
    void setMinValue(int min);          // 设置最小值
    void setMaxValue(int max);          // 设置最大值
    void setRange(int min,int max);     // 设置数值范围
    void setBorderWidth(int width);     // 设置边框宽度
    void setBorderRadio(int radio);     // 设置外边框圆角
    void setInRadio(int radio);         // 设置内部绘制区域圆角
    void setAlarmValue(int alarm);      // 设置警告值
    void setBorderColor(QColor color);  // 设置边框颜色
    int getValue();                     // 获取当前值
    int getMinValue();                  // 获取当前最小值
    int getMaxValue();                  // 获取当前最大值
    int getAlarmValue();                // 获取告警值

signals:

private:
    int borderWidth;                // 边缘线框宽度
    int headWidth;                  // 右侧头部宽度
    int value;                      // 当前值
    int minValue;                   // 最小值
    int maxValue;                   // 最大值
    int alarmValue;                 // 警告值
    int borderRadio;                // 外部边框圆角
    int drawInRadio;                // 内部绘制区域圆角
    QRectF borderRect;              // 电池区域
    QColor borderColor;
};

#endif // BATT_H
