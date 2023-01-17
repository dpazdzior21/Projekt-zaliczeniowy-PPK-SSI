/** @file */
#ifndef STRUCTS_H
#define STRUCTS_H
#include <vector>
#include <string>

struct City;

/** Struktura reprezentuj¹ca jednokierunkowe po³¹czenie pomiêdzy dwoma miastami. */
struct Road
{
    City* from; ///< miasto pocz¹tkowe
    City* to; ///< miasto koñcowe
    int length; ///< d³ugoœæ drogi
};

/** Struktura reprezentuj¹ca miasto. */
struct City
{
    std::string name; ///< nazwa miasta
    std::vector<Road*> roads; ///< drogi wychodz¹ce z miasta
    Road* previous = nullptr; ///< poprzednie miasto (u¿ywane podczas wyszukiwania trasy)
    int total_length = INT_MAX; ///< odleg³oœæ od miasta pocz¹tkowego (u¿ywane podczas wyszukiwania trasy)
};

/** Struktura reprezentuj¹ca trasê do wyznaczenia. */
struct Path
{
    City* from; ///< pocz¹tek wyszukiwanej trasy
    City* to; ///< koniec wyszukiwanej trasy
    std::vector<Road*>* roads; ///< kolejne drogi od miasta pocz¹tkowego, prowadz¹ce do miasta koñcowego
};

#endif