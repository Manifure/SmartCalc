#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QTextStream>
#include <QVector>
#include <QtMath>

extern "C" {
#include "smartcalc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_1_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_9_clicked();

  void on_pushButton_0_clicked();

  void on_pushButton_decimal_clicked();

  void on_pushButton_plus_clicked();

  void on_pushButton_minus_clicked();

  void on_pushButton_multiply_clicked();

  void on_pushButton_equals_clicked();

  void on_pushButton_division_clicked();

  void on_pushButton_percent_clicked();

  void on_pushButton_clean_clicked();

  void on_pushButton_backspace_clicked();

  void on_pushButton_close_bracket_clicked();

  void on_pushButton_open_bracket_clicked();

  void on_pushButton_cos_clicked();

  void on_pushButton_sin_clicked();

  void on_pushButton_acos_clicked();

  void on_pushButton_tan_clicked();

  void on_pushButton_asin_clicked();

  void on_pushButton_atan_clicked();

  void on_pushButton_sqrt_clicked();

  void on_pushButton_ln_clicked();

  void on_pushButton_log_clicked();

  void on_pushButton_pow_clicked();

 private:
  Ui::MainWindow *ui;
  double xBegin, xEnd, h, X;
  int n;

  QVector<double> x, y;
};
#endif  // MAINWINDOW_H
