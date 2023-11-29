#include <stdio.h>
#include <stdbool.h>

#define ALGORITHM_DESIGN                0x1  // 0b00000001
#define COLLEGE_PHYSICS                 0x2  // 0b00000010
#define COLLEGE_ENGLISH                 0x4  // 0b00000100
#define COMPUTER_NETWORK                0x8  // 0b00001000
#define ELECTRONIC_TECHNOLOGY           0x10 // 0b00010000
#define COMPUTER_COMPOSITION            0x20 // 0b00100000
#define COMPUTER_OPERATING_SYSTEM       0x40 // 0b01000000
#define DATA_STRUCTURE_BUDGETING_METHOD 0x80 // 0b10000000

/* 选课 */
void SelectedCourse(unsigned char* student, const unsigned char course) {
    *student |= course;
}

/* 退课 */
void WithdrawalCourse(unsigned char* student, const unsigned char course) {
    *student &= ~course;
}

/* 查询 */
bool QueryCourse(unsigned char* student, const unsigned char course) {
    return *student & course;
}

/* 打印已选 */
void PrintSelectedCourse(unsigned char* student) {

}

int main() {
    unsigned char student = 0; // char 1 byte 8 bit

    SelectedCourse(&student, ALGORITHM_DESIGN);
    SelectedCourse(&student, COLLEGE_ENGLISH);
    SelectedCourse(&student, ELECTRONIC_TECHNOLOGY);

    WithdrawalCourse(&student, COLLEGE_ENGLISH);

    bool s_technology = QueryCourse(&student, ELECTRONIC_TECHNOLOGY);
    bool s_english = QueryCourse(&student, COLLEGE_ENGLISH);

    if (s_english) {
        printf("student selected english\n");
    }
    if (s_technology) {
        printf("student selected technology\n");
    }

    return 0;
}
