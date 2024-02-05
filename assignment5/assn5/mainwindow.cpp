#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game_initialize();

    t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(timer_event()));    //타이머 slot 함수와 연결
    t->start(1000);

    ui->lineEdit->installEventFilter(this);         //lineEdit에 이벤트 필터 적용
}


MainWindow::~MainWindow()
{
    delete ui;
    delete t;
}

void MainWindow::game_initialize()
{
    ui->lcdNumber->display(30);
    ui->lcdNumber_2->display(0);
    ui->lineEdit->clear();
    word_num = 0;

    std::fill_n(word_list, 6, "");
    std::fill_n(x, 6, 0);
    std::fill_n(y, 6, 60);
    std::fill_n(level, 6, 0);

    DrawWord_e(0);
    DrawWord_e(1);
    DrawWord_e(2);
    DrawWord_e(3);
    DrawWord_e(4);
    DrawWord_e(5);
}

void MainWindow::DrawWord_c(int idx)
{
    if(idx == 0)
    {
        ui->label_3->setStyleSheet("QLabel { color : red; }");
        ui->label_3->setText(word_list[idx]);
        ui->label_3->move(x[idx], y[idx]);
    }
    else if(idx == 1)
    {
        ui->label_4->setStyleSheet("QLabel { color : red; }");
        ui->label_4->setText(word_list[idx]);
        ui->label_4->move(x[idx], y[idx]);
    }
    else if(idx == 2)
    {
        ui->label_5->setStyleSheet("QLabel { color : red; }");
        ui->label_5->setText(word_list[idx]);
        ui->label_5->move(x[idx], y[idx]);
    }
    else if(idx == 3)
    {
        ui->label_6->setStyleSheet("QLabel { color : red; }");
        ui->label_6->setText(word_list[idx]);
        ui->label_6->move(x[idx], y[idx]);
    }
    else if(idx == 4)
    {
        ui->label_7->setStyleSheet("QLabel { color : red; }");
        ui->label_7->setText(word_list[idx]);
        ui->label_7->move(x[idx], y[idx]);
    }
    else if(idx == 5)
    {
        ui->label_8->setStyleSheet("QLabel { color : red; }");
        ui->label_8->setText(word_list[idx]);
        ui->label_8->move(x[idx], y[idx]);
    }
}

void MainWindow::DrawWord_e(int idx)
{
    if(idx == 0)
    {
        ui->label_3->setStyleSheet("QLabel { color : black; }");
        ui->label_3->setText(word_list[idx]);
        ui->label_3->move(x[idx], y[idx]);
    }
    else if(idx == 1)
    {
        ui->label_4->setStyleSheet("QLabel { color : black; }");
        ui->label_4->setText(word_list[idx]);
        ui->label_4->move(x[idx], y[idx]);
    }
    else if(idx == 2)
    {
        ui->label_5->setStyleSheet("QLabel { color : black; }");
        ui->label_5->setText(word_list[idx]);
        ui->label_5->move(x[idx], y[idx]);
    }
    else if(idx == 3)
    {
        ui->label_6->setStyleSheet("QLabel { color : black; }");
        ui->label_6->setText(word_list[idx]);
        ui->label_6->move(x[idx], y[idx]);
    }
    else if(idx == 4)
    {
        ui->label_7->setStyleSheet("QLabel { color : black; }");
        ui->label_7->setText(word_list[idx]);
        ui->label_7->move(x[idx], y[idx]);
    }
    else if(idx == 5)
    {
        ui->label_8->setStyleSheet("QLabel { color : black; }");
        ui->label_8->setText(word_list[idx]);
        ui->label_8->move(x[idx], y[idx]);
    }
}

void MainWindow::creatWord()
{
    for(int i = 0; i < 6; i++)
    {
        if(word_list[i].isEmpty())
        {
            x[i] = rand()%700 + 10;             //단어의 x좌표 초기화

            if(rand()%10 >= 8)                  //20% 확률로 어려운 단어
            {
                level[i] = 1;
                word_list[i] = crazy_words[rand()%10];
                DrawWord_c(i);
            }
            else
            {
                level[i] = 0;
                word_list[i] = easy_words[rand()%30];
                DrawWord_e(i);
            }
            break;
        }
    }
    word_num++;
}

