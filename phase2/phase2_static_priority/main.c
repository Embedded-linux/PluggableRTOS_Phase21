#include "kernel.h"
#include "scheduler_static_priority.h"

void task1() {
    while (1) {
        kernel_print("Task 1 Running\n");
        delay(100000);
    }
}

void task2() {
    while (1) {
        kernel_print("Task 2 Running\n");
        delay(100000);
    }
}

int main() {
    kernel_init();
    scheduler_set(static_priority_scheduler());

    kernel_add_task(task1, 1); // lower priority
    kernel_add_task(task2, 2); // higher priority

    kernel_start();
    return 0;
}
