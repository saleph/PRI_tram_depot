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

#### Modyfikacja danych
##### Dodawanie nowego rekordu
Dodanie nowego rekordu następuje poprzez znalezienie piewszej struktury w tablicy, której flaga *visible* jest równa 0, a następnie zedytowaniu tej struktury poprzez przypisanie jej nowych danych. Na starcie sprawdzana jest aktualna liczba elementów (przechowywana w zmiennej globalnej `trams_array_size`) - jeśli jej wartość jest większa lub równa maksymalnemu rozmiar tablicy, to zwraca komunikat o niepowodzeniu.

##### Edytowanie rekordu
Edycja rekordu odbywa się poprzez wskazanie numeru rekordu, który ma zostać poddany edycji, a następnie funkcja pyta użytkownika, które pole struktury chce zmienić. Po podaniu nowej, prawidłowej wartości struktura zostaje natychmiastowo zaktualizowana. Jeśli na początku rozmiar tablicy struktur był równy 0, funkcja zwróci komunikat o błędzie.

##### Usuwanie rekordu
Usuwanie rekordu odbywa się poprzez wskazanie indeksu rekordu do usunięcia. Następnie flaga wskazanego rekordu zostaje zmieniona na 0, a w pozostałych elementach, które znajdowały się za usuwanym rekordem, zostają zdekrementowane ich numery rekordów. Zaś sam usuwany rekord zostaje wyrzucony za ostatni "widoczny" element tablicy. Jeśli na początku rozmiar tablicy struktur był równy 0, funkcja zwróci komunikat o błędzie. Podobnie w przypadku podaniu niewłaściwego indeksu (większego od rozmiaru tablicy).

##### Wyświetlanie danych
w budowie
