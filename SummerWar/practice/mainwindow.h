#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <stack>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void numButtonToText();

    void actButtonToText();

    void simpleActButtonToText();

    void on_pushButton_c_clicked();

    void on_pushButton_rav_clicked();

    void on_pushButton_bs_clicked();

    void keyPressEvent(QKeyEvent *event);

    void write(QString input);

    void on_pushButton_pow_clicked();

    void on_pushButton_kor_clicked();

private:
    Ui::MainWindow *ui;
    bool act_check(char a);
    void calctostack(std::stack<double> &num, std::stack<char> &act);
    double calc(double num1, double num2, char act);
    int priority(char act);
    bool input_error(std::string input);
    double mainFunc(std::string input);
};

#endif // MAINWINDOW_H
