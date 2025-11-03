#include <gtest/gtest.h>
#include "../linear_list/linear_list.h"

//TEST(TestLibLib, can_iterate) {
//	List<int> list;
//
//	for (int i = 0; i < 10; i++) {
//		list.push_back(i + 1);
//	}
//
//	int expected_val = 1;
//	for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
//		EXPECT_EQ(*it, expected_val);
//		expected_val++;
//	}
//
//	int expected_val = 1;
//	for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
//		*it = expected_val;
//		expected_val++;
//	}
//
//	int expected_val = 1;
//	for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
//		EXPECT_EQ(*it, expected_val);
//		expected_val++;
//	}
//
//	List<int> list;
//	for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
//		*it = 0;
//	}
//}

TEST(TestLibLib, can_iterate) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    // Проверка прохода по всем элементам
    auto iter = list.begin();
    auto end = list.end();

    EXPECT_TRUE(iter.operator!=(end)); //методы из итератора подключить к листу, но как?
    EXPECT_EQ(iter.value(), 10);

    iter.operator++();
    EXPECT_TRUE(iter.operator!=(end));
    EXPECT_EQ(iter.value(), 20);

    iter.operator++();
    EXPECT_TRUE(iter.operator!=(end));
    EXPECT_EQ(iter.value(), 30);

    iter.operator++();
    EXPECT_FALSE(iter.operator!=(end));

    // Подсчет суммы через итератор
    int sum = 0;
    auto it = list.begin();
    while (it.operator!=(list.end())) {
        sum += it.value();
        it.operator++();
    }
    EXPECT_EQ(sum, 60);
}

TEST(TestLibLib, can_push_elements) {
    List<int> list;

    // Проверка пустого списка
    EXPECT_TRUE(list.is_empty());
    EXPECT_EQ(list.size(), 0);

    // Добавление в начало
    list.push_front(2);
    EXPECT_FALSE(list.is_empty());
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 2);
    EXPECT_EQ(list.back(), 2);

    // Добавление в конец
    list.push_back(3);
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), 2);
    EXPECT_EQ(list.back(), 3);

    // Еще одно добавление в начало
    list.push_front(1);
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.back(), 3);
}

TEST(TestLibLib, can_pop_elements) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.size(), 3);

    // Удаление из начала
    list.pop_front();
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), 2);
    EXPECT_EQ(list.back(), 3);

    // Удаление из конца
    list.pop_back();
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 2);
    EXPECT_EQ(list.back(), 2);

    // Последнее удаление
    list.pop_front();
    EXPECT_TRUE(list.is_empty());
    EXPECT_EQ(list.size(), 0);
}

//TEST(TestLibLib, can_find_elements) {
//    List<int> list;
//    list.push_back(1);
//    list.push_back(2);
//    list.push_back(3);
//    list.push_back(4);

    //// Поиск существующего элемента
    //Node<int>* found = list.find(3);
    //EXPECT_NE(found, nullptr);
    //EXPECT_EQ(found->value, 3);

    //// Удаление найденного элемента
    //list.pop_node(found);
    //EXPECT_EQ(list.size(), 3);

    //// Проверка оставшихся элементов
    //auto iter = list.begin();
    //EXPECT_EQ(iter.get_value(), 1);
    //iter.pre_increment();
    //EXPECT_EQ(iter.get_value(), 2);
    //iter.pre_increment();
    //EXPECT_EQ(iter.get_value(), 4);

    //// Поиск несуществующего элемента
    //found = list.find(5);
    //EXPECT_EQ(found, nullptr);
//}

TEST(TestLibLib, can_clear_elements) {
    List<int> list;

    // Заполняем список
    for (int i = 0; i < 5; i++) {
        list.push_back(i);
    }

    EXPECT_EQ(list.size(), 5);
    EXPECT_FALSE(list.is_empty());

    // Очищаем список
    list.clear();

    EXPECT_TRUE(list.is_empty());
    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.get_head(), nullptr);
    EXPECT_EQ(list.get_tail(), nullptr);

    // Проверяем, что можно снова добавлять после очистки
    list.push_back(100);
    EXPECT_FALSE(list.is_empty());
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 100);
    EXPECT_EQ(list.back(), 100);
}
