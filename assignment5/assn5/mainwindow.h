#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <QLineEdit>
#include <QKeyEvent>
#include <QApplication>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void timer_event();     //타이머 업데이트
    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    QTimer* t;

    int word_num;           //현재 화면에 있는 단어의 개수를 세는 변수
    QString word_list[6];           //단어를 저장하는 변수
    int x[6] = {0, };               //단어의 x좌표를 저장하는 배열
    int y[6] = {60, 60, 60, 60, 60, 60};            //단어의 y좌표를 저장하는 배열
    int level[6] = {0, };           //idx에 해당하는 단어의 난이도를 저장하는 배열

    QString easy_words[30]= {"명징","직조", "갈증","비행기","나흗날","비둘기"
                             , "옹달샘", "줄이다", "거울", "집오리", "물리학", "토마토", "올리브", "은박지"
                             , "문지방", "물병", "양치질", "어린이", "집무실", "달빛", "다르다", "부고", "낫"
                             , "서당", "참외", "사다리", "천지", "인바디", "어금니", "추격"};
    QString crazy_words[10]= {"숨마쿰라우데", "우거지다", "토지소유권", "하염없다",
                              "도톰하다", "넓적부리", "타란티노", "방울토마토", "객체지향수업", "컴퓨터공학과" };

    void game_initialize();     //게임 시작으로 초기화 하는 함수
    void creatWord();           //조건에 맞게 단어를 만들어 주는 함수
    void moveWord();            //출력된 단어를 y축 방향으로 움직여주는 함수
    bool missingWord();         //플레이어가 단어를 놓쳤는지 판별하는 함수
    void DrawWord_c(int);         //crazy 단어를 그려주는 함수
    void DrawWord_e(int);         //easy 단어를 그려주는 함수

    bool eventFilter(QObject* obj, QEvent* event);
};
#endif // MAINWINDOW_H
