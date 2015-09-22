#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int head;
  int tail;
  int size;
  char ** data;
} QUEUE;

int queue_next(int current, int SIZE) {
  return (current + 1) % SIZE;
}

char queue_isFull(QUEUE * queue) {
  return queue_next(queue->tail, queue->size) == queue->head;
}

char queue_isEmpty(QUEUE * queue) {
  return queue->head == queue->tail;
}

void queue_add(QUEUE * queue, char * data) {
  if (queue_isFull(queue)) return;
  queue->data[queue->tail] = data;
  queue->tail = queue_next(queue->tail, queue->size);
}

char * queue_remove(QUEUE * queue) {
  char * data;
  if (queue_isEmpty(queue)) return NULL;
  data = queue->data[queue->head];
  queue->head = queue_next(queue->head, queue->size);
  return data;
}

void queue_print(QUEUE * queue) {
  for(int tempHead = queue->head; tempHead != queue->tail;
    tempHead = queue_next(tempHead, queue->size)
  ) {
    printf("%s ", queue->data[tempHead]);
  }
  printf("\n");
}

void queue_reset(QUEUE * queue) {
  queue->head = 0;
  queue->tail = 0;
}

void queue_init(QUEUE * queue) {
  queue_reset(queue);
  queue->data = (char **) malloc(sizeof(char *) * queue->size);
}

int main() {
  const int SIZE = 10;
  QUEUE queue;
  queue.size = SIZE;
  queue_init(&queue);
  char isRunning = 1;
  while (isRunning) {
    int choice;
    char * data;
    printf("\n1. ����\n2. ������\n3. ���\n4. ���� ����\n5. ��\n�Է�: ");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
      case 1:
        if (queue_isFull(&queue)) {
          printf("ť�� �� á���ϴ�\n");
          break;
        }
        printf("�����͸� �Է����ּ���: ");
        data = (char *) malloc(256);
        gets(data);
        queue_add(&queue, data);
        break;
      case 2:
        if (queue_isEmpty(&queue)) {
          printf("ť�� ������ϴ�\n");
          break;
        }
        data = queue_remove(&queue);
        printf("���� ������: %s\n", data);
        free(data);
        break;
      case 3:
        queue_print(&queue);
        break;
      case 4:
        // This doesn't free the queue, but whatever.
        queue_reset(&queue);
        break;
      case 5:
        isRunning = 0;
        break;
    }
  }
}
