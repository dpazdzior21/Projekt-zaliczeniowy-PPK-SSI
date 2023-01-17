/** @file */
#ifndef FILES_H
#define FILES_H
#include "structs.h"
#include "pathfinding.h"

/** Funkcja pobiera parametry uruchamiania programu i sprawdza ich poprawno��.
@param argc liczba parametr�w uruchamiania programu
@param argv tablica wska�nik�w na parametry uruchomienia programu
@param roads_path odczytana przez funkcj� nazwa pliku wej�ciowego z drogami
@param target_path odczytana przez funkcj� nazwa pliku wej�ciowego z trasami do wyznaczenia
@param output_path odczytana przez funkcj� nazwa pliku wynikowego z wyznaczonymi trasami
@return true, je�eli wszystkie parametry s� poprawne
*/
bool read_args(int argc, char* argv[], std::string& roads_path, std::string& target_path, std::string& output_path);

/** Funkcja zapisuje wyniki wyszukiwania tras.
@param output_path sciezka do pliku wyj�ciowego
@param result tekst z wynikami wyszukiwania wszystkich �cie�ek
@return true, je�eli uda�o zapisa� wynik
*/
bool save_result(std::string& output_path, std::string& result);

/** Funkcja odczytuje pliki z miastami i trasami, a nast�pnie dodaj je do vector�w.
@param roads_path �cie�ka do pliku z drogami
@param target_path �cie�ka do pliku z trasami do wyznaczenia
@param cities pusty vector z wszystkimi miastami
@param paths pusty vector ze �cie�kami do wyznaczenia
@return true, je�eli uda�o si� odczyta� pliki i doda� wszystkie miasta i trasy
*/
bool read_files(std::string& roads_path, std::string& target_path, std::vector<City*>* cities, std::vector<Path*>* paths);

/** Funkcja czy�ci pami�� vector�w.
@param cities vector z wszystkimi miastami
@param paths vector ze �ciezkami do wyznaczenia
*/
void clean_memory(std::vector<City*>* cities, std::vector<Path*>* paths);

#endif
