/** @file */
#ifndef PATHFINDING_H
#define PATHFINDING_H
#include "structs.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

/** Struktura zawiera funkcjê operator() wykorzystywan¹ do sortowania miast wed³ug ich odleg³oœci od miasta startowego.*/
struct customComparator
{
    /**
    @param a pierwsze miasto
    @param b drugie miasto
    @return true, je¿eli pierwsze miasto jest bli¿ej miasta startowego.
    */
    bool operator() (const City* a, const City* b) const
    {
        return a->total_length < b->total_length;
    }
};

/** Funkcja zwraca miasto o podanej nazwie. Jezeli nie ma go w vectorze wejœciowym, tworzy je.
@param cities vector z wszystkimi miastami
@param name nazwa miasta wyszukiwanego
@return wskaŸnik na wyszukiwane miasto
*/
City* get_or_add(std::vector<City*>* cities, std::string name);

/** Funkcja dodaje kolejne drogi miêdzy miastami od miasta pocz¹tkowego do miasta koñcowego.
@param cities vector z wszystkimi miastami
@param path trasa dla której budowana jest œcie¿ka
*/
void build_path(std::vector<City*>* cities, Path* path);

/** Funkcja zwraca drogê z path w formie tekstu.
@param path trasa z drog¹
@return tekst zawieraj¹cy plan trasy
*/
std::string get_path(Path* path);

/** Funkcja ustawia parametr total_length dla kazdego miasta w vectorze na INT_MAX. Jest to wymagane za ka¿dym razem, gdy wyszukiwana jest nowa œcie¿ka.
@param cities vector z wszystkimi miastami
*/
void reset_total_lengths(std::vector<City*>* cities);

/** Funkcja wyszukuje drogê algorytmem Dijkstry.
@param path trasa która ma byæ wyznaczona
@return true, je¿eli uda³o siê znaleŸæ po³¹czenie, false je¿eli nie
*/
bool dijkstra(Path* path);

/** Funkcja wyszukuje wszystkie wymagane po³¹czenia pomiêdzy miastami.
@param cities vector z wszystkimi miastami
@param paths vector z trasami do wyznaczenia
@return tekst zawieraj¹cy rezultat wyszukiwania wszystkich tras
*/
std::string find_paths(std::vector<City*>* cities, std::vector<Path*>* paths);

#endif PATHFINDING_H