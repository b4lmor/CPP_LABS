//
// Created by afox on 9/10/23.
//

#ifndef LAB1_BITARRAY_H
#define LAB1_BITARRAY_H

#include <string>
#include <vector>
#include <cstdint>

#define CELL_SIZE 8

typedef struct bits_s {
    std::vector<std::byte> bit_vector;
    /*
     * in {1 ; 2 ; ... ; 8}
     * OR just {0} if BitArray is empty
     */
    uint8_t last_used_bit = 0;
} bits_t;

class BitArray {
private:
    bits_t bits;
    void set_bit(int pos, bool value);
public:
    BitArray();
    ~BitArray();

    //Конструирует массив, хранящий заданное количество бит.
    //Первые sizeof(long) бит можно инициализровать с помощью параметра value.
    explicit BitArray(int num_bits, unsigned long value = 0);
    BitArray(const BitArray & b);


    //Обменивает значения двух битовых массивов.
    void swap(BitArray & b);

    BitArray & operator=(const BitArray & b);


    //Изменяет размер массива. В случае расширения, новые элементы
    //инициализируются значением value.
    void resize(int num_bits, bool value = false);
    //Очищает массив.
    void clear();
    //Добавляет новый бит в конец массива. В случае необходимости
    //происходит перераспределение памяти.
    void push_back(bool bit);


    //Битовые операции над массивами.
    //Работают только на массивах одинакового размера.
    //Обоснование реакции на параметр неверного размера входит в задачу.
    BitArray & operator&=(const BitArray & b);
    BitArray & operator|=(const BitArray & b);
    BitArray & operator^=(const BitArray & b);

    //Битовый сдвиг с заполнением нулями.
    BitArray & operator<<=(int n);
    BitArray & operator>>=(int n);
    BitArray operator<<(int n) const;
    BitArray operator>>(int n) const;


    //Устанавливает бит с индексом n в значение val.
    BitArray & set(int n, bool val = true);
    //Заполняет массив истиной.
    BitArray & set();

    //Устанавливает бит с индексом n в значение false.
    BitArray & reset(int n);
    //Заполняет массив ложью.
    BitArray & reset();

    //true, если массив содержит истинный бит.
    bool any() const;
    //true, если все биты массива ложны.
    bool none() const;
    //Битовая инверсия
    BitArray operator~() const;
    //Подсчитывает количество единичных бит.
    int count() const;


    //Возвращает значение бита по индексу i.
    bool operator[](int i) const;

    int size() const;
    bool empty() const;

    //Возвращает строковое представление массива.
    std::string to_string() const;
};

bool operator==(const BitArray & a, const BitArray & b);
bool operator!=(const BitArray & a, const BitArray & b);

BitArray operator&(const BitArray & b1, const BitArray & b2);
BitArray operator|(const BitArray & b1, const BitArray & b2);
BitArray operator^(const BitArray & b1, const BitArray & b2);

#endif //LAB1_BITARRAY_H
