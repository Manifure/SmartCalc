#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "1");
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "2");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "3");
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "4");
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "5");
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "6");
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "7");
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "8");
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "9");
}


void MainWindow::on_pushButton_0_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "0");
}


void MainWindow::on_pushButton_decimal_clicked()
{
    if(!ui->lineEdit->text().endsWith("."))
    {
        ui->lineEdit->setText(ui->lineEdit->text() + ".");
    }
}


void MainWindow::on_pushButton_plus_clicked()
{
    if(!ui->lineEdit->text().endsWith("+"))
    {
        ui->lineEdit->setText(ui->lineEdit->text() + "+");
    }
}


void MainWindow::on_pushButton_minus_clicked()
{
    if(!ui->lineEdit->text().endsWith("-"))
    {
        ui->lineEdit->setText(ui->lineEdit->text() + "-");
    }
}


void MainWindow::on_pushButton_multiply_clicked()
{
    if(!ui->lineEdit->text().endsWith("*"))
    {
        ui->lineEdit->setText(ui->lineEdit->text() + "*");
    }
}


void MainWindow::on_pushButton_equals_clicked()
{
    QTextStream out(stdout); //debug
    QString str = ui->lineEdit->text();
    out << str << Qt::endl; //debug
    QByteArray arr_chars = str.toLocal8Bit(); //конвертация QString
    char *ptr_arr_chars = arr_chars.data(); //        в char
    char result[256];
    calc_main(ptr_arr_chars,result);
    ui->lineEdit->setText(result);
    out << str << Qt::endl; //debug
}


void MainWindow::on_pushButton_division_clicked()
{
    if(!ui->lineEdit->text().endsWith("/"))
    {
        ui->lineEdit->setText(ui->lineEdit->text() + "/");
    }
}


void MainWindow::on_pushButton_percent_clicked()
{
    if(!ui->lineEdit->text().endsWith("%"))
    {
        ui->lineEdit->setText(ui->lineEdit->text() + "%");
    }
}


void MainWindow::on_pushButton_clean_clicked()
{
    ui->lineEdit->clear();
}


void MainWindow::on_pushButton_backspace_clicked()
{
    ui->lineEdit->backspace();
}


void MainWindow::on_pushButton_close_bracket_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ")");
}


void MainWindow::on_pushButton_open_bracket_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "(");
}


void MainWindow::on_pushButton_cos_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "cos(");
}


void MainWindow::on_pushButton_sin_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "sin(");
}


void MainWindow::on_pushButton_acos_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "acos(");
}


void MainWindow::on_pushButton_tan_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "tan(");
}


void MainWindow::on_pushButton_asin_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "asin(");
}


void MainWindow::on_pushButton_atan_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "atan(");
}


void MainWindow::on_pushButton_sqrt_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "sqrt(");
}


void MainWindow::on_pushButton_ln_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "ln(");
}


void MainWindow::on_pushButton_log_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "log(");
}


void MainWindow::on_pushButton_pow_clicked()
{
  if(!ui->lineEdit->text().endsWith("^"))
  {
    ui->lineEdit->setText(ui->lineEdit->text() + "^");
  }
}

