#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define up 0
#define down 1
#define left 2
#define right 3

typedef struct pos
{
    int y;
    int x;
} pos;

typedef struct node
{
    pos value;
    struct node* prev;
} node;

typedef struct queue
{
    int num;
    struct node* head;
    struct node* tail;
} queue;

bool is_queue_empty(queue* target)
{
    return target->num == 0;
}

void push(queue* target, pos value)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->value = value;
    if (is_queue_empty(target))
    {
        target->tail = new_node;
    }
    else
    {
        target->head->prev = new_node;
    }
    target->head = new_node;
    target->num++;
}

pos pop(queue* target)
{
    node* temp = target->tail;
    pos result = temp->value;
    target->tail = temp->prev;
    target->num--;
    if (is_queue_empty(target))
    {
        target->head = NULL;
    }
    free(temp);
    return result;
}

int main()
{
    pos loc_of_head = {1, 1};

    int size_of_board;
    scanf("%d", &size_of_board);

    int location_of_apple[101][101] = {0,};

    int apple;
    scanf("%d", &apple);

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int current_dir = 3;
    queue q = {};

    for (int i = 0; i < apple; i++)
    {
        int y, x;
        scanf("%d %d", &y, &x);
        location_of_apple[y][x] = true;
    }

    int number_of_turn;
    scanf("%d", &number_of_turn);

    char dir_change[10001] = {0,};

    for (int i = 0; i < number_of_turn; i++)
    {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        dir_change[x] = c;
    }

    int loc_of_snake[101][101] = {0,};

    push(&q, loc_of_head);
    loc_of_snake[1][1] = 1;

    for (int i = 1; i <= 10000; i++)
    {
        loc_of_head.x += dx[current_dir];
        loc_of_head.y += dy[current_dir];

        if (loc_of_head.x > size_of_board || loc_of_head.y > size_of_board ||
            loc_of_head.x < 1 || loc_of_head.y < 1 || loc_of_snake[loc_of_head.y][loc_of_head.x] == 1)
        {
            printf("%d", i);
            break;
        }

        push(&q, loc_of_head);
        loc_of_snake[loc_of_head.y][loc_of_head.x] = 1;

        if (location_of_apple[loc_of_head.y][loc_of_head.x] == true)
        {
            location_of_apple[loc_of_head.y][loc_of_head.x] = false;
        }
        else
        {
            pos temp = pop(&q);
            loc_of_snake[temp.y][temp.x] = 0;
        }
        if (dir_change[i] == 'L')
        {
            if (current_dir == up)
                current_dir = left;

            else if (current_dir == down)
                current_dir = right;

            else if (current_dir == left)
                current_dir = down;

            else
                current_dir = up;
        }
        else if (dir_change[i] == 'D')
        {
            if (current_dir == up)
                current_dir = right;

            else if (current_dir == down)
                current_dir = left;

            else if (current_dir == left)
                current_dir = up;

            else
                current_dir = down;
        }
    }

    return 0;
}