void MainWindow::moveWord()
{
    for(int i = 0; i < 6; i++)
    {
        if(!word_list[i].isEmpty() && (level[i] == 1) && (y[i] <= 250))        //index가 crasy word인 동시에 단어가 중앙 이전에 존재하는 경우
        {
            y[i] += 45;        //단어의 y좌표 이동

            if(i == 0)
                ui->label_3->move(x[i], y[i]);
            else if(i == 1)
                ui->label_4->move(x[i], y[i]);
            else if(i == 2)
                ui->label_5->move(x[i], y[i]);
            else if(i == 3)
                ui->label_6->move(x[i], y[i]);
            else if(i == 4)
                ui->label_7->move(x[i], y[i]);
            else if(i == 5)
                ui->label_8->move(x[i], y[i]);
        }
        else if(!word_list[i].isEmpty())        //위 경우를 제외하고 index에 단어가 존재하는 경우
        {
            y[i] += 30;        //단어의 y좌표 이동

            if(i == 0)
                ui->label_3->move(x[i], y[i]);
            else if(i == 1)
                ui->label_4->move(x[i], y[i]);
            else if(i == 2)
                ui->label_5->move(x[i], y[i]);
            else if(i == 3)
                ui->label_6->move(x[i], y[i]);
            else if(i == 4)
                ui->label_7->move(x[i], y[i]);
            else if(i == 5)
                ui->label_8->move(x[i], y[i]);
        }
    }
}

bool MainWindow::missingWord()
{
    bool judg = false;          //놓친 단어가 있는지 저장하는 변수

    for(int i = 0; i < 6; i++)
    {
        if(y[i] >= 430)
        {
            word_list[i] = "";
            x[i] = 0;
            y[i] = 60;
            level[i] = 0;
            DrawWord_e(i);
            word_num--;
            judg = true;
        }
    }
    return judg;
}

void MainWindow::timer_event()                    //타이머의 1000ms 당 시간 이벤트
{
    QMessageBox msgBox;
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    ui->lcdNumber->display(ui->lcdNumber->intValue() - 1);      //lcd에 1초 감소 표시

    if(missingWord())           //플레이어가 단어를 놓치는 경우
    {
        if(ui->lcdNumber->intValue() - 3 < 0)
            ui->lcdNumber_2->display(0);
        else
            ui->lcdNumber->display(ui->lcdNumber->intValue() - 3);
    }
    if(ui->lcdNumber->intValue() == 0)      //타이머가 0이 되는 경우
    {
        t->stop();
        int choice = QMessageBox::question(this, "Time Out", "Your score is " + QString::number(ui->lcdNumber_2->intValue()) + ".\nDo you want to try again?");

        if(choice == QMessageBox::Yes)
        {
            game_initialize();
            t->start();
        }
        else
        {
            this->close();
        }
    }
    if(word_num < 6)            //단어가 6개 미만인 경우
    {
        creatWord();
    }
    moveWord();
}

bool MainWindow::eventFilter(QObject* obj, QEvent *event)           //이벤트 필터
{
    if(obj == ui->lineEdit)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyE = static_cast<QKeyEvent*>(event);
            if(keyE->key() == Qt::Key_Enter)
            {
                ui->lineEdit->clear();
                return true;
            }
        }
    }
    return false;
}

void MainWindow::on_lineEdit_returnPressed()            //사용자 입력을 처리하는 함수
{
    int idx;

    for(int i = 0; i < 6; i++)
    {
        if(ui->lineEdit->text() == word_list[i])
        {
            idx = i;
            for(int j = i; j < 6; j++)
            {
                if(word_list[j] == word_list[idx])
                    idx = y[j] > y[idx] ? j : i;
            }

            if(level[idx] == 1)
                ui->lcdNumber_2->display(ui->lcdNumber_2->intValue() + 15);
            else
                ui->lcdNumber_2->display(ui->lcdNumber_2->intValue() + 10);

            word_list[idx] = "";
            x[idx] = 0;
            y[idx] = 60;
            level[idx] = 0;
            DrawWord_e(idx);
            word_num--;

            break;
        }
    }
    ui->lineEdit->clear();
}
