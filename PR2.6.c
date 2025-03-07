#include <stdio.h>
#include <unistd.h>
static void *heap_start = NULL;
static void *last_allocation = NULL;
static size_t last_size = 0;

void *my_malloc(size_t size) {
    if (heap_start == NULL) {
        heap_start = sbrk(0);
    }

    void *ptr = sbrk(size);
    if (ptr == (void *)-1) {
        printf("Помилка: Не вдалося виділити пам’ять\n");
        return NULL;
    }

    last_allocation = ptr;
    last_size = size;
    return ptr;
}

void my_free(void *ptr) {
    if (ptr == last_allocation) {
        sbrk(-last_size);
        last_allocation = NULL;
        last_size = 0;
    } else {
        printf("Помилка: Неможливо звільнити пам'ять посередині heap\n");
    }
}

int main() {
    printf("Виділення пам’яті \n");
    int *arr = (int *)my_malloc(5 * sizeof(int));

    if (arr == NULL) {
        printf("Помилка виділення пам’яті\n");
        return 1;
    }

    arr[0] = 42;
    printf("Значення arr[0]: %d\n", arr[0]);
    printf("Звільнення пам’яті \n");
    my_free(arr);
    return 0;
}