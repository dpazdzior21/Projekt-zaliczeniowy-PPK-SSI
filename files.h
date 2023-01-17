/** @file */
#ifndef FILES_H
#define FILES_H
#include "structs.h"
#include "pathfinding.h"

/** Funkcja pobiera parametry uruchamiania programu i sprawdza ich poprawnoœæ.
@param argc liczba parametrów uruchamiania programu
@param argv tablica wskaŸników na parametry uruchomienia programu
@param roads_path odczytana przez funkcjê nazwa pliku wejœciowego z drogami
@param target_path odczytana przez funkcjê nazwa pliku wejœciowego z trasami do wyznaczenia
@param output_path odczytana przez funkcjê nazwa pliku wynikowego z wyznaczonymi trasami
@return true, je¿eli wszystkie parametry s¹ poprawne
*/
bool read_args(int argc, char* argv[], std::string& roads_path, std::string& target_path, std::string& output_path);

/** Funkcja zapisuje wyniki wyszukiwania tras.
@param output_path sciezka do pliku wyjœciowego
@param result tekst z wynikami wyszukiwania wszystkich œcie¿ek
@return true, je¿eli uda³o zapisaæ wynik
*/
bool save_result(std::string& output_path, std::string& result);

/** Funkcja odczytuje pliki z miastami i trasami, a nastêpnie dodaj je do vectorów.
@param roads_path œcie¿ka do pliku z drogami
@param target_path œcie¿ka do pliku z trasami do wyznaczenia
@param cities pusty vector z wszystkimi miastami
@param paths pusty vector ze œcie¿kami do wyznaczenia
@return true, je¿eli uda³o siê odczytaæ pliki i dodaæ wszystkie miasta i trasy
*/
bool read_files(std::string& roads_path, std::string& target_path, std::vector<City*>* cities, std::vector<Path*>* paths);

/** Funkcja czyœci pamiêæ vectorów.
@param cities vector z wszystkimi miastami
@param paths vector ze œciezkami do wyznaczenia
*/
void clean_memory(std::vector<City*>* cities, std::vector<Path*>* paths);

#endif
