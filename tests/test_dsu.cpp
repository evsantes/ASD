#include <gtest/gtest.h>
#include "../lib_DSU/DSU.h"

// Тест 1: Проверка создания DSU
TEST(DSUTest, CreateDSU) {
    // Создаем DSU на 5 элементов
    DSU<int> dsu(5);

    // Тест не упал - значит DSU создался
    SUCCEED();  // Просто отмечаем успех
}

// Тест 2: Проверка, что каждый элемент - свой собственный родитель при создании
TEST(DSUTest, InitialState) {
    DSU<int> dsu(3);

    // Каждый элемент должен быть своим собственным родителем
    EXPECT_EQ(dsu.find(0), 0);  // Проверяем элемент 0
    EXPECT_EQ(dsu.find(1), 1);  // Проверяем элемент 1
    EXPECT_EQ(dsu.find(2), 2);  // Проверяем элемент 2
}

// Тест 3: Простейшее объединение
TEST(DSUTest, SimpleUnion) {
    DSU<int> dsu(5);

    // Объединяем элементы 1 и 2
    dsu.unite(1, 2);

    // Теперь они должны быть в одном множестве
    EXPECT_EQ(dsu.find(1), dsu.find(2));

    // Но элемент 0 должен быть в другом множестве
    EXPECT_NE(dsu.find(0), dsu.find(1));
}

// Тест 4: Объединение нескольких элементов
TEST(DSUTest, MultipleUnions) {
    DSU<int> dsu(6);

    // Объединяем: 0-1-2 и 3-4-5
    dsu.unite(0, 1);
    dsu.unite(1, 2);

    dsu.unite(3, 4);
    dsu.unite(4, 5);

    // Проверяем первую группу
    EXPECT_EQ(dsu.find(0), dsu.find(1));
    EXPECT_EQ(dsu.find(1), dsu.find(2));

    // Проверяем вторую группу
    EXPECT_EQ(dsu.find(3), dsu.find(4));
    EXPECT_EQ(dsu.find(4), dsu.find(5));

    // Группы должны быть разными
    EXPECT_NE(dsu.find(0), dsu.find(3));
}

// Тест 5: Проверка транзитивности
TEST(DSUTest, Transitivity) {
    DSU<int> dsu(4);

    // Если A соединен с B, и B соединен с C, то A соединен с C
    dsu.unite(0, 1);  // 0 <-> 1
    dsu.unite(1, 2);  // 1 <-> 2

    // Теперь 0 должен быть соединен с 2
    EXPECT_EQ(dsu.find(0), dsu.find(2));
}

// Тест 6: Проверка, что объединение с самим собой ничего не ломает
TEST(DSUTest, UnionWithSelf) {
    DSU<int> dsu(3);

    // Объединяем элемент с самим собой
    int parent_before = dsu.find(1);
    dsu.unite(1, 1);  // Объединяем 1 с 1
    int parent_after = dsu.find(1);

    // Родитель должен остаться тем же
    EXPECT_EQ(parent_before, parent_after);
}

// Тест 7: Проверка копирования DSU
TEST(DSUTest, CopyConstructor) {
    DSU<int> original(4);
    original.unite(0, 1);
    original.unite(2, 3);

    // Создаем копию
    DSU<int> copy(original);

    // Проверяем, что структура сохранилась
    EXPECT_EQ(copy.find(0), copy.find(1));
    EXPECT_EQ(copy.find(2), copy.find(3));
    EXPECT_NE(copy.find(0), copy.find(2));
}

// Тест 8: Цепочка объединений
TEST(DSUTest, ChainUnion) {
    DSU<int> dsu(10);

    // Создаем цепочку: 0-1-2-3-4
    for (int i = 0; i < 4; i++) {
        dsu.unite(i, i + 1);
    }

    // Все элементы от 0 до 4 должны быть в одном множестве
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            EXPECT_EQ(dsu.find(i), dsu.find(j));
        }
    }

    // Элемент 5 должен быть в другом множестве
    EXPECT_NE(dsu.find(0), dsu.find(5));
}

// Тест 9: Обращение к одному элементу много раз
TEST(DSUTest, MultipleFinds) {
    DSU<int> dsu(5);

    // Много раз ищем один и тот же элемент
    int parent1 = dsu.find(3);
    int parent2 = dsu.find(3);
    int parent3 = dsu.find(3);

    // Все результаты должны быть одинаковыми
    EXPECT_EQ(parent1, parent2);
    EXPECT_EQ(parent2, parent3);
}

// Тест 10: Простая проверка всех элементов
TEST(DSUTest, CheckAllElements) {
    const int SIZE = 8;
    DSU<int> dsu(SIZE);

    // Сначала все элементы разные
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            EXPECT_NE(dsu.find(i), dsu.find(j));
        }
    }

    // Объединяем все в одну группу
    for (int i = 1; i < SIZE; i++) {
        dsu.unite(0, i);
    }

    // Теперь все элементы в одной группе
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            EXPECT_EQ(dsu.find(i), dsu.find(j));
        }
    }
}
