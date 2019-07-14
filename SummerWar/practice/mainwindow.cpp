#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stack>
#include <string>
#include <cstring>
#include <QPushButton>
#include <QString>
#include <QKeyEvent>
#include <QLabel>
#include <QPainter>

using namespace std;

static bool pow_click = false;
static QString buff;
static QString rootstring;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    setCentralWidget(ui->centralWidget);
    QMainWindow m;
    centralWidget()->setStyleSheet(" QWidget {"
                                   "background: white;"
                                   "font-family:Helvetica"
                                   "}"
                                   "QPushButton {"
                                   ""
                                   "}"
                                   "QPushButton#num {"
                                   "background-color: #444444;"
                                   "border-style: outset;"
                                   "border-radius: 30px;"
                                   "border-color: black;"
                                   "font: 20px;"
                                   "color: white;"
                                   "padding: 6px; "
                                   "}"
                                   "QPushButton#num:pressed {"
                                   "background-color: #383838"
                                   "}"
                                   "QPushButton#act {"
                                   "background-color: #636363;"
                                   "border-style: outset;"
                                   "border-radius: 30px;"
                                   "border-color: black;"
                                   "font: 20px;"
                                   "color: white;"
                                   "padding: 6px; "
                                   "}"
                                   "QPushButton#act:pressed {"
                                   "background-color:#595959"
                                   "}"
                                   "QPushButton#act2 {"
                                   "background-color: #61C4A8;"
                                   "border-style: outset;"
                                   "border-radius: 30px;"
                                   "border-color: black;"
                                   "font: 20px;"
                                   "color: white;"
                                   "padding: 6px; "
                                   "}"
                                   "QPushButton#act2:pressed {"
                                   "background-color: #49bc9b;"
                                   "}"
                                   "QPushButton#act3 {"
                                   "background-color: #A6A6A6;"
                                   "border-style: outset;"
                                   "border-radius: 30px;"
                                   "border-color: black;"
                                   "font: 20px;"
                                   "padding: 6px; "
                                   "}"
                                   "QPushButton#act3:pressed {"
                                   "background-color: #949494"
                                   "}"
                                   "QLabel#label {"
                                   "font: 16pt;"
                                   "color:black;"
                                   "background:white;"
                                   "border-radius:30px;"
                                   "}"
                                   "QLabel#powlabel {"
                                   "font: 16pt;"
                                   "background-color: rgba(0,0,0,0%)"
                                   "}");
    ui->pushButton_00->setObjectName("num");
    ui->pushButton_0->setObjectName("num");
    ui->pushButton_1->setObjectName("num");
    ui->pushButton_2->setObjectName("num");
    ui->pushButton_3->setObjectName("num");
    ui->pushButton_4->setObjectName("num");
    ui->pushButton_5->setObjectName("num");
    ui->pushButton_6->setObjectName("num");
    ui->pushButton_7->setObjectName("num");
    ui->pushButton_8->setObjectName("num");
    ui->pushButton_9->setObjectName("num");
    ui->pushButton_dot->setObjectName("num");
    ui->pushButton_del->setObjectName("act");
    ui->pushButton_sum->setObjectName("act");
    ui->pushButton_min->setObjectName("act");
    ui->pushButton_umn->setObjectName("act");
    ui->pushButton_sin->setObjectName("act2");
    ui->pushButton_cos->setObjectName("act2");
    ui->pushButton_tan->setObjectName("act2");
    ui->pushButton_log->setObjectName("act2");
    ui->pushButton_ln->setObjectName("act2");
    ui->pushButton_ls->setObjectName("act2");
    ui->pushButton_rs->setObjectName("act2");
    ui->pushButton_pi->setObjectName("act2");
    ui->pushButton_e->setObjectName("act2");
    ui->pushButton_kor->setObjectName("act2");
    ui->pushButton_pow->setObjectName("act2");
    ui->pushButton_c->setObjectName("act2");
    ui->pushButton_bs->setObjectName("act3");
    ui->pushButton_rav->setObjectName("act3");

    connect(ui->pushButton_00,SIGNAL(clicked()),this,SLOT(numButtonToText()));
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(numButtonToText()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(numButtonToText()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(numButtonToText()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(numButtonToText()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(numButtonToText()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(numButtonToText()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(numButtonToText()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(numButtonToText()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(numButtonToText()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(numButtonToText()));
    connect(ui->pushButton_del,SIGNAL(clicked()),this,SLOT(simpleActButtonToText()));
    connect(ui->pushButton_sum,SIGNAL(clicked()),this,SLOT(simpleActButtonToText()));
    connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(simpleActButtonToText()));
    connect(ui->pushButton_umn,SIGNAL(clicked()),this,SLOT(simpleActButtonToText()));
    connect(ui->pushButton_dot,SIGNAL(clicked()),this,SLOT(numButtonToText()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(actButtonToText()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(actButtonToText()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(actButtonToText()));
    connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(actButtonToText()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(actButtonToText()));
    connect(ui->pushButton_ls,SIGNAL(clicked()),this,SLOT(actButtonToText()));
    connect(ui->pushButton_rs,SIGNAL(clicked()),this,SLOT(actButtonToText()));
    connect(ui->pushButton_pi,SIGNAL(clicked()),this,SLOT(actButtonToText()));
    connect(ui->pushButton_e,SIGNAL(clicked()),this,SLOT(actButtonToText()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    QString str = QString(QChar(event->key()));
    if ((event->key()>=Qt::Key_0 && event->key()<=Qt::Key_9) || event->key() == Qt::Key_ParenLeft || event->key() == Qt::Key_ParenRight || event->key() == Qt::Key_Plus
            || event->key() == Qt::Key_Minus || event->key() == Qt::Key_Slash || event->key() == Qt::Key_Asterisk || event->key() == Qt::Key_Period) {
        write(str);
    } else if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Equal) {
        on_pushButton_rav_clicked();
    } else if(event->key() == Qt::Key_Backspace) {
        on_pushButton_bs_clicked();
    } else if(event->key() == Qt::Key_Delete) {
        on_pushButton_c_clicked();
    }
    update();
}

void MainWindow::numButtonToText() {
    QPushButton *button = static_cast<QPushButton*>(sender());
    write(button->text());
}

void MainWindow::simpleActButtonToText() {
    QPushButton *button = static_cast<QPushButton*>(sender());
    pow_click = false;
    write(button->text());
}

void MainWindow::actButtonToText() {
    QPushButton *button = static_cast<QPushButton*>(sender());
    write(button->text());
}


void MainWindow::on_pushButton_pow_clicked()
{
    pow_click = true;
    write("^");
}

void MainWindow::write(QString input) {
    if (pow_click == false) {
        if(input == "√") {
            buff = buff + "%";
            ui->label->setText(ui->label->text() + input);
        } else {
       buff = buff + input;
       ui->label->setText(ui->label->text() + input); }
    } else {
        if (input == "^") {
            buff = buff + input;
        } else {
            buff = buff + input;
            ui->label->setText(ui->label->text() + "<sup>" + input + "</sup>");
        }
    }
}


void MainWindow::on_pushButton_c_clicked()
{
    pow_click = false;
    buff.clear();
    ui->label->clear();
    ui->error_label->clear();
}

void MainWindow::on_pushButton_bs_clicked()
{
    if(buff.length() != 0) {
    QString temp = ui->label->text();
        if (temp[temp.length() - 1] != '>') {
            buff.resize(buff.length() - 1);
            temp.resize(temp.length() - 1);
            ui->label->setText(buff);
            pow_click = false;
        } else {
            buff.resize(buff.length() - 1);
            temp.resize(temp.length() - 12);
            ui->label->setText(temp);
            pow_click = true;
        }
    }
}

void MainWindow::on_pushButton_rav_clicked()
{
    QString result;
    string input = buff.toLocal8Bit().constData();
    if(input_error(input) == true) {
        ui->error_label->setStyleSheet("QLabel {color : black; font-size : 10pt; }");
        ui->error_label->setText("Некорректное выражение. Введите заново");
    } else {
        result = QString::fromStdString(to_string(mainFunc(input)));
        int i = result.length() - 1;
        while (result[i] == '0' && i > 0) {
            if (result[i-1] == '.') result.resize(i-1);
            else result.resize(i);
            i--;
        }
        ui->label->setText(ui->label->text() + " = " + result);
    }

}


void MainWindow::on_pushButton_kor_clicked()
{
    QString root_flipped = "";
    QString root;
    QString forroot = buff;
    int i = forroot.length() - 1;
    while (i >= 0 && buff[i] != '+' && buff[i] != '-' && buff[i] != '*' && buff[i] != '/' && buff[i] != '^') {
        root_flipped += forroot[i];
        forroot[i] = ' ';
        i--;
    }
    root.resize(root_flipped.length());
    for (i = 0; i < root_flipped.length(); i++) {
         root[root.length() - 1 - i] = root_flipped[i];
    }
    ui->label->setText(forroot + "<sup>" + root + "</sup>");
    write("√");
}


int MainWindow::priority(char act) {
    if (act == 's' || act == 'c' || act == 't' || act == 'l' || act == 'n') return 3;
    if (act == '*' || act == '/' || act == '^' || act == '%') return 2;
    if (act == '+' || act == '-') return 1;
    return 0;
}

double MainWindow::calc(double num1, double num2, char act) {
    switch (act) {
    case 'n': return log10(num2);
    case 'l': return log(num2);
    case 't': return tan(num2 * 3.14159265 / 180);
    case 's': return sin(num2 * 3.14159265 / 180);
    case 'c': return cos(num2 * 3.14159265 / 180);
    case '%': return pow(num2, 1 / num1);
    case '^': return pow(num1, num2);
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return num1 / num2;
    }
}

bool MainWindow::act_check(char a) {
    if (a == '+' || a == '/' || a == '*' || a == '^' || a == '%') return true;
    return false;
}

bool MainWindow::input_error(string input) {

    bool dot = false;
    int lb_count = 0, rb_count = 0;
    if (input.length() == 0) return true;
    for (unsigned int i = 0; i < input.length(); i++) {
        if (act_check(input[0])) return true;
        if (act_check(input[input.length() - 1]) && input[i] != '-') return true;
        if (act_check(input[i]) && act_check(input[i + 1])) return true;
        if (input[i] == '.' && act_check(input[i + 1])) return true;
        if (i > 0 && input[i] == '.' && !isdigit(input[i - 1])) return true;
        if (input[0] == '.' || input[input.length() - 1] == '.') return true;
        if (input[i] == '(') lb_count++;
        if (input[i] == ')') rb_count++;
        if (isdigit(input[i]) && input[i + 1] == '(') return true;
        if (input[i] == '.') {
            if (dot == true) return true;
            else {
                dot = true;
                continue;
            }
        }
        if (act_check(input[i]) && input[i] != '-') dot = false;
        if (input[i] == 's' && input[i+1] == 'i' && input[i + 2] == 'n' && (!isdigit(input[i+3]) || input[i+3] == '.' || input[i+3] == ')')) return true;
        if (input[i] == 'c' && input[i+1] == 'o' && input[i + 2] == 's' && (!isdigit(input[i+3]) || input[i+3] == '.' || input[i+3] == ')')) return true;
        if (input[i] == 't' && input[i+1] == 'a' && input[i + 2] == 'n' && (!isdigit(input[i+3]) || input[i+3] == '.' || input[i+3] == ')')) return true;
        if (input[i] == 'l' && input[i+1] == 'o' && input[i + 2] == 'g' && (!isdigit(input[i+3]) || input[i+3] == '.' || input[i+3] == ')')) return true;
        if (input[i] == 'l' && input[i+1] == 'n' && (!isdigit(input[i+3]) || input[i+2] == '.' || input[i+2] == ')')) return true;
    }
    if (lb_count != rb_count) return true;
    return false;
}

void MainWindow::calctostack(stack<double> &num, stack<char> &act) {
    double num2 = num.top();
    num.pop();
    double num1 = num.top();
    num.pop();
    char op = act.top();
    act.pop();
    num.push(calc(num1, num2, op));
}

double MainWindow::mainFunc(string input) {
    stack<double> num;
    stack<char> act;
    double fraction = 1;
    bool minus = false;

    for (unsigned int i = 0; i < input.length(); i++) {
        //minus=false;
        if (input[i] == ' ') {
            continue;
        }
        if (input[i] == '-') {
            minus = true;
            i++;
        }
        if (input[i] == '(') {
            act.push(input[i]);
        }
        if (input[i] == 'e') {
            num.push(exp(1));
        }
        if (input[i] == 'p' && input[i + 1] == 'i') {
            num.push(3.14159265);
        }
        if (input[i] == 'l' && input[i + 1] == 'n') {
            act.push('l');
            num.push(1);
        }
        if (input[i] == 'l' && input[i + 1] == 'o' && input[i + 2] == 'g') {
            act.push('n');
            num.push(1);
        }
        if (input[i] == 's' && input[i + 1] == 'i' && input[i + 2] == 'n') {
            act.push('s');
            num.push(1);
        }
        if (input[i] == 'c' && input[i + 1] == 'o' && input[i + 2] == 's') {
            act.push('c');
            num.push(1);
        }
        if (input[i] == 't' && input[i + 1] == 'a' && input[i + 2] == 'n') {
            act.push('t');
            num.push(1);
        }

        if (isdigit(input[i])) {
            double temp = 0;
            while (i < input.length() && (isdigit(input[i]) || input[i] == '.')) {
                if (input[i] == '.') {
                    fraction = 10;
                    i++;
                    continue;
                }
                if (fraction == 1.0) {
                    temp = (temp * 10) + (input[i] - '0');
                    i++;
                }
                else {
                    temp = temp + ((input[i] - '0') / fraction);
                    fraction *= 10;
                    i++;
                }
            }
            if (minus == true) {
                num.push((-1)*temp);
                minus = false;
            }
            else num.push(temp);
        }
        if (input[i] == ')') {
            while (!act.empty() && act.top() != '(') {
                calctostack(num, act);
            }
            act.pop();
        }
        if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' || input[i] == '^' || input[i] == '%') {
            fraction = 1;
            while (!act.empty() && priority(act.top()) >= priority(input[i])) {
                calctostack(num, act);
            }
            act.push(input[i]);
        }

    }
    while (!act.empty()) {
        calctostack(num, act);
    }
    return num.top();
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_2->setText(buff);
}
