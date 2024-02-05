#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

const int MAP_SIZE = 10;
const int QUEUE_SIZE = 100;     //BFS를 하며 각 node(방문한 위치)를 저장할 queue의 크기

int bfs(char map[][MAP_SIZE], int *x_start, int *y_start);      //최단경로를 탐색하기 위한 BFS 알고리즘을 구현한 함수
bool bfs_finish(int q_x[], int q_y[], int *front, char map[][MAP_SIZE], bool get_key);      //key or exit에 도착했는지 확인하는 함수
void inqueue(int q_x[], int q_y[], int *rear, int x, int y);
void dequeue(int q_x[], int q_y[], int *front);


using namespace std;

int main()
{
    char map[MAP_SIZE][MAP_SIZE];       //파일에서 읽어올 지도를 저장하기 위한 이차원 배열

    ifstream indata("input.txt");

    if(!indata.is_open())
    {
        cout << "could not open the file " << endl;
        cout << "program terminating" << endl;
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j< MAP_SIZE; j++)
            indata >> map[i][j];
    }

    int x_start = 0, y_start = 0;    //경로 탐색을 시작하는 좌표

    int length_key = bfs(map, &x_start, &y_start);      //시작점부터 key까지 최단거리
    int length_exit = bfs(map, &x_start, &y_start);     //key부터 exit까지 최단거리

    ofstream outdata("output.txt");
    outdata << length_key + length_exit;

    indata.close();
    outdata.close();
}


int bfs(char map[][MAP_SIZE], int *x_start, int *y_start)
{
    //해당 node에서 상하좌우의 인접 node를 탐색하기 위한 배열
    int x_dis[4] = { -1, 0, 1, 0};
    int y_dis[4] = { 0, 1, 0, -1};

    char path_record[MAP_SIZE][MAP_SIZE];    //갈 수 없는 node('1') = 2, 갈 수 있는 node('0', '1', '2') = 0 으로 저장
    int path_length[MAP_SIZE][MAP_SIZE];    //각 node와 시작점 부터의 거리를 해당 node에 저장

    bool get_key = false;       //key 획득 여부를 판단하기 위한 변수

    if(map[*x_start][*y_start] == 'k') get_key = true;

    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j < MAP_SIZE; j++)
        {
            if(map[i][j] == '1')
            {
                path_length[i][j] = 1;
                path_record[i][j] = '2';
            }
            else
            {
                path_length[i][j] = 0;
                path_record[i][j] = '0';
            }
        }
    }

    //node의 위치를 저장하기 위한 queue를 배열로 구현
    int queue_x[QUEUE_SIZE] = {0, };
    int queue_y[QUEUE_SIZE] = {0, };
    int front = 0, rear = 0;
    
    inqueue(queue_x, queue_y, &rear, *x_start, *y_start);       //start node inqueue

    while(!bfs_finish(queue_x, queue_y, &front, map, get_key))
    {
        path_record[queue_x[front]][queue_y[front]] = '2';      //중복 방지를 위해 방문한 node는 2로 표시
        
        for(int i = 0; i < 4; i++)
        {
            int del_x = queue_x[front] + x_dis[i];
            int del_y = queue_y[front] + y_dis[i];
            
            if((del_x >= 0 && del_x < MAP_SIZE) && (del_y >= 0 && del_y < MAP_SIZE) && path_record[del_x][del_y] == '0')
            {
                inqueue(queue_x, queue_y, &rear, del_x, del_y);     //큐에 해당 좌표 넣기(inqueue)
                path_record[del_x][del_y] = '1';        //queue에 넣은 node는 1로 표시
                path_length[del_x][del_y] = path_length[del_x - x_dis[i]][del_y - y_dis[i]] + 1;
            }
        }
        dequeue(queue_x, queue_y, &front);  //방문한 node delete
    }

    *x_start = queue_x[front];
    *y_start = queue_y[front];

    return path_length[*x_start][*y_start];
}

bool bfs_finish(int q_x[], int q_y[], int *front, char map[][MAP_SIZE], bool get_key)
{
    int x = q_x[*front], y = q_y[*front];

    if((map[x][y] == 'k' && get_key == false) || (map[x][y] == 'e' && get_key == true))
        return true;
    else return false;
}

void inqueue(int q_x[], int q_y[], int *rear, int x, int y)
{
    q_x[*rear] = x;
    q_y[*rear] = y;
    *rear = (*rear + 1) % QUEUE_SIZE;
}

void dequeue(int q_x[], int q_y[], int *front)
{
    q_x[*front] = 0;
    q_y[*front] = 0;
    *front = (*front + 1) % QUEUE_SIZE;
}