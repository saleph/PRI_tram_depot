# Zadanie 2.01
Program zarządzający spisem tramwajów opuszczających zajezdnię.

## Warstwa algorytmiczna
Program operuje na tablicy 17 zmiennych typu `struct Tram`:

```c
typedef struct {
    int visible;              // flaga widoczności w tablicy
    int record_no;            // numer rekordu (numer wprowadzenia)
    int line_no;              // 4-cyfrowy numer linii
    char tram_type[16];       // typ tramwaju
    int side_no;              // numer boczny tramwaju
    char motorman_name[256];  // nazwisko i imię motorniczego
} Tram;
```

### Sortowanie
Sortowanie odbywa się poprzez utworzenie tymczasowej, statycznej tablicy typu `int` kolejnymi numerami indeksów (`tab[0]=0`, `tab[16]=16` etc.), a przy porównaniu odpowiednich pól pomiędzy dwiema strukturami, jako indeks tablicy `trams` jest używany element tablicy `indexes`, np. `trams[indexes[i]].line_no`. W przypadku, gdy elementy są w złej kolejności, to zamieniane są tylko elementy w tablicy `indexes`. Po zakończeniu sortowania i wyświetleniu danych przy pomocy tymczasowej tablicy zostaje usunięta, a dane w głównej tablicy nie zostały naruszone.

### Modyfikacja danych
#### Dodawanie nowego rekordu
Dodanie nowego rekordu następuje poprzez znalezienie piewszej struktury w tablicy, której flaga *visible* jest równa 0, a następnie zedytowaniu tej struktury poprzez przypisanie jej nowych danych. Na starcie sprawdzana jest aktualna liczba elementów (przechowywana w zmiennej globalnej `trams_array_size`) - jeśli jej wartość jest większa lub równa maksymalnemu rozmiar tablicy, to zwraca komunikat o niepowodzeniu.
#### Edytowanie rekordu
Edycja rekordu odbywa się poprzez wskazanie numeru rekordu, który ma zostać poddany edycji, a następnie funkcja pyta użytkownika, które pole struktury chce zmienić. Po podaniu nowej, prawidłowej wartości struktura zostaje natychmiastowo zaktualizowana. Jeśli na początku rozmiar tablicy struktur był równy 0, funkcja zwróci komunikat o błędzie.
#### Usuwanie rekordu
Usuwanie rekordu odbywa się poprzez wskazanie indeksu rekordu do usunięcia. Następnie flaga wskazanego rekordu zostaje zmieniona na 0, a w pozostałych elementach, które znajdowały się za usuwanym rekordem, zostają zdekrementowane ich numery rekordów. Zaś sam usuwany rekord zostaje wyrzucony za ostatni "widoczny" element tablicy. Jeśli na początku rozmiar tablicy struktur był równy 0, funkcja zwróci komunikat o błędzie. Podobnie w przypadku podaniu niewłaściwego indeksu (większego od rozmiaru tablicy).
### Wyświetlanie danych
Procedury wyświetlające zostały posegmentowane - istnieje tylko jedna procedura wyświetlająca nagłówki kolumn oraz jedna funkcja wyświetlająca informacje o zadanym tramwaju. Dzięki temu została zachowana spójność estetyczna.
#### W kolejności wprowadzenia
Rekordy zostają w po prostu wyświetlone w kolejności zgodnej z układem w tablicy `trams`.
#### Rosnąco według numerów linii, a w ramach tego rosnąco według numerów bocznych
W ramach zadanego sortowania następuje ułożenie elementów w odpowiedniej kolejności za pomocą tymczasowej tablicy typu `int`, a następnie w ramach tejże tablicy dane zostają wyświetlone. Porównanie jest dwupoziomowe i wykorzystuje standardowe porównanie dwóch liczb.
#### Alfabetycznie według typu tramwaju, a w ramach tego alfabetycznie według nazwiska i imienia motorniczego
W ramach zadanego sortowania następuje ułożenie elementów w odpowiedniej kolejności za pomocą tymczasowej tablicy typu `int`, a następnie w ramach tejże tablicy dane zostają wyświetlone. Zgodnie z poleceniem porównanie jest dwupoziomowe i wykorzystuje funkcję biblioteki *<string.h>* `strcmp(char*, char*)` 
### Testy
Program został uodporniony na nielogiczne wprowadzanie danych głównie dzięki operacjom na stringach. Poszczególne z nich zostaną przedstawione w dokumentacji funkcji i procedur. Dodatkowo, zważywszy na operowanie na buforach o skończonym rozmiarze, funkcje skanujące skanują stringa dokładnie do zadanej długości - np. jeśli użytkownik poda 25 znaków przy buforze 15 znakowym, to po prostu pozostałe 10 znaków zostanie odczytane przez następną funkcję `scanf`, które w większości przypadków zostaną odrzucone (jeśli następna funkcja skanująca czeka na liczbę), bądź też zostanie zedytowany typ tramwaju albo nazwisko motorniczego. Nie jest to wielkim problemem, bo te dane będzie można zedytować. Szczególnie, że takie działanie użytkownika jest jego całkowicie świadomą próbą "wykrzaczenia" programu.

Przypadki pustej tablicy (dla edycji i usuwania) zostają sprawdzone już na początku wywołania tych funkcji. Przy dodawaniu nowych rekordów także już przy starcie zostaje sprawdzone, czy przypadkiem tablica nie jest już pełna. Walidacja danych wejściowych wykorzystuje między innymi funkcje `isdigit()`, `isupper()`, `islower()` dzięki którym program jest w pełni odporny na niewłaściwe dane wejściowe.